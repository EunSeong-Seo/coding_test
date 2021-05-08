#include <string>
#include <vector>

using namespace std;
string ans= "";

int solution(string s) {
    int len = s.length();
    int p =0;
        
    while(p< len){
        
        string ts= "";
        
        if(s[p]>='0'&&'9'>=s[p]){
            ans +=s[p];
            p++;
        }
        else {
        	string cp ="";
        	string np ="";	//이거를 배웄 더  
            cp +=s[p];
            np +=s[p+1];
            ts = cp + np;
            
            if(ts == "ze"){ans+="0"; p+=4;}
            else if(ts == "on"){ans+="1"; p+=3;}
            else if(ts == "tw"){ans+="2"; p+=3;}
            else if(ts == "th"){ans+="3"; p+=5;}
            else if(ts == "fo"){ans+="4"; p+=4;}
            else if(ts == "fi"){ans+="5"; p+=4;}
            else if(ts == "si"){ans+="6"; p+=3;}
            else if(ts == "se"){ans+="7"; p+=5;}
            else if(ts == "ei"){ans+="8"; p+=5;}
            else if(ts == "ni"){ans+="9"; p+=4;}
        }
        
    }
    
    int real_ans = stoi(ans);
    return real_ans;;
}

