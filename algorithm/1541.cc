/*
    Traing algorithm everyday
    2018-08-16
    
    greedy algorithm(잃어 버린 괄호)
    첫째 줄에 식이 주어진다. 식은 0~9, +, -로 구성
    가장 처음과 마지막 문자는 숫자
    연속해서 두 개 이상의 연산자가 나타나지 않고,
    5자리 이상 연속되는 숫자는 없다. 수는 0으로 시작 가능
    
 
    ex3) 20 + 30 - ((70 + 20 - 10) + 40) - 20
      -> 20 + 30 - 70 + 20 - 10 + 40 - 20
      = 10, -30, -70, -10, 30
      = 50 - 120 - 20 
      = -90
      = 20 + 30 - 90 - 50 - 20
      = 50 - 90 - 50 - 20
      = -110
*/

#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

/*
enum은 상수를 정의하는데에 많이 쓰인다.
소스의 가독성을 높이거나 상수에 의미를 부여해서 쓸 수 있다.
const와 #define보다 장점이 존재한다.
1. 기억이 용이하다. 
2. 소스의 가독성이 높아진다. 
3. 안전하다.
*/

enum oper {
    MINUS = 100001,
    PLUS = 100000,
};

int main()
{
    string str;
    cin >> str;

    vector<int> numbers;
    // 입력되는 수의 범위가 0~99999
    // 20+30-70+20-10+40-20
    // 20-1+430-20+30-31-23-4
    bool minusOn = false;
    int idx = 0;
    int idxOfNumbers = 0;
    for(int i=0;i<str.length();i++)
    {
        if(!isdigit(str[i]))
        {
            // 숫자가 아닐 때
            string subString = str.substr(idx, i-idx);
            // substr은 [idx, i)의 문자열이 아니라 idx부터 i개
            numbers.push_back(stoi(subString));
            idx = i + 1;

            if('-' == str[i])
                numbers.push_back(MINUS);
            else if('+' == str[i])
                numbers.push_back(PLUS);
   
        }
    }
    // 마지막 수를 위한 코드
    numbers.push_back(stoi(str.substr(idx, str.length()-idx)));

    for(int i=1;i<numbers.size();i+=2)
    {
        if(numbers[i] == MINUS)
            minusOn = true;   
        
        else if(numbers[i] == PLUS)
        {
            if(minusOn)
                numbers[i] = MINUS;
        }
    }

    int result = numbers[0];
    for(int i=1;i<numbers.size();i+=2)
    {
        if(numbers[i] == PLUS)
            result += numbers[i+1];
        else
            result -= numbers[i+1];  
    }

    cout << result << endl;
    // 20+30-70+20+10+40-20 = 20+30-70-20-10-40-20
}
