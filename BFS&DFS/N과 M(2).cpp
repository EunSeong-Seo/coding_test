#include <iostream>

using namespace std;

int n,m;
int arr[10];


void NaM3(int k){
	if(k==m){
		for(int i=0;i<m;i++){
			cout<<arr[i]<<" ";
		}
		cout<<'\n';
		return;
	}
	
	if(k==0){
		for(int i=1;i<=n;i++){
			arr[k]=i;
			NaM3(k+1);
		}
	}
	else{
		int pre = arr[k-1];
		for(int i=1;i<=n;i++){
			if(arr[k]>=pre){
				arr[k]=i;
				NaM3(k+1);
			}
		}
	}
	
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	NaM3(0);
	
	
} 
