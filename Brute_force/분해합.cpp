#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
int sum;
int mini;

int main(){
	
	cin>>n;
	
	for(int i=1;i<n;i++){
		int sum=0;
		string num = to_string(i);

		for(int j=0;j<num.size();j++){
			sum+=num[j]-'0';
		}
		sum+=i;
		if(sum==n) { mini = i; break;}
	}
	if(mini==0)cout<<0<<endl;
	else cout<<mini<<endl;
	
} 
