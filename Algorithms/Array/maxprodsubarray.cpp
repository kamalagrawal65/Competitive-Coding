#include<bits/stdc++.h>
using namespace std;
int main(){
	int arr[]={-1,-2,-3};
	int n=sizeof(arr)/sizeof(arr[0]);
	int left_till=1;
	int left=INT_MIN;
	for(int i=0;i<n;i++){
		left_till=left_till*arr[i];
		if(left<left_till)
			left=left_till;
		if(left_till==0)
			left_till=1;
	}
	
	int right_till=1;
	int right=INT_MIN;
	for(int i=n-1;i>=0;i--){
		right_till=right_till*arr[i];
		if(right<right_till)
			right=right_till;
		if(right_till==0)
			right_till=1;
	}
	cout<<max(left,right);
}
