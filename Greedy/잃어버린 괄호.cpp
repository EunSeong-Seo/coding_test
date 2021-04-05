#include <iostream>

#include <string>

using namespace std;

 

string str;

 

int minResult(void)

{

        int result = 0;

        string temp = "";

        bool minus = false;

        for (int i = 0; i <= str.size(); i++)

        {

                 //연산자일 경우

                 if (str[i] == '+' || str[i] == '-' || str[i] == '\0')

                 {

                         if (minus)

                                 result -= stoi(temp);

                         else

                                 result += stoi(temp);

                         temp = ""; //초기화

                         //괄호를 뺄셈 이후에 치면 최소

                         if (str[i] == '-')

                                 minus = true;

                         continue;

                 }

                 //피연산자일 경우

                 temp += str[i];

        }

        return result;

}

 

int main(void)

{

        cin >> str;

 

        cout << minResult() << endl;

        return 0;

}



//출처: https://jaimemin.tistory.com/504 [꾸준함]
