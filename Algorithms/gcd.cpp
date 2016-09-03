#include<iostream>
using namespace std;
int gcd(int a,int b){
	int c;
	while((c=(a%b))!=0){
		a=b;
		b=c;
	}
	return b;
}
int main(){
	cout<<gcd(14,12);
}
