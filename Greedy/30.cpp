#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string num;
int res=0;
bool zero = false;

bool cmp(int x, int y){
	return x>y;
}

int main(){
	cin>> num;
	for (int i=0; i<num.size();i++){
		res+=num[i]-'0';
		if (num[i]-'0'==0) zero= true;
	}

	if(!zero||res%3){
		cout<<-1<<endl;
	}
	else {
		sort(num.begin(),num.end(),cmp);
		cout<<num<<endl;
	}

	
}
