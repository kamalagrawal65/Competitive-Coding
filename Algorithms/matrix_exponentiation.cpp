#include<iostream>
using namespace std;
int n;
long long int mat[10][10];
long long int matst[10][10];
long long mod=1e9+7;
//y*y
void multiply_yy(){
	long long int mul[n][n];
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mul[i][j]=0;
            for(int k=0;k<n;k++)
                mul[i][j]=(mul[i][j]+(mat[i][k]*mat[k][j])%mod)%mod;
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            mat[i][j]=mul[i][j]%mod; 
}
//x*y
void multiply_xy(){
	long long int mul[n][n];
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mul[i][j]=0;
            for(int k=0;k<n;k++)
                mul[i][j]=(mul[i][j]+(matst[i][k]*mat[k][j])%mod)%mod;
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            matst[i][j]=mul[i][j]%mod;
}

void power(int n){
	while(n>0){
  		if(n%2){
  			multiply_xy();
  			n-=1;
		}
  		n/=2;
  		if(n>0)
  			multiply_yy();	
	}
}

int main(){
	long long int p;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>p;
			mat[i][j]=(p%mod);
			if(i==j) matst[i][j]=1;
			else matst[i][j]=0;
		}
	}
	int k;
	cin>>k;
	power(k);
	long long int sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			//cout<<matst[i][j]<<" ";
			sum=(sum+matst[i][j])%mod;
		}
	}
	cout<<sum<<endl;
}
