#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> str;

int main(){
	cin>>n;

	for (int i =0;i<n;i++)
	{
		int p;
		cin>>p;
		str.push_back(p);
	}
	sort(str.begin(), str.end());
	
	int result=0;
	int team=0; 
	
	for (int i =0;i<n;i++)
	{
		team +=1;
		if(team>=str[i]){
			result+=1;
			team=0;
		}
	}
	cout<<result;
	
 }
