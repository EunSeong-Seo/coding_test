#include <iostream>
#include <string>
 
 
using namespace std;

int main(){
	string str = "123456789";
	string a = str.substr(1,2);
	str.erase(2,3);
	cout<<a<<endl<<str<<endl;
	
	
}
