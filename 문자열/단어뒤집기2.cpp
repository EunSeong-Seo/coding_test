#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


/*

int s 
int substr

case 1 : if s meet < 
	then continue until >
		+ revese untill now
case 2 : if it is not tag && meet ' '
	then reverse untill now 

start pointer p1
end pointer i

bool tag 
string temp 
substr+= temp 
temp =""

*/

string s ="";
string substr="";

int main(void){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	getline(cin,s);
	cout<<s<<'\n';
	int sp=0;
	bool tag =0;
	string temp ="";
	
	for(int i=0;i<s.size();i++){
		if(s[i]=='<'){
			tag =1;
		}
		if(s[i]=='>'){
			tag=0;
			substr+='>';
		}
		if(tag ==1){
			substr+=s[i];
		}
		if(s[i]!='>'&& tag==0&& i==s.size()-1){
			temp+=s[i];
			reverse(temp.begin(),temp.end());
			substr+=temp;
		}
		if(tag==0 && s[i]==' '){
			reverse(temp.begin(),temp.end());
			substr+=temp;
			substr+=' ';
		}
		if(tag==0&& s[i]!=' '){
			temp+=s[i];
		}
	}
	
	cout<<substr<<'\n';
	
}
