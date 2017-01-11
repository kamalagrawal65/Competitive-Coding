/* It visits each edge exactly once and starts and ends at same vertex */
/* Eulerian path is if it does not start and end at same vertex */

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
vi edges[100005];
map<pair<int,int>, bool> visited_edge,results;
int inedge[100004],outedge[100004];
vector<pair<int,int> > input,output;
int visited[100005];
int dfs(int s){
	visited[s]=1;
	for(int i=0;i<edges[s].size();i++){
		if(!visited[edges[s][i]])
			dfs(edges[s][i]);
	}
}
/* eulerian cycle */
void findcycle(int u,stack<int>& stk){
	stk.push(u);
	for(int i=0;i<edges[u].size();i++){
		if(!visited_edge[make_pair(u,edges[u][i])]){
			visited_edge[make_pair(u,edges[u][i])]=visited_edge[make_pair(edges[u][i],u)]=true;
			findcycle(edges[u][i],stk);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,e,s,d;
	cin>>n>>e;	
	for(int i=0;i<e;i++){
		cin>>s>>d;
		input.push_back(make_pair(s,d));
		outedge[s]++;
		inedge[d]++;
		edges[s].push_back(d);
		edges[d].push_back(s);
	}
	dfs(1);
	bool result=true;
	for(int i=1;i<=n;i++){
		if(!visited[i] || (inedge[i]+outedge[i])%2){
			result=false;
			break;
		}
	}
	stack<int> stk;
	if(!result)
		cout<<"NO"<<endl;
	else{
		findcycle(1,stk);
		int current=stk.top();
		if(current!=1)
			result=false;
		if(!result)
			cout<<"NO"<<endl;
		else{
			stk.pop();
			while(!stk.empty()){
				int next=stk.top();
				cout<<current<<"->"<<next<<endl;
				current=next;
				stk.pop();
			}
		}
	}
}
