#include <bits/stdc++.h>

using namespace std;

int main(){
   
   //initialization
   int k;
   cin>>k;
   char graph[k][k];
   int center = (k/2);  //��ǥ�� ����  
   int star = k-1;   //star�� ������� �ʱ� ����  
   
   
   for(int i=0; i<k ;i++){
      for (int j =0;j<k;j++){
         if (j== center){
            if (i==center) graph[i][j]= 'O';
            else graph[i][j]='I';
         }
         else if (i == center){
            if (j== center) continue;
            else graph[i][j]= '+';
         }
         else graph[i][j]='.';
      }
   }
   
   for (int i=0; i<k;i++){
      if (i == center){
         star--;
         continue;
      } 
      graph[i][star]='*';
      star--;
   }
   
   for(int i=0; i<k ;i++){
      for (int j =0;j<k;j++){
         cout<< graph[i][j];
      }
      cout<<endl;
   }
   
   cout<<graph;
   
   
}
