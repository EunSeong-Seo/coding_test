#include <bits/stdc++.h>

using namespace std;

int test, n,m;
int a[20][20]; 	// 최대값의 범위로 해도된다 어차피 지정할것이기 때문 
int dp[20][20];

int main(){
	cin>> test;
	
	for(int tc=0;tc<test;tc++){
		cin>>n>>m;
		
		for(int i =0;i<n;i++){
			for (int j=0;j<m;j++){
				int x;
				cin>>x;
				a[i][j]=x;
			}
		}
		
		for(int i=0; i<n;i++){
			for(int j=0;j<m;j++){
				dp[i][j]=a[i][j];
			}
		}
		
		for(int j=1;j<m;j++){
			for(int i =0;i<n;i++){
				int leftup, left, leftdown;
				if(i==0) leftup =0;
				else leftup = dp[i-1][j-1];
				if(i==m-1) leftdown=0;
				else leftdown= dp[i+1][j-1];
				left = dp[i][j-1];
				
				dp[i][j]= dp[i][j] +max(leftup, max(left, leftdown));
			}
		}
		
		int result =0;
		for(int i=0;i<n;i++){
			result= max(result,dp[i][m-1]);
		}
		cout<<result<<endl;
		
		
		
		
	}
	
} 
