/*
    Traing algorithm everyday
    2018-08-20
    
    greedy algorithm(��ȸ or ����)
    ��ȸ�� ���� �� 2���� ���л��� 1���� ���л��� ����
    �̷�� ���� ��Ģ. n���� ���л��� m���� ���л� ã�� ��
    ���Ͻʿ� �����ؾߵǴ� k���� ��ȸ�� ���� ���Ѵ�.

    Contest > Croatian Open Competition in Informatics > COCI 2010/2011 > Contest #1 1��

    �Է� :
    N, M, K�� ������� �־�����. 
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
