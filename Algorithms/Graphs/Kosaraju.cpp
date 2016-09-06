#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define li long int
#define vi vector<int>
ll mod=1e9+7;
vi graph[1005];
vi rev_graph[1005];
int visited[1005];
int tc,n,src,dest,m;
bool allvisited(){
	for(int i=1;i<=n;i++)
		if(!visited[i])
			return false;
	return true;
}
void dfs1(int s){
	visited[s]=1;
	for(int i=0;i<graph[s].size();i++)
		if(!visited[graph[s][i]])
			dfs1(graph[s][i]);
}
void dfs2(int s){
	visited[s]=1;
	for(int i=0;i<rev_graph[s].size();i++)
		if(!visited[rev_graph[s][i]])
			dfs2(rev_graph[s][i]);
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>src>>dest;
		graph[src].push_back(dest);
		rev_graph[dest].push_back(src);
	}
	//straight graph
	memset(visited,0,sizeof(visited));
	dfs1(1);
	if(!allvisited()){
		cout<<"No"<<endl;
		return 0;
	}
	//reverse graph
	memset(visited,0,sizeof(visited));
	dfs2(1);
	if(!allvisited())
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
}
