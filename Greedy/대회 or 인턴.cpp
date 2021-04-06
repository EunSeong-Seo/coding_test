#include <iostream>

using namespace std;

int m,n,k;
int team=0;
int el=0;
bool over =false;

int main(){
	
	cin>>m>>n>>k;
	
	while(true){
		if (m>=2&&n>=1){
			m-=2;
			n-=1;
			team++;
		}
		else break;
	}
	el = m+n;
	
	while(true){
		if(k > el){
			team--;
			el+=3;
			}
		else{
			cout<<team<<endl;
			break;
			}
		}
		
	}
