#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
//power a^b
ll power(ll a,ll b){
	ll x=1,y=a;
    while(b>0){
        if(b&1)
            x=(x*y)%mod;
        y=(y*y)%mod;
        b=b>>1;
    }
    return x;
}
//inverse
ll inv(ll a,ll mod){
    return power(a,mod-2);
}
//ncr
ll ncr(int n,int k){
    ll ret=1;
    for(int i=1;i<=k;i++){			//coz remaining will be cancelled
    	ret=(ret*(n-i+1))%mod;		
        ret=(ret*inv(i,mod))%mod;		//cal denominator's inverse and multiply
    }
    return ret;
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<ncr(n,k)<<endl;
}
