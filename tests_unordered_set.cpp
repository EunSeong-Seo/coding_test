#include<iostream>
#include<unordered_set>
using namespace std;
 
int main(void){
    unordered_set<int> s;
 
    s.insert(40);    
    s.insert(10);
    s.insert(80);
    s.insert(30);
    s.insert(70);
    s.insert(60);
    s.insert(20);
    s.insert(50);
 
    unordered_set<int>::iterator iter;
    for(iter = s.begin(); iter != s.end(); iter++){
        cout << *iter << " " ;
    }
    cout << endl;
    
     
    //�ߺ� �� �־��. 
    s.insert(20); 
    for(iter = s.begin(); iter != s.end(); iter++){
        cout << *iter << " " ;
    }    
    cout << endl;    
    
    //���� �ϴ� ���� ã��
    iter = s.find(30);
    if(iter != s.end()){
        cout << *iter << " : ���� " << endl; 
    }else{
        cout << "�������� ���� " << endl; 
    }
 
    //���� ���� �ʴ� ���� ã��    
    iter = s.find(33);
    if(iter != s.end()){
        cout << *iter << " : ���� " << endl; 
    }else{
        cout << "�������� ���� " << endl; 
    }
    
    
    return 0;    
}


//��ó: https://blockdmask.tistory.com/79 [������ ������]
