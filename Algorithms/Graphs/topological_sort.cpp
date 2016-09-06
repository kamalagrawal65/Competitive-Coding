#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;
bool vis[100007];
stack<int> st;

void toposort(int v)
{
	vis[v] = 1;
	for(int i = 0; i < graph[v].size(); i ++)
	{
		if(! vis[graph[v][i]])
		    toposort(graph[v][i]);
	}
	st.push(v);
}

int main()
{
	int i, n, m, u, v;
	cin >> n >> m;
	graph.resize(n + 1);
	for(i = 1; i <= m; i ++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
	}
	for(i = 1; i <= n; i ++)    // all the nodes are checked because a DAG can be disconnected..
	{
		if(! vis[i])
		    toposort(i);
	}
	while(! st.empty())
	{
		cout << st.top() << ' ';
		st.pop();
	}
	return 0;
}
