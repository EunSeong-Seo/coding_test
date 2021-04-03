#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n,m,start;  //

vector< pair <int , int> > graph[10001];
int d[10001];


void dijkstra(int start){
	priority_queue <pair <int, int> > pq;  //우선순위 큐를 만들 고  
	
	pq.push({0,start}); //큐에 집어넣고  처음에 시작할 위치까지 가는것은 0이라고 세팅한다 
	d[start]=0 ;
	while(!pq.empty()){	// 큐가 빌때까지 계속 진행하는데  
		int dist = -pq.top().first; 	// dist는 가장 낮은 비용을 뽑는다 
		int now = pq.top().second;  	//now는 그것의 현재위 치  
		pq.pop();					//정보를 뽑았으면 pq에서도 뽑은다  
		
		if(d[now]<dist)continue;	//만약에 가장낮은비용이 최소거리d에 있는값보다 크면 이건뭐 볼필요 없으니 넘긴다  
		for(int i=0;i<graph[now].size();i++){	//그래프에서 해당 성분들을 조사해보자 
			int cost = dist +graph[now][i].second;	//비용은 여기까지 가는 비용 + 인접노드에서 가는 비용 으로 세팅
		 
			if (cost<d[graph[now][i].first]){ 	//만약에 b까지 가는거리가 d에 저장되어있는 것보다 cost가 더 작다면  
				d[graph[now][i].first]= cost; 	// 이값을 가장 작은값이라 지정하고  
				pq.push(make_pair(-cost,graph[now][i].first));	// pq에 pair로 만들어서 넣는데 이때 cost는 - 를 붙여야 내림차순이된다.  
			} 
		}
		
	}
}

int main(){
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		graph[a].push_back({b,c});
	}
	fill (d, d+10001,INF);
	dijkstra(start);
	
	for (int i=1;i<=n;i++){
		if(d[i]==INF)cout<<"inifitinity"<<'\n';
		else cout<<d[i];
	}
}
