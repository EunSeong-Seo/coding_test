#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 int n;
 int res=0;
 
 bool cmp(int x, int y){
 	return x > y;
 }
 
 int main(){
 	cin>>n;
 	int a[n];
 	bool d[n];	
 	
 	for (int i=0; i<n;i++){
 		int x;
 		cin>>x;
 		a[i]=x;
 		d[i]=false;
	 }
	 
	sort(a,a+n,cmp);

	 for (int i=0;i<n;i++){
	 	if(d[i]==true)continue;
	 	if(i!=n-1){
			if(a[i]>0&&a[i+1]>0){
				res += (a[i]*a[i+1]);
				d[i]= true;
				d[i+1]= true;
			}
			else {
				res+=a[i]+a[i+1];
				d[i]= true;
				d[i+1]=true;
			}
			
		 }
		else{
			res+=a[i];
			 d[i]=true;
	 }
	 }
 	
 	cout<<res<<endl;
 	
 }
