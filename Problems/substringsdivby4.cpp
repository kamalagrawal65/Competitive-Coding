#include <bits/stdc++.h>
using namespace std;
string s;
void solve(){
    long long ans=0;
    for(int i=0;i<s.length();i++){
        int d=int(s[i]-'0');
        if(d%4==0) ans++;
        if(i){
            int pd=int(s[i-1]-'0');
            if((pd*10+d)%4==0)
                ans+=i;
        }
    }
    cout<<ans<<endl;
}
 
int main(){
	int tc;
	cin>>tc;
	while(tc--){
		cin>>s;
		solve();
	}
    return 0;
}
