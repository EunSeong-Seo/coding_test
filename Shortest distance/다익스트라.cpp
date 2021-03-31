# include <bist/stdc++.h>

using namespace std;


int n,m,start;
vector< pair <int, int> > graph[10001];

int d[10001];

void dijkstra(int start){
	priority_queue<pair<int, int> > pq;
	
	pq.push({0,start});
	d[start]=0;
	
	while(!pq.empty()){
		
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		
		if(d[now]<dist)continue;
		
		for(int i=0;i<graph[now].size();i++){
			int cost = dist + graph[now][i]
		}
		
		
	}
	
}
