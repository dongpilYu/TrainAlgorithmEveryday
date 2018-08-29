/*
    Traing algorithm everyday
    2018-08-16
    
    greedy algorithm(�Ҿ� ���� ��ȣ)
    ù° �ٿ� ���� �־�����. ���� 0~9, +, -�� ����
    ���� ó���� ������ ���ڴ� ����
    �����ؼ� �� �� �̻��� �����ڰ� ��Ÿ���� �ʰ�,
    5�ڸ� �̻� ���ӵǴ� ���ڴ� ����. ���� 0���� ���� ����
*/

#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

/*
enum�� ����� �����ϴµ��� ���� ���δ�.
�ҽ��� �������� ���̰ų� ����� �ǹ̸� �ο��ؼ� �� �� �ִ�.
const�� #define���� ������ �����Ѵ�.
1. ����� �����ϴ�. 
2. �ҽ��� �������� ��������. 
3. �����ϴ�.
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
    // �ԷµǴ� ���� ������ 0~99999
    // 20+30-70+20-10+40-20
    // 20-1+430-20+30-31-23-4
    bool minusOn = false;
    int idx = 0;
    int idxOfNumbers = 0;
    for(int i=0;i<str.length();i++)
    {
        if(!isdigit(str[i]))
        {
            // ���ڰ� �ƴ� ��
            string subString = str.substr(idx, i-idx);
            // substr�� [idx, i)�� ���ڿ��� �ƴ϶� idx���� i��
            numbers.push_back(stoi(subString));
            idx = i + 1;

            if('-' == str[i])
                numbers.push_back(MINUS);
            else if('+' == str[i])
                numbers.push_back(PLUS);
   
        }
    }
    // ������ ���� ���� �ڵ�
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
}
