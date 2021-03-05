#include <iostream>

using namespace std;

int n;
int a[4]={500,100,50,10};
int result=0;
int count=0;

int main()
{
	cin>>n;
	
	for(int i =0;i<4;i++)
	{
		count = n/a[i];
		result +=count;
		n -= count * a[i];
	}
	cout<<result;
}
