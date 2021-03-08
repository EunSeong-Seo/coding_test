#include <bits/stdc++.h>
using namespace std;

stack<int> s;

int main(){
s.push(5);
s.push(3);
s.pop();

while (!s.empty()){
	cout<<s.top() << ' '; 
	s.pop();
	}
}
