#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n ,m;
int mini=2501;
int change;
int change1;
int change2;

char chese1[8][8]=
{{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'}};

char chese2[8][8]=
{{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'}};

int main(){
	cin>>n>>m;
	char a[n][m];

	for (int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}

	for(int i=0;i<n-8+1;i++){
		for(int j=0;j<m-8+1;j++){
			change=0;
			change1=0;
			change2=0;
			
			for(int k=0;k<8;k++){
				for(int l=0;l<8;l++){
					if(a[k+i][l+j]!=chese1[k][l]) change1++;
					if(a[k+i][l+j]!=chese2[k][l]) change2++;
					change = min(change1,change2);
				}
			}
			if(mini>change) mini= change;
		}
	}
	
	cout<<mini<<endl;
	
} 
