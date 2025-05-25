图虽然可以说是比较特殊的多叉树（这也是遍历还是这两种经典遍历的原因）,但是图的遍历当中要格外注意的是，图的遍历可能会出现环，**因而我们要标记已经遍历过的节点，避免出现死循环**

### DFS遍历
```cpp
void traverse(const Graph&graph,int s,vector<bool>&visited)
{
	if(s<0||s>=graph.size()){
		return;
	}
	if(visited[s]){
		return;
	}
	//前序位置
	visited[s]=true;
	cout<<"Visit"<<s<<endl;
	for(cosnt Graph::Edge& e :graph.neighbors(s))
	{
		traverse(graph,e.to,visited);
	}
	//后序位置
}
```
#### 遍历所有路径
对于树结构而言，遍历所有路径和遍历所有节点没什么区别，但是对于图结构而言，这二者是不同的。

因为对于树而言，方向是单一的，只能从父节点指向子节点，但是对于图而言，方向是多样的，也就是从x到y的路径并不是唯一的，因而在前面要添加位置，在后序位置要撤销位置，这跟走迷宫是一样的

```cpp
vector<bool>onPath(graph.size());
list<int>path;
void traverse(Graph&graph,int src,int dest)
{
	if(src<0||src>=graph.size())
	{
		return;
	}
	if(onPath[src])//只要是图的遍历都要做标记防止死循环
	{
		return;
	}
	//前序位置
	onPath[src]=true;
	path.push_back(src);
	if(src==dest){
		cour<<"find path";
		for(int node:path)
		{
			cout<<node<<" ";
		}
		cout<<endl;
	}
	//遍历
	for(const Edge& e:graph.neighbors(src))
	{
		traverse(graph,e.to,dest);
	}
	//后序位置 撤销选择]
	path.pop_back();
	onPath[src]=false;
}
```
由于onPath会撤销选择，就导致可能会重复遍历某些节点或边，增加了复杂度

由于在实际问题当中，我们可能并不需要真的遍历得到所有的路径，那其实我们可以用visited数组来提前排除一下不可能的路径，也就是提前剪枝，这样可以降低一些时间复杂度

还有一个问题就是，其实我们的visted或者是onPath数组都是为了防止出现环，那么如果题目中明确告诉了没有环，那其实也就不需要使用这两个数组了

### BFS遍历
图的BFS遍历其实也就是多叉树的层序遍历，只不过是加了一个visited数组来防止重复遍历节点

BFS算法常常用来求**最短路径**，而DFS算法常常用来求**所有路径**

第一种写法:
```cpp
void bfs(const Graph&graph,int s)
{
	vector<bool>visited(graph.size(),false);
	queue<int>q;
	q.push(s);
	visited[s]=true;

	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		cout<<"visit"<<cur<<endl;
		for(const Edge&e:graph.neighbors(cur))
		{
			if(!visited[e.to])
			{
				q.push(e.to);
				visited[e.to]=true;
			}
		}
	}
}
```
可以看到这里没有使用for循环来一层一层的遍历，而是只有有没有访问的就直接加入了队列，从结果上来看，同样也是层序访问的。

这种写法的优点在于简单，但是没有内部分割，不知道哪个是哪层的

第二种写法(记录遍历的步数)
```cpp
void bfs(const Graph&graph,int s)
{
	vector<bool>visited(graph.size(),false);
	queue<int>q;
	q.push(s);
	visited[s]=true;
	int step=0;
	while(!q.empty())
	{
		int sz=q.size();
		for(int i=0;i<sz;i++)
		{
			int cur=q.front();
			q.pop();
			cout<<"visit"<<cur<<"at step"<<step<<endl;
			for(const Edge&e:graph.neighbors(cur))
			{
				if(!visited[e.to])
				{
					q.push(e.to);
					visited[e.to]=true;
				}
			}
		}
		step++;
	}
}
```
这个step变量可以帮助我们判断最短路径

第三种写法
```cpp
class State
{
	int node;
	int step;//从起点s到当前节点的遍历步数
	State(int node,int step):node(node),step(step){}
};

void traverse(const Graph&graph,int s)
{
	vector<bool>visited(graph.size(),false);
	queue<State>q;
	q.push(State(s,0));
	visited[s]=true;
	while(!q.empty())
	{
		State state=q.front();
		q.pop();
		int cur=state.node;
		int step=state.step;
		cout<<"visit"<<cur<<"with step"<<step<<endl;
		for(const Graph&e:graph.neighbors(cur))
		{
			if(!visited[e.to])
			{
				q.push(State(e.to,step+1));
				visited[e.to]=true;
			}
		}
	}
}
```