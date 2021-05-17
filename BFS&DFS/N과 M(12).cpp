#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int arr[10];
int key[10004];
int isused[10004];


void nam(int k, int start){
	if(k==m){
		for(int i =0;i<m;i++){
			cout<<arr[i]<<" ";
		}
		cout<<'\n';
		return ;
	}
	int pre_key = -1;
	for(int i=start;i<n;i++){
		if(pre_key==key[i]) continue;
		arr[k]=key[i];
		pre_key= key[i];
		nam(k+1,i);
	}
}


int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>key[i];
	}
	sort(key, key+n);
	nam(0,0);
}
 
