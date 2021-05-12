#include <iostream>

using namespace std;

int n,m;
int arr[10];

int last =0;
bool isused[10];
string s ="";

void NaM2(int k){
	if(k==m){
		for(int i =0;i<m;i++){
			cout<<arr[i]<<' ';
		}
		cout<<'\n';
	}
	
	for(int i=1;i<=n;i++){
		if(k==0){
			if(!isused[i]){
				arr[k]=i;
				isused[i]=1;
				NaM2(k+1);
				isused[i]=0;
			}
		}
		else{
			int pre = arr[k-1];
			if(!isused[i]&& i>pre){
				arr[k]=i;
				isused[i]=1;
				NaM2(k+1);
				isused[i]=0;
			}
		}
	}
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	NaM2(0);
	
}
