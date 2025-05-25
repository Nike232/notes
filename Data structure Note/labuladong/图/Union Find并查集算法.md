并查集算法是一种专门针对动态连通性的算法

### 动态连通性
连通性所具有的三个性质:1.自反性 2.对称性 3.**传递性**

### 基本思路
在数据结构中，我们知道了并查集的底层是森林，每一个二叉树就是一个连通分量，那么返回连通分量的个数就解决了，时间复杂度为O(1)

我们设定每一个节点有都有一个父节点（这样方便确定根节点，因为我们其实并不关心子节点是谁，而是关心父节点，因为根节点一致就能判断两个节点在同一颗树上，这样他们就是在同一个连通分量里面）

```cpp
class UF{
	int count;//记录连通分量
	vector<int>parent;
	public:
	UF(int n)
	{
		//一开始都互不连通
		this->count=n;
		parent=vertor<int>(n);
		for(int i=0;i<n;i++)
		{
			parent[i]=i;//父节点的指针都指向自己
		}
	}
	private:
	//返回某个节点x的根节点
	int find(int x)
	{
		//在这种存储方式中 根节点的特点是parent[x]=x
		while(parent[x]!=x)
		{
			x=parent[x];
		}
		return x;
	}
	public:
	//返回当前的连通分量的个数
	int count()
	{
		return count;
	}
	void union(int p,int q)
	{
		int rootp=find(p);
		int rootq=find(q);
		if(rootq==rootp)
		{
			return;//已经是同一颗树了
		}
		parent[rootp]=rootq;
		count--;
	}
	bool connected(int p,int q)
	{
		int rootp=find(p);
		int rootq=find(q);
		return rootq==rootp;
	}
};
```
上面就是最基本的思路，通过数组而不是链表来实现大大节约了空间。用索引来表示节点，用值来表示节点的父节点的索引。首先是找到根节点的函数，根节点的特点是`parent[x]=x`。然后是判断两个节点是否连通，只需要找到他们的根节点，只要根节点相同，也就是说在同一颗树上，那么就是连通的，合并也就是连接两颗树的根节点就可以了。

还是老问题，整个算法的复杂度取决于find函数，进而取决于树的高度。也就是我们要尽可能保证树的平衡

### 平衡性优化
树高的增加过程就是union的过程，我们当时是随便选择了一个然后进行了连接这样的话，就可能会导致树高增长过快。
![](https://pic1.imgdb.cn/item/682000c758cb8da5c8eb98ba.png)
就像这样

所以我们希望将小一些的树接到大一些树的下面，这样就可以更加平衡。解决方法就是额外使用一个size数组，记录每一课树所包含的节点的数量
```cpp
class UF
{
	private:
	int count;
	vector<int>parent;
	vector<int>size;
	public(int n)
	{
		this->count=n;
		this->parent.resize(n);
		this->size.resize(n);
		for(int i=0;i<n;i++)
		{
			parent[i]=i;
			size[i]=1;
		}
	}
};
```
比如说 `size[3] = 5` 表示，以节点 `3` 为根的那棵树，总共有 `5` 个节点。
```cpp
class UF {
private:
    // 为了节约篇幅，省略上文给出的代码部分...
    
public:
    void union_(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
            return;
        
        // 小树接到大树下面，较平衡
        if (size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        } else {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        _count--;
    }
};
```
这样树的高度大致在logN这个数量级，这样几个算法的时间复杂度都降低为了O(lonN)

### 路径压缩
**其实关键点在于我们并不在意树长什么样子，我们只在意一个节点的根节点，那我们能不能进一步压缩树高，使得树高始终为常数？**

主要是修改 `find` 函数逻辑，非常简单，但你可能会看到两种不同的写法

第一种写法：
```cpp
class UF {
    // 为了节约篇幅，省略上文给出的代码部分...

private:
    int find(int x) {
        while (parent[x] != x) {
            // 这行代码进行路径压缩
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
};
```
这段代码就是在寻找根节点的过程中顺便调整父节点，将自己的父节点调整为祖父节点，这虽然改变了数的结构但是我们只关心根节点是什么，所以没有影响。

第二种写法：
```cpp
class UF {
    // 为了节约篇幅，省略上文给出的代码部分...
    
    // 第二种路径压缩的 find 方法
    public:
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
};
```
这段代码**更推荐**，因为他直接将所有节点都拉在了根节点下面，平均时间复杂度为O(1)

总结一下我们优化算法的过程：

1、用 `parent` 数组记录每个节点的父节点，相当于指向父节点的指针，所以 `parent` 数组内实际存储着一个森林（若干棵多叉树）。

2、用 `size` 数组记录着每棵树的重量，目的是让 `union` 后树依然拥有平衡性，保证各个 API 时间复杂度为 O(logN)，而不会退化成链表影响操作效率。

3、在 `find` 函数中进行路径压缩，保证任意树的高度保持在常数，使得各个 API 时间复杂度为 O(1)。使用了路径压缩之后，可以不使用 `size` 数组的平衡优化。