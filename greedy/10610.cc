/*
    Traing algorithm everyday
    2018-08-20

    greedy algorithm(30 만들기)
    우연히 길거리에서 양수 N을 보았다. 
    길거리에서 찾은 수에 포함된 숫자들을 섞어 30의 배수가
    되는 가장 큰 수를 만들고 싶어한다. 그 수가 존재한다면 
    그 수를 출력하고 없다면 -1을 출력하라 
    (N은 최대 100,000개의 숫자로 구성)

    입력 :
    N

    배수의 특징을 정리해 두면 나중에 도움이 될 수도 있을듯!
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string inputN;
    cin >> inputN;
    int result = 0;
    bool isZero = false;
    vector<int> numbers;

    for(int i=0;i<inputN.size();i++)
    {
        if ('0' == inputN[i])
            isZero = true;
        result += (inputN[i] - '0');
        numbers.push_back(inputN[i] - '0');
    }
    if(result%3 != 0 || false == isZero)
    {
        cout << -1 << endl;
        return 0;
    }
    sort(numbers.begin(), numbers.end());
    reverse(numbers.begin(), numbers.end());
    for(int i=0;i<numbers.size();i++)
        cout << numbers[i];

    // 다 합쳐서 3의 배수,    
}
