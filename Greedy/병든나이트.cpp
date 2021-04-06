#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s,t;
bool possible;

int main(){
	cin>>s>>t;
	
	while(1){
		
		if(s.length()==t.length()){
			if(s==t) possible = true;
			break;
		}
		
		char c= t[t.length()-1];
		t.pop_back();
		if(c=='B') reverse(t.begin(),t.end());
	}
	
	cout<<possible<<endl;
}
