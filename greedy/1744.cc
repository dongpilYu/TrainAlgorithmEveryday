/*
    Traing algorithm everyday
    2018-08-20
    
    greedy algorithm(�� ����)
    ���̰� N�� �������� �� ���� ������ ��� ������ ���� �ִ�� �ϴ� ����
    ���� ������ �ٲ㵵 ��� ����.
    ���� ��ġ�� �ִ� ���� ���� ���� �Ұ���
    �� ���� �� �ѹ��� ���ų� ���� �ʾƾ� ��
    ���� �Ŀ��� �� ���� ���� ���� ��
    �� �� �ִ� ã��

    �Է� : 
    ù �ٿ� ������ ũ�� N�� �־�����.N�� 10,000���� �۴�. ��° �ٺ��� N���� �ٿ� ������ �� ���� �־�����. 
    ������ ���� -10,000 ���� ũ�ų� ����, 10,000 ���� �۰ų� ���� ����
    ��� :
    ���� ������ ���� �� ���� �ִ��� ���, ������ �׻� 2^31���� �۴�.
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
        ����� ū ������
        ������ ���� ������
        0�� ���� �ʴ� ���� �ִ�
        1�� ���� �ʴ� ���� ����.
        ������ �ʴ� ������ �ִ� ��� 0�� �̿��� �� �ִ�.
        (������ ¦�����̸� 0�� �ʿ� ����.)
        -> ���� ó���� �߿伺�� ���캸�� ����
    */
    // 1�� ��� �߿� ���� ���� ��, ��� ���Ϳ��� 1�� ������ ���� Ȧ���̸�
    // 1�� + (Ȧ���� ��� ����� �� ���� ���� ���) + ���� ��
    // ���� �� + (Ȧ���� ��� ����� ���� ū ������ 0�� �ִٸ� ����)


}
