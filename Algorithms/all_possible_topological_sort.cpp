#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;
bool vis[100007];
int indegree[100007];

void toposort(vector<int>& res, int n)
{
	bool f = 0;
	int i, j;
	for(i = 1; i <= n; i ++)
	{
		if(! indegree[i] && ! vis[i])
		{
			for(j = 0; j < graph[i].size(); j ++)
				indegree[graph[i][j]] --;
			res.push_back(i);
			vis[i] = 1;
			toposort(res, n);
			vis[i] = 0;
			res.erase(res.end() - 1);
			for(j = 0; j < graph[i].size(); j ++)
				indegree[graph[i][j]] ++;
			f = 1; 
		}
	}
	if(! f)
	{
		for(i = 0; i < res.size(); i ++)
		    cout << res[i] << ' ';
		cout << '\n';
	}
}

int main()
{
    int n, m, u, v, i, j;
    cin >> n >> m;
    graph.resize(n + 1);
    for(i = 1; i <= n; i ++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for(i = 1; i <= n; i ++)
    {
    	for(j = 0; j < graph[i].size(); j ++)
    		indegree[graph[i][j]] ++;
	}
	vector<int> res;
    cout << "All the possible topological orderings for the given DAG are as follows :\n";
    toposort(res, n);
    return 0;
}
