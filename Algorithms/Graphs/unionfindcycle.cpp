#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100];
int n,m,src,dest;
int parent[100];
int find(int i){
	if(parent[i]!=i)
		return find(parent[i]);
	return i;
}
int join(int a,int b){
	parent[a]=b;
}
bool iscyclic(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<graph[i].size();j++){
			int s=find(i);
			int d=find(graph[i][j]);
			if(s==d)
				return true;
			join(s,d);
		}
	}
	return false;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>src>>dest;
		graph[src].push_back(dest);
	}
	for(int i=1;i<=n;i++) parent[i]=i;
	cout<<iscyclic();
}
