#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main(){
q.push(5);
q.push(3);
q.pop();

while (!q.empty()){
	cout<<q.front() << ' ';  //큐는 q.front 스택은 s.top 
	q.pop();
	}
}
