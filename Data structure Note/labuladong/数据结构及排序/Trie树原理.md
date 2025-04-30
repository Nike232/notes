Trie树（又叫字典树、线段树）

首先我们先来梳理一下已经接触过的map/set：
* 标准的哈希表是借助一个哈希函数把键值对存在一个table数组中的，有两个解决哈希冲突的方法。哈希表的特点是快，基本的增删查改的操作都是O(1)，哈希集合是对哈希表的简单封装
* 哈希链表是对哈希表的加强，用来解决哈希表的存储无序的问题，为了能够按插入顺序得到所有节点的值，我们将所有节点用双链表进行连接，这样就使得既继承了哈希表的快，又能按插入顺序访问
* 哈希数组是为了解决在O(1)的时间内返回一个随机键的问题，arrayhashset是对arrayhashmap的简单封装，继承了哈希表的快，同时提供了一个额外的randomkey函数
* Treemap映射，底层是一颗二叉搜索树（编程语言标准库一般使用经过改良的自平衡红黑树）,基本增删查改的复杂度是O(logn),它的特点是动态维护键值对的大小关系，Treeset是对Treemap的简单封装

同样Trieset也是对Triemap的简单封装，因而聚焦于Triemap的实现即可

### Trie树的主要应用场景
**Tire树是针对字符串有特殊优化的数据结构**,Trie树针对字符串的处理有一系列的优势
#### 节约存储空间
比如存储下面的几个键值对
```
map["apple"]=1;
map["appl"]=2;
map["app"]=3;
```
如果用哈希表来实现，根据哈希表的原理，它会真的创建"apple"、"appl"、"app"这几个字符串，也就是占用了12个字符的存储空间
但其实，这三个字符串具有公共前缀"app"也就是“app”被重复存储了三次，"l"被重复存储了两次

但是如果用TrieMap来存储
由于Trie树底层并不会重复存储公共前缀，所以只需要"apple"五个字符的内存来存储

如果键非常多非常长，那么Trie树会节约大量的空间，在现实当中也有这样的需求，比如身份证号

#### 方便处理前缀操作
举个例子
```java
// Trie 树的键类型固定为 String 类型，值类型可以是泛型
TrieMap<Integer> map = new TrieMap<>();
map.put("that", 1);
map.put("the", 2);
map.put("them", 3);
map.put("apple", 4);

// "the" 是 "themxyz" 的最短前缀
System.out.println(map.shortestPrefixOf("themxyz")); // "the"

// "them" 是 "themxyz" 的最长前缀
System.out.println(map.longestPrefixOf("themxyz")); // "them"

// "tha" 是 "that" 的前缀
System.out.println(map.hasKeyWithPrefix("tha")); // true

// 没有以 "thz" 为前缀的键
System.out.println(map.hasKeyWithPrefix("thz")); // false

// "that", "the", "them" 都是 "th" 的前缀
System.out.println(map.keysWithPrefix("th")); // ["that", "the", "them"]
```
除了`keysWithPrefix`方法的复杂度取决于返回结果的长度，其他前缀操作的复杂度都是O(L),其中L是前缀字符串的长度，这几个方法用HashMap或者TreeMap能做到吗？应该只能强行遍历所有键，然后一个一个比较字符串前缀，时间复杂度非常高
(这个keysWithPrefix是不是非常适合做自动补全功能?)

#### 可以使用通配符
```java
// Trie 树的键类型固定为 String 类型，值类型可以是泛型
// 支持通配符匹配，"." 可以匹配任意一个字符
TrieMap<Integer> map = new TrieMap<>();

map.put("that", 1);
map.put("the", 2);
map.put("team", 3);
map.put("zip", 4);

// 匹配 "t.a." 的键有 "team", "that"
System.out.println(map.keysWithPattern("t.a.")); // ["team", "that"]

// 匹配 ".ip" 的键有 "zip"
System.out.println(map.hasKeyWithPattern(".ip")); // true

// 没有匹配 "z.o" 的键
System.out.println(map.hasKeyWithPattern("z.o")); // false
```
通配符匹配，是不是可以做搜索引擎的关键词匹配呢？这个功能用HashMap或者TreeMap肯定是做不到的
#### 可以按字典序遍历键
```
// Trie 树的键类型固定为 String 类型，值类型可以是泛型
TrieMap<Integer> map = new TrieMap<>();

map.put("that", 1);
map.put("the", 2);
map.put("them", 3);
map.put("zip", 4);
map.put("apple", 5);

// 按照字典序遍历键
System.out.println(map.keys()); // ["apple", "that", "the", "them", "zip"]
```
这个功能TreeMap能做到（大小比较的时候不就是按字典序嘛）但是HashMap肯定是做不到的

### Trie树的基本结构
**Trie树本质上就是一颗从二叉树衍生出来的多叉树**
```cpp
template<typename V>
struct TrieNode{
	V val =NULL;
	TrieNode<V>* children[256]={NULL};
};
```
这个val字段存储键对应的值，children数组存储指向子节点的指针。
乍一看和多叉树节点的定义很像
**但是和多叉树节点又不同，TrieNode中的children数组的索引是有意义的，代表键中的一个字符**
比如说children[97]非空，说明这里存储了一个字符'a'，因为'a'的ASCII码为97
当然这个也可以根据实际修改，比如只有'a'-'z'，就设置为26,我们这里使用的是ASCII形式
以下是Trie树的结构
![](https://pic1.imgdb.cn/item/6810f1a258cb8da5c8d4a5c3.png)
![](https://pic1.imgdb.cn/item/6810f29158cb8da5c8d4a611.png)

需要特别注意的是，TrieNode节点本身只存储val，并没有存储字符，字符是通过子节点在父节点children数组中的索引确定的
**形象理解就是，Trie 树用「树枝」存储字符串（键），用「节点」存储字符串（键）对应的数据（值）。**

### API
```cpp
template <typename V>
class TrieMap {
public:
    // 在 Map 中添加 key
    void put(string key, V val);

    // 删除键 key 以及对应的值
    void remove(string key);

    // 搜索 key 对应的值，不存在则返回 null
    // get("the") -> 4
    // get("tha") -> null
    V get(string key);

    // 判断 key 是否存在在 Map 中
    // containsKey("tea") -> false
    // containsKey("team") -> true
    bool containsKey(string key);

    // 在 Map 的所有键中搜索 query 的最短前缀
    // shortestPrefixOf("themxyz") -> "the"
    string shortestPrefixOf(string query);

    // 在 Map 的所有键中搜索 query 的最长前缀
    // longestPrefixOf("themxyz") -> "them"
    string longestPrefixOf(string query);

    // 搜索所有前缀为 prefix 的键
    // keysWithPrefix("th") -> ["that", "the", "them"]
    vector<string> keysWithPrefix(string prefix);

    // 判断是和否存在前缀为 prefix 的键
    // hasKeyWithPrefix("tha") -> true
    // hasKeyWithPrefix("apple") -> false
    bool hasKeyWithPrefix(string prefix);

    // 通配符 . 匹配任意字符，搜索所有匹配的键
    // keysWithPattern("t.a.") -> ["team", "that"]
    vector<string> keysWithPattern(string pattern);

    // 通配符 . 匹配任意字符，判断是否存在匹配的键
    // hasKeyWithPattern(".ip") -> true
    // hasKeyWithPattern(".i") -> false
    bool hasKeyWithPattern(string pattern);

    // 返回 Map 中键值对的数量
    int size();
};
```
