#include <bits/stdc++.h>

using namespace std;

int v,e;
int parent[100001];
vector <pair <int,pair < int, int> > > edges; // 모든 간선을 담을 리스트와 최종비용을 담을 변수
int result;

int findParent(int x){
	if(x==parent[x])return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b){
	a = findParent(a);
	b = findParent(b);
	if (a <b) parent[b]= a;
	else parent[a] =b;
}

int main(){
	
	cin >>v>>e;
	
	//initialize itself to parent
	
	for (int i =1; i<=v;i++){
		parent[i]=i;
	} 
	
	
	
	for (int i= 0; i<e; i++){
		int a,b,cost;
		cin>>a>>b>>cost; 			//this is diffennce with 서로소
		edges.push_back({cost, {a,b}});
		
		} 
		
		
	sort(edges.begin(),edges.end());

	
	for (int i=0;i< edges.size();i++){
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		
		if(findParent(a)!= findParent(b)){
			unionParent(a,b);
			result +=cost;
		}
		
	}
}
