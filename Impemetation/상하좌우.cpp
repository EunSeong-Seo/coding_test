#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
string plans;
int x=1,y=1;

//L R U D
int dx[4]={0,0,-1,+1};
int dy[4]={-1,1,0,0};
char moveType[4]= {'L','R','U','D'};

int main(){
	cin>>n;
	cin.ignore();
	getline(cin,plans);
	
	for (int i =0;i<plans.size();i++){
		char plan = plans[i];
		int nx  =-1,ny=-1; 
		//nx와 ny를 설정한이유는 범위를 넘었을때 다시 취소할방법으로 쓰려고 
	
		for (int j =0;j<4;j++){
			if(plan == moveType[j]){
				nx = x+dx[j];
				ny = y +dy[j];
			}
		}
		if (nx<1||ny<1||nx>n||ny>n) continue;
		x=nx;
		y=ny;
	}
	cout<<x<<" "<<y<<endl;
	return 0;
		
	
 }
