#include <bits/stdc++.h>

using namespace std;

int n;


int main(){
	//ó���� ���� ���� ���ڸ� �̰� �״��� �ð����ؼ�  
	cin>>n;
	
	priority_queue <pair <int, pair < int , int > > > pq;
	
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		pq.push({y-x,{x,y}});
	}
	
}
