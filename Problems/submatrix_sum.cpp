#include<bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	while(tc--){
		int mat[105][105]={0};
		int sum[105][105]={0};
		int m,n;
		cin>>m>>n;
		for(int i=0;i<n;i++)
			sum[0][i]=0;
		for(int i=0;i<m;i++)
			sum[i][0]=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				cin>>mat[i][j];
				sum[i][j]=mat[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			}
		}
		int a,b,q;
		cin>>q;
		while(q--){
			cin>>a>>b;
			int max=INT_MIN;
			for(int i=a;i<=m;i++){
				for(int j=b;j<=n;j++){
					int tmp_sum=sum[i][j]-sum[i-a][j]-sum[i][j-b]+sum[i-a][j-b];
					if(tmp_sum>max)
						max=tmp_sum;
				}
			}
			cout<<max<<' ';
		}
		cout<<endl;
	}
}
