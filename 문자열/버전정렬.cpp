#include <bits/stdc++.h>

using namespace std;


/*
1.1
1.2
1.2.1
1.2.1.1
1.3

cgcm 
int check 
vector 

version number is no limit
string length is no limit 

while loop :
if (version front num ==)
	then next position( after point)
	
int check <= compare version length 
bool cmp () <= compare the versions
vector gettoken (a) <= split string without point(.)

sort( v.begin(), v.end(),cmp)

버전 길이는 얼마나 됩니까
포인트의 갯수는 제한없나요
버전의 총 갯수는 몇개인가요 지금 주어진것만 정렬하면 되나요?
변수이름은 제 마음대로 선정해도 괜찮나요?
버전에는 char형이 들어갈수 있나요? 그러면 int로만 하는걸로 하겠습니다  
오 그렇군요 참고해서 만들겠습니다
뭔가 이방식이 더 빠를수도 있을거 같아서 해보겠습니다 
저는 다른사람이 이해하기 쉬운 코드를 위해 이렇게 하였습니다  
한줄로 표현해도 괜찮나요?  
 
*/

int check (const string& a, const string& b){	
	int al = a.length();	
	int bl = b.length();	
	
	int i = 0;
	int j = 0;
	
	while(i<al && j<bl ){
		if(a[i]==b[i]){
			++i;
			++j;
		}
		else if(a[i]> b[j])return 1;	// 1 means that a is following
		else return -1;					//-1 means that a is previous 
	} 
	
	if(i==al && j == bl) return 0;		// 0 means that a is eaual to b
	if (j == bl)return 1;				// 1 means that a is  previous
	return -1;							// -1 means that a is previous
}

vector<string> getTokens(const string &a){
	vector<string> v;
	string s;
	
	stringstream ss(a);	//이것의 역할을 설명하기  
	while(getline(ss,s,'.')) v.push_back(s);	//이걸로 분리합니다  
	
	return v;
} 

bool cmp(const string& a, const string& b){
	
	vector<string> va,vb;
	va = getTokens(a);  
	vb = getTokens(b);	
	
	for(int i =0;i<min(va.size(),vb.size());i++) // the more point, the more next 이거를 설명하기  
	{
		int countcheck = check(va[i],vb[i]);
		
		if(countcheck == -1)return true;	//true means that a < b
		else if (countcheck == 1)return false;	//false means that a>b
	}
	
	if(va.size()<vb.size()) return true;
	return false;
	
}


int main(void){
	
	ios::sync_with_stdio(0);	//속도를 빨리하기 위해 썼습니다.  
	cin.tie(0);
	
	vector<string> s;		
 	s.push_back("1.1.0"); 
    s.push_back("1.2.1");
    s.push_back("0.9.1");
    s.push_back("1.3.4");
    s.push_back("1.1.2");
    s.push_back("1.1.2.2.3");
    s.push_back("9.3");
	
	sort(s.begin(),s.end(),cmp); //include <algorithm>  저는 여기 있는 sort함수를 이용했습니다  
	
	for(int i=0;i<s.size();i++){
		cout<<s[i]<<'\n';
	} 
	cout<<'\n';
	
	return 0;
	
	//O(N*L *logN) where N is the total number of version string ,
	// L is the maximum length among those strings  
}
