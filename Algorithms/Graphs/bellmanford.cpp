//v-1 times as each edge can be at max connected to other v-1 edges. It is beacuse we can calculate the distance in any random order so we use v-1 times.

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long 
vector<pair<int,int> > graph[100004];
int n,m;
int start,ending;
bool visited[100005];
int dist[100005];
int parent[100005];
void dfs(int begin){
	visited[begin]=true;
	for(int i=0;i<graph[begin].size();i++){
		if(!visited[graph[begin][i].first]) 
			dfs(graph[begin][i].first);
	}
}
void bf(){
	for(int i=1;i<=n;i++){
		dist[i]=INT_MAX;
		parent[i]=-1;
	}
	dist[start]=0;
	for(int i=1;i<=n-1;i++){	//v-1  times loop
		for(int k=1;k<=n;k++){	//all edges
			for(int j=0;j<graph[k].size();j++){
				int s=k;
                int e=graph[k][j].first;
                double w=graph[k][j].second;
                if(dist[e]>dist[s]+w){
                    dist[e]=dist[s]+w;
                	parent[e]=s;
				}
			}
		}
	}	
}
int main(){
	int src,dest,weight;
	cin>>n>>m;	//n vertices and m edges
	for(int i=1;i<=m;i++){
		cin>>src>>dest>>weight;
		graph[src].pb(make_pair(dest,weight));
	}
	cin>>start>>ending;
	dfs(start);
	if(!visited[ending]){
		cout<<"-1"<<endl;
		return 0;
	}
	bf();
	for(int i=1;i<=n;i++){
		cout<<dist[i]<<" "<<parent[i]<<endl;
	}
}
