#include <iostream>

using namespace std;

string str;

int main(){
	
	cin >> str;
	
	long long result = str[0] - '0';
	int n;
	
	for (int i =1;i< str.size();i++)
	{
		if (result<2){
			result += str[i]-'0';
		}
		else 
		 result *=str[i]-'0';
	}
	cout<<result;
 }
