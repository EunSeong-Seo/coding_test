#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main(){
q.push(5);
q.push(3);
q.pop();

while (!q.empty()){
	cout<<q.front() << ' ';  //ť�� q.front ������ s.top 
	q.pop();
	}
}
