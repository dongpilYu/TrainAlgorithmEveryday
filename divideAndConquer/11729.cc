/*
    Traing algorithm everyday
    2018-08-26
    
    ���� ����(������ ����)
    �ϳ��� ž �̵� ����
    ��Ģ 1 : �ѹ��� �� ���� ���Ǹ��� �ٸ� ž���� �ű� �� �ִ�.
    ��Ģ 2 : �׾� ���� ������ �׻� ���� ���� �Ʒ��� �ͺ��� �۾ƾ� ��
    �Է� : 
    ù° �ٿ� ù ��° ��뿡 ���� ������ ���� N(1<=N<=20)�� �־�����.
    ��� : 
    ù ° �ٿ� �ű� Ƚ�� K�� ����Ѵ�. 
    �ι� ° �ٿ� ���� ������ ����Ѵ�. 
*/

#include <iostream>
#include <vector>
using namespace std;

int memo[20][3][3];

void solve(int n, int x, int y)
{
    if(n==0)
        return;
    solve(n-1,x,6-x-y); // x+y+z = 6
    cout << x << ' ' << y << endl;
    solve(n-1,6-x-y,y);

    // solve(20,1,3) = solve(19,1,2) + cout + solve(19,2,3)
    // solve(19,1,2) = solve(18,1,3) + cout + solve(18,3,2)
    // solve(19,2,3) = solve(18,2,1) + cout + solve(18,1,2)
}

int main()
{
    int n;
    cin >> n;
    
    cout << (1<<n) -1 << endl;
    solve(n,1,3);
}
