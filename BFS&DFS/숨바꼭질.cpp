#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n,k;
int map[100004];
int dist[100004];


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	queue<int> q;
	cin>>n>>k;
	fill(dist,dist+100004,-1);
	
	dist[n]=0;
	q.push(n);
	
	
	while(dist[k]==-1){
		int x = q.front();
		q.pop();
		
		for(int nxt :{x-1,x+1,2*x}){
			if(nxt<0 ||nxt>100000)continue;
			if(dist[nxt]!= -1)continue; // If i already visited here than i have to skip
			dist[nxt] = dist[x]+1;
			q.push(nxt);
		}
		
	}
	cout<<dist[k];
	
}
