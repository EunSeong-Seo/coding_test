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

                 //�������� ���

                 if (str[i] == '+' || str[i] == '-' || str[i] == '\0')

                 {

                         if (minus)

                                 result -= stoi(temp);

                         else

                                 result += stoi(temp);

                         temp = ""; //�ʱ�ȭ

                         //��ȣ�� ���� ���Ŀ� ġ�� �ּ�

                         if (str[i] == '-')

                                 minus = true;

                         continue;

                 }

                 //�ǿ������� ���

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



//��ó: https://jaimemin.tistory.com/504 [������]
