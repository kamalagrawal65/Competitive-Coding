#include<iostream>
using namespace std;
void swap(char &a,char &b){
	char c=a;
	a=b;
	b=c;
}
void permut(string str,int l,int h){
	if(l==h)
		cout<<str<<endl;
	for(int i=l;i<=h;i++){
		swap(str[l],str[i]);
		permut(str,l+1,h);
		swap(str[l],str[i]);
	}
}
int main(){
	string str="ABC";
	permut(str,0,2);
}
