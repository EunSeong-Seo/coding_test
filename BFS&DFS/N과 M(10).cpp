#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int key[10004];
bool isused[10004];
int arr[10];


void nam(int k, int start){
	if(k==m){
		for(int i=0;i<m;i++) cout<<arr[i]<<" ";
		cout<<'\n';
		return ;
	}
	
	int prev_num = -1;
	int prev_arr =100010;
	
	for(int i=start;i<n;i++){
		if(isused[i]||prev_num == key[i])continue;
		isused[i]=1;
		arr[k]=key[i];
		prev_num = key[i];
		
		nam(k+1,i);
		isused[i]=0;
	}	
	
	
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>key[i];
	}
	sort(key, key+n);
	
	nam(0,0);
} 
