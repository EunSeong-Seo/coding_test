#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 1000000000

using namespace std;


bool c[MAX];
vector<int> ham;
int size =0;
int k;


int main(){
	
	cin>>k;
	priority_queue<int> pq;
	pq.push(1);
	c[1]=true;
	size++;
	
	while(size>=k+1){
		int j=pq.top();
		pq.pop();
		
		if(c[j]==true){
			if(c[2*j]!=true){
				c[2*j]=true;
				size++;
				pq.push(2*j);
				ham.push_back(2*j);
			}
			if(c[3*j]!=true){
				c[3*j]=true;
				size++;
				pq.push(3*j);
				ham.push_back(3*j);
			}
			if(c[5*j]!=true){
				c[5*j]=true;
				size++;
				pq.push(5*j);
				ham.push_back(5*j);
			}
			
		}
		
	}
	
	cout<<ham[k-1]<<endl;
	
	
}
