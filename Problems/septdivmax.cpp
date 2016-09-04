#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool vis[1000004];
ll lpf[1000004];
ll siz=0;
ll N=1000004;
ll t,n,m,qt,qs,qe;
//sieve of erathosenes
void sieve(){
	lpf[1]=lpf[0]=1;
    for(int i=2;i*i<=N;i++){
        if(!vis[i]){
			lpf[i]=i;
            for(ll j=i*i;j<=N;j+=i){
            	vis[j]=true;
                if(!lpf[j])
                	lpf[j]=i;
            }
    	}
    }
}
//building
int arr[100005];
int tree[300020][2];
void build(int index,int le,int ri){
    if(le==ri){
        tree[index][0]=arr[le];
		tree[index][1]=lpf[arr[le]]>0?lpf[arr[le]]:1;
        return;
    }
    int mid=(le+ri)>>1;
    build(index*2+1,le,mid);              
    build(index*2+2,mid+1,ri);        
    tree[index][1]=max(tree[index*2+1][1],tree[index*2+2][1]);
    return;
}
//updating
void update(int index,int start,int end,int l,int r){
    if(start>end || start>r || end<l)
        return;
    if(start==end){
    	tree[index][0]=tree[index][0]/tree[index][1];
		tree[index][1]=lpf[tree[index][0]];
        return;
	}
	int mid=(start+end)>>1;
    update(index*2+1,start,mid,l,r);
    update(index*2+2,mid+1,end,l,r);
    tree[index][1]=max(tree[index*2+1][1],tree[index*2+2][1]);
	return;
}
//query
int query(int index,int le,int ri,int a,int b){
    if(le>=a && ri<=b)
        return tree[index][1];
    if(le>b || ri<a) return INT_MIN;
    int mid=(le+ri)>>1;
    return max(query(index*2+1,le,mid,a,b),query(index*2+2,mid+1,ri,a,b));  
}

int main(){
    sieve();
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++)
        	cin>>arr[i];
        build(0,0,n-1);
        
        while(m--){
        	cin>>qt>>qs>>qe;
        	qs--,qe--;
        	if(qt==0)
        		update(0,0,n-1,qs,qe);
			else
				cout<<query(0,0,n-1,qs,qe)<<" ";
		}
    }
}
