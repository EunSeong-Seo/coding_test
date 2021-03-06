#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int h,m,s;
	int n;
	int cnt;
	
	cin>>n;
	for(h=0;h<=n;h++)
		for(m=0;m<60;m++)
			for(s=0;s<60;s++){
				if(h==3||m/10==3||m%10==3||s/10==3||s%10==3) cnt++;
			}
			
	cout<<cnt<<endl;
 } 
