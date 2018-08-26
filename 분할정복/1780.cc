/*
    Traing algorithm everyday
    2018-08-23
    
    ���� ����(������ ����)
    NxN ũ���� ��ķ� ǥ���Ǵ� ���̰� �ִ�.
    ������ �� ĭ���� -1, 0, 1�� �� �� �� �ϳ��� ����Ǿ� �ִ�.
    1. ���� ���̰� ��� ���� ���� �Ǿ� �ִٸ� �״�� ���
    2. 1 �� �ƴ� ��� ���̸� ���� ũ���� 9���� �ڸ���, ������
    �߸� ���̿� ���ؼ� 1 �� ������ �ݺ��Ѵ�.
    �̿� ���� �߶��� ��, ������ ���ڷ� ä���� ������ ������ ���ϴ�
    ���α׷��� �ۼ��϶� 

    �Է� : 
    ù° �ٿ� N(1<=N<=3^7, N�� 3^k��)�� �־�����. 
    ���� N���� �ٿ��� N���� ������ ����� �־�����.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr;
int arrNum[3] = {0,0,0};

int same(int size, int posX, int posY)
{
    bool notAll = false;
    int first = arr[posX][posY];

    for(int i=posX;i<posX+size;i++)
    {
        for(int j=posY;j<posY+size;j++)
        {
            if(first != arr[i][j])
                return 4;
        }
    }
    if(first == 1)
        return 1;
    else if(first == 0)
        return 0;
    else if(first == -1)
        return -1;
}
void sub_problem(int size, int posX, int posY)
{
    int idx;
    if((idx = same(size, posX, posY)) != 4)
        arrNum[idx+1]++;
    
    else
    {
        for(int i=posX;i<posX+size;i+=(size/3))
            for(int j=posY;j<posY+size;j+=(size/3))
                sub_problem(size/3, i, j);
    }
        
}

int main()
{
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++)
    {
        vector<int> element(N);
        arr.push_back(element);
    }

    for(int i=0;i<N;i++) 
    {
        for(int j=0;j<N;j++)
            cin >> arr[i][j];
    }

    int posX = 0;
    int posY = 0;
    int size = N;

    sub_problem(size, posX, posY);

    cout << arrNum[0] << endl;
    cout << arrNum[1] << endl;
    cout << arrNum[2] << endl;
}
