#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int V;
vector<pair<int, int> > adj[100005]; 	//source.. destination.. weight..
void shortestPath(int src){
    set<pair<int, int> > setds;
 	vector<int> dist(V, INF);
 	setds.insert(make_pair(0, src));
    dist[src] = 0;
 	while (!setds.empty()){
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());
 	    int u = tmp.second;
 		vector< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i){
            int v = (*i).first;
            int weight = (*i).second;
 			if (dist[v] > dist[u] + weight){
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));
 				dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v],v));
            }
        }
    }
 	/*printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);*/
}
 
int main(){
    int edge,s,d,w;
	cin>>V>>edge;
    for(int i=0;i<edge;i++){
    	cin>>s>>d>>w;
    	adj[s].push_back(make_pair(d, w));
    	adj[d].push_back(make_pair(s, w));
	}
	shortestPath(0);
}
