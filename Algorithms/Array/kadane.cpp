#include<bits/stdc++.h>
using namespace std;
int kadane(int arr[],int n){
	int maxtillnow=0;
	int result=INT_MIN;
	for(int i=0;i<n;i++){
		maxtillnow+=arr[i];
		if(result<maxtillnow)	result=maxtillnow;
		if(maxtillnow<0) maxtillnow=0;
	}
	return result;
}
int main(){
	int tc,n,arr[105];
	cin>>tc;
	while(tc--){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cout<<kadane(arr,n)<<endl;
	}
}
