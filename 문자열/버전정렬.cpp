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

���� ���̴� �󸶳� �˴ϱ�
����Ʈ�� ������ ���Ѿ�����
������ �� ������ ��ΰ��� ���� �־����͸� �����ϸ� �ǳ���?
�����̸��� �� ������� �����ص� ��������?
�������� char���� ���� �ֳ���? �׷��� int�θ� �ϴ°ɷ� �ϰڽ��ϴ�  
�� �׷����� �����ؼ� ����ڽ��ϴ�
���� �̹���� �� �������� ������ ���Ƽ� �غ��ڽ��ϴ� 
���� �ٸ������ �����ϱ� ���� �ڵ带 ���� �̷��� �Ͽ����ϴ�  
���ٷ� ǥ���ص� ��������?  
 
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
	
	stringstream ss(a);	//�̰��� ������ �����ϱ�  
	while(getline(ss,s,'.')) v.push_back(s);	//�̰ɷ� �и��մϴ�  
	
	return v;
} 

bool cmp(const string& a, const string& b){
	
	vector<string> va,vb;
	va = getTokens(a);  
	vb = getTokens(b);	
	
	for(int i =0;i<min(va.size(),vb.size());i++) // the more point, the more next �̰Ÿ� �����ϱ�  
	{
		int countcheck = check(va[i],vb[i]);
		
		if(countcheck == -1)return true;	//true means that a < b
		else if (countcheck == 1)return false;	//false means that a>b
	}
	
	if(va.size()<vb.size()) return true;
	return false;
	
}


int main(void){
	
	ios::sync_with_stdio(0);	//�ӵ��� �����ϱ� ���� ����ϴ�.  
	cin.tie(0);
	
	vector<string> s;		
 	s.push_back("1.1.0"); 
    s.push_back("1.2.1");
    s.push_back("0.9.1");
    s.push_back("1.3.4");
    s.push_back("1.1.2");
    s.push_back("1.1.2.2.3");
    s.push_back("9.3");
	
	sort(s.begin(),s.end(),cmp); //include <algorithm>  ���� ���� �ִ� sort�Լ��� �̿��߽��ϴ�  
	
	for(int i=0;i<s.size();i++){
		cout<<s[i]<<'\n';
	} 
	cout<<'\n';
	
	return 0;
	
	//O(N*L *logN) where N is the total number of version string ,
	// L is the maximum length among those strings  
}
