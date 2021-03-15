#include <bits/stdc++.h>
#include <vector>
#define INF 1e9 

using namespace std;

int n, m;
int graph[101][101];

int main(void){
	cin>>n >>m;
	
	// initialization 
	for (int i =0;i<101;i++){
		fill(graph[i], graph[i]+101 , INF);
		
	}
	for (int a =1; a<=n;a++){
		for(int b=1;b<=n; b++){
			if (a==b) graph[a][b]=0;
		}
	}
	
	
	
	for (int i =0; i<m; i++){
		int a,b;
		
		cin>>a>>b;
		graph[a][b]=1;
		graph[b][a]=1;
	}
	
	int x,k;
	cin>>x>>k;
	
	for (int k=1; k<=n;k++){
		for (int a=1; a<=n;a++){
			for (int b=1; b<=n; b++){
				graph[a][b]= min(graph[a][b], graph[a][k]+graph[k][b]);
			}
		}
	}
	
	int distance = graph[1][k] + graph [k][x];
	
	if (distance >= INF){
		cout<<"-1"<<endl;
	}
	else cout<< distance <<endl;
} 
