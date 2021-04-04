#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

bool cmp(int x, int y){
	return x<y;
}

int main(){
	int n;
	cin>> n;
	
	vector <int> p;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		p.push_back(x);
	}
	
	sort(p.begin(),p.end(),cmp);
	
	int res=0;
	int pn=n;
	
	for(int i=0;i<n;i++){
		res += pn * p[i];
		pn--;
	}
	cout<<res<<endl;
	
	
	
}
