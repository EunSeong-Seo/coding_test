#include <bits/stdc++.h>

using namespace std;

int n;

class Time{
	public:
		int begin;
		int end;
};

bool cmp(Time f, Time s){
	if(f.end ==s.end) return f.begin < s.begin;
	else return f.end<s.end;
		
}


int main(){
	//ó���� ���� ���� ���ڸ� �̰� �״��� �ð����ؼ�  
	cin>>n;
	
	vector <Time> t(n);
	for (int i =0;i<n;i++){
		cin>>t[i].begin>>t[i].end;
	}
	
	sort(t.begin(),t.end(),cmp);
	
	int cnt=0;
	int e=0;
	for (int i=0;i<t.size();i++){
		if(e<=t[i].begin){
			e= t[i].end;
			cnt++;
		}
	}
	cout<<cnt<<endl;
	
}
