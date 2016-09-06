#include<bits/stdc++.h>
using namespace std;
const int MAX = 100001;
bool visit[MAX] = {0};
int intime[MAX];
int outtime[MAX];
int timer = 0;
void dfs(vector<int> graph[], int v){
    visit[v]=true;
    ++timer;
    intime[v]=timer;
    vector<int>::iterator it=graph[v].begin();
    while(it!=graph[v].end()){
        if(visit[*it]==false)
            dfs(graph,*it);
        it++;
    }
    ++timer;
    outtime[v]=timer;
}
bool query(int u,int v){
    return ((intime[u]<intime[v] && outtime[u]>outtime[v]) || (intime[v]<intime[u] && outtime[v]>outtime[u]));
}
int main(){
    int n = 9; // total number of nodes
    vector<int> graph[n+1];
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[3].push_back(6);
    graph[2].push_back(4);
    graph[2].push_back(5);
    graph[5].push_back(7);
    graph[5].push_back(8);
    graph[5].push_back(9);
    dfs(graph,1);
    query(1, 5)? cout << "Yes\n" : cout << "No\n";
    query(2, 9)? cout << "Yes\n" : cout << "No\n";
    query(2, 6)? cout << "Yes\n" : cout << "No\n";
}