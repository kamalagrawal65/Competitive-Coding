#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;
queue<int> q;
int indegree[100007];

int main()
    {
    int n, m, u, v, i, j, num = 0;    // num stores the number of visited nodes
    vector<int> topo;
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
    for(i = 1; i <= n; i ++)
        {
        if(! indegree[i])
            q.push(i);
    }
    while(! q.empty())
        {
        u = q.front();
        q.pop();
        topo.push_back(u);
        for(i = 0; i < graph[u].size(); i ++)
            {
            if(! (-- indegree[graph[u][i]]))
                q.push(graph[u][i]);
        }
        num ++;
    }
    if(num != n)
        cout << "There exists a cycle in the DAG.. \n";
    else
        {
        for(i = 0; i < n; i ++)
            cout << topo[i] << '\n';
    }
    return 0;
}
