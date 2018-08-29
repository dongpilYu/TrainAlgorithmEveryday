/*
    Traing algorithm everyday
    2018-08-23
    
    분할 정복(종이의 개수)
    NxN 크기의 행렬로 표현되는 종이가 있다.
    종이의 각 칸에는 -1, 0, 1의 세 값 중 하나가 저장되어 있다.
    1. 만약 종이가 모두 같은 수로 되어 있다면 그대로 사용
    2. 1 이 아닌 경우 종이를 같은 크기의 9개로 자르고, 각각의
    잘린 종이에 대해서 1 의 과정을 반복한다.
    이와 같이 잘랐을 때, 각각의 숫자로 채워진 종이의 개수를 구하는
    프로그램을 작성하라 

    입력 : 
    첫째 줄에 N(1<=N<=3^7, N은 3^k꼴)이 주어진다. 
    다음 N개의 줄에는 N개의 정수로 행렬이 주어진다.
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
