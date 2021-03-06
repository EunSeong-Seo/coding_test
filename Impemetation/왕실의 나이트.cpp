#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string position;
int dx[8]={-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8]={-1, -2, -2, -1, 1, 2, 2, 1};
int cnt=0;

int main(){
	cin>> position;
	
	int x= position[1] -'0';
	int y= position[0]-'a'+1; 
	
	for (int i =0;i<8;i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<=0||ny<=0||nx>8||ny>8) continue;
		cnt++;
	}
	cout<<cnt<<endl;
}
