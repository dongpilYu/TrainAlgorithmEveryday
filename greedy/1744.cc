/*
    Traing algorithm everyday
    2018-08-20
    
    greedy algorithm(수 묶기)
    길이가 N인 수열에서 두 수를 적절히 묶어서 수열의 합을 최대로 하는 문제
    수의 순서를 바꿔도 상관 없다.
    같은 위치에 있는 수를 묶는 것은 불가능
    각 수는 단 한번만 묶거나 묶지 않아야 함
    묶은 후에는 두 수의 곱이 수가 됨
    이 때 최대 찾기

    입력 : 
    첫 줄에 수열의 크기 N이 주어진다.N은 10,000보다 작다. 둘째 줄부터 N개의 줄에 수열의 각 수가 주어진다. 
    수열의 수는 -10,000 보다 크거나 같고, 10,000 보다 작거나 같은 정수
    출력 :
    수를 적절히 묶어 그 합의 최댓값을 출력, 정답은 항상 2^31보다 작다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int inputN, num;
    cin >> inputN;
    vector<int> plus;
    vector<int> minus;

    int numOfZero = 0;
    int numOfOne = 0;

    for(int i=0; i<inputN; i++)
    {
        cin >> num;
        
        if(num > 0)
        {
            if (num == 1)
                numOfOne ++;
            plus.push_back(num);
        }
        else if(num < 0)
            minus.push_back(num);
        else
            numOfZero ++;
    }
    
    sort(minus.begin(), minus.end()); // -124,-23,-5,-2,-1
    reverse(minus.begin(), minus.end()); // -1,-2,-5,-23,-124
    sort(plus.begin(), plus.end()); // 1,3,4,13,151,1231

    int result = 0;
        
    if(1 == (plus.size() - numOfOne) % 2)
    {
        result += (numOfOne + plus[numOfOne]);
        for(vector<int>::size_type i=numOfOne+1; i<plus.size(); i+=2)
            result += (plus[i]*plus[i+1]);
    }
    else
    {
        result += numOfOne;
        for(vector<int>::size_type i=numOfOne; i<plus.size(); i+=2)
            result += plus[i]*plus[i+1];
    }

    if(1 == (minus.size()%2))
    {
        for(vector<int>::size_type i=1;i<minus.size();i+=2)
            result += minus[i]*minus[i+1];
            
        if(0 == numOfZero)
            result += minus[0];
    }
    else
    {
        for(vector<int>::size_type i=0;i<minus.size();i+=2)
            result += minus[i]*minus[i+1];
        
    }
    cout << result << endl;
    /*
        양수는 큰 수끼리
        음수는 작은 수끼리
        0은 묶지 않는 것이 최대
        1은 묶지 않는 것이 좋다.
        묶이지 않는 음수가 있는 경우 0을 이용할 수 있다.
        (음수가 짝수개이면 0은 필요 없다.)
        -> 예외 처리의 중요성을 살펴보는 문제
    */
    // 1은 양수 중에 작은 작은 것, 양수 벡터에서 1의 개수를 빼고 홀수이면
    // 1들 + (홀수일 경우 생기는 그 다음 작은 양수) + 묶음 곱
    // 묶음 곱 + (홀수일 경우 생기는 가장 큰 음수는 0이 있다면 없앰)


}
