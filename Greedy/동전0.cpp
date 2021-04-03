#include <bits/stdc++.h>

using namespace std;

int n;


int main(){
	//처음에 가장 작은 숫자를 뽑고 그다음 시간비교해서  
	cin>>n;
	
	priority_queue <pair <int, pair < int , int > > > pq;
	
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		pq.push({y-x,{x,y}});
	}
	
}
