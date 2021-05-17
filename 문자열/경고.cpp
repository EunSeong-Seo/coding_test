#include <iostream>

using namespace std;

int main(void){
	
	int h1,m1,s1;
	int h2,m2,s2;
	
	int rh,rm,rs;
	
	scanf("%d:%d:%d",&h1,&m1,&s1);
	scanf("%d:%d:%d",&h2,&m2,&s2);
	
	if(h2>=h1){
		rh = h2-h1; 
	}
	else{
		rh = 24-h1+h2;
	}
	
	if(m2>=m1){
		rm= m2-m1;
	}
	else{
		rh-=1;
		rm = 60-m1+m2;
	}
	if(s2>=s1){
		rs = s2-s1;
	}
	else{
		rm-=1;
		rs= 60 -s1+s2;
	}
	
	printf("%02d:%02d:%02d",rh,rm,rs); 
	
	
}
