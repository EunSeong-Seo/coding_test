#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n,m,start;  //

vector< pair <int , int> > graph[10001];
int d[10001];


void dijkstra(int start){
	priority_queue <pair <int, int> > pq;  //�켱���� ť�� ���� ��  
	
	pq.push({0,start}); //ť�� ����ְ�  ó���� ������ ��ġ���� ���°��� 0�̶�� �����Ѵ� 
	d[start]=0 ;
	while(!pq.empty()){	// ť�� �������� ��� �����ϴµ�  
		int dist = -pq.top().first; 	// dist�� ���� ���� ����� �̴´� 
		int now = pq.top().second;  	//now�� �װ��� ������ ġ  
		pq.pop();					//������ �̾����� pq������ ������  
		
		if(d[now]<dist)continue;	//���࿡ ���峷������� �ּҰŸ�d�� �ִ°����� ũ�� �̰ǹ� ���ʿ� ������ �ѱ��  
		for(int i=0;i<graph[now].size();i++){	//�׷������� �ش� ���е��� �����غ��� 
			int cost = dist +graph[now][i].second;	//����� ������� ���� ��� + ������忡�� ���� ��� ���� ����
		 
			if (cost<d[graph[now][i].first]){ 	//���࿡ b���� ���°Ÿ��� d�� ����Ǿ��ִ� �ͺ��� cost�� �� �۴ٸ�  
				d[graph[now][i].first]= cost; 	// �̰��� ���� �������̶� �����ϰ�  
				pq.push(make_pair(-cost,graph[now][i].first));	// pq�� pair�� ���� �ִµ� �̶� cost�� - �� �ٿ��� ���������̵ȴ�.  
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
