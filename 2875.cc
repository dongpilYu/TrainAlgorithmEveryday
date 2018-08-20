/*
    Traing algorithm everyday
    2018-08-20
    
    greedy algorithm(대회 or 인턴)
    대회에 나갈 때 2명의 여학생과 1명의 남학생이 팀을
    이루는 것이 원칙. n명의 여학생과 m명의 남학생 찾는 중
    인턴십에 참가해야되는 k명은 대회를 참가 못한다.

    Contest > Croatian Open Competition in Informatics > COCI 2010/2011 > Contest #1 1번

    입력 :
    N, M, K가 순서대로 주어진다. 
    (0 <= M <= 100, 0 <= N <= 100, 0 <= K < M+N)
*/

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    int result = 0;
    
    while(true)
    {
        if(N+M >= K+3 && N >= 2 && M >= 1)
        {
            N -=2;
            M -=1;
            result ++;
        }
        else
            break;

        
    }

    cout << result << endl;
}
