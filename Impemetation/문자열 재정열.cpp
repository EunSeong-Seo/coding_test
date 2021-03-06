#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<char> ch;
int sum=0;

int main(){
	string s;
	cin>>s;
	
	for(int i =0;i<s.size();i++)
	{
		if(isalpha(s[i]))ch.push_back(s[i]);
		else sum+= s[i] -'0';
	}
	sort(ch.begin(),ch.end());
	
	for(int i =0;i<ch.size();i++) cout<<ch[i];
	cout<<sum;
	
	
	
}
