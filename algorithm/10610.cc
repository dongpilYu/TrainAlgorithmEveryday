/*
    Traing algorithm everyday
    2018-08-20

    greedy algorithm(30 �����)
    �쿬�� ��Ÿ����� ��� N�� ���Ҵ�. 
    ��Ÿ����� ã�� ���� ���Ե� ���ڵ��� ���� 30�� �����
    �Ǵ� ���� ū ���� ����� �;��Ѵ�. �� ���� �����Ѵٸ� 
    �� ���� ����ϰ� ���ٸ� -1�� ����϶� 
    (N�� �ִ� 100,000���� ���ڷ� ����)

    �Է� :
    N

    ����� Ư¡�� ������ �θ� ���߿� ������ �� ���� ������!
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
    
}
