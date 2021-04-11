#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

string s;
string t;

void rev_a(string x){
	x.pop_back();
}

void rev_b(string x){
	reverse(x.begin(),x.end());
	x.pop_back();
}

bool cal(string s, string t){
	if(s.size()==t.size()){
		if(s==t)return true;
	}
	else{
		if(t[0]=='A'&&t[t.size()-1]=='A'){
			rev_a(t);
		}
		else if(t[0]=='A'&&t[t.size()-1]=='B') return false;
		else if(t[0]=='B'&&t[t.size()-1]=='A') {
			return 
		}
		else if(t[0]=='B'&&t[t.size()-1]=='B') return 
	}
	
	
}

int main(){
	cin>>s;
	cin>>t;
	
	while (s.size()!=t.size()){
		
		if(s==)
		
		
	}
}
