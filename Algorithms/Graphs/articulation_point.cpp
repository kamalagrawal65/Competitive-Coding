//Low represents the earliest of the time a vertex can be visited.. 
//Hence its parent's discovery time should be greater than its own low time.
//Because its says there is some other path if it happens so.
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define li long int
#define vi vector<int>
ll mod=1e9+7;
vi graph[1005];
bool visited[1005];
int disc[1005],low[1005],parent[1005],ap[1005];
int timer=1;
int n,m,src,dest;
void articulation(int u){
	int children=0;
 	visited[u]=true;
 	// for first visit dixcovert time and low is set to visited time
 	disc[u]=low[u]=timer++;
    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i];
		if(!visited[v]){
            children++;
            parent[v]=u;
            articulation(v);
            //parents low is changed...
            low[u]=min(low[u],low[v]);
            if(parent[u]==-1 && children>1)
               ap[u]=1;
            if(parent[u]!=-1 && low[v]>=disc[u])
               ap[u]=1;
        }
        else if(v!=parent[u])
            low[u]=min(low[u],disc[v]);		//set back edge's disc value
    }
}
int main(){
    cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>src>>dest;
		graph[src].push_back(dest);
		graph[dest].push_back(src);
	}
	memset(parent,-1,sizeof(parent));
	memset(visited,false,sizeof(visited));
	memset(ap,0,sizeof(ap));
	timer=1;
	for(int i=0;i<n;i++)
        if(visited[i]==false)
            articulation(i);
    //result
 	for(int i=0;i<n;i++)
        if(ap[i]==1)
            cout<<i<<" ";
}
