#include <iostream>
using namespace std;
bool check = 0;

string s;
string sub;
string cmp="";

void check_small(){
	
	for(int i=0;i<cmp.size();i++){
		if(cmp[i]==sub[0]){
			int k =i;
			if(sub.size()==1){
				check =1;
				continue;
			}
			for(int j=1;j<sub.size();j++){
				if(sub[j]==cmp[k+j]) check =1;
				else{
					check =0;
					break;
				}
			}
		}
		if(check) return ;
	}
}


int main(void){	
	cin>>s>>sub;
	
	for(int i=0;i<s.size();i++){
		if(isalpha(s[i])) cmp+=s[i]; 
	}
	
	check_small();
	
	cout<<check;
	
}
