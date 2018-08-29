/*
    Traing algorithm everyday
    2018-08-26
    
    분할 정복(종이의 개수)
    하노이 탑 이동 순서
    규칙 1 : 한번에 한 개의 원판만을 다른 탑으로 옮길 수 있다.
    규칙 2 : 쌓아 놓은 원판은 항상 위의 것이 아래의 것보다 작아야 함
    입력 : 
    첫째 줄에 첫 번째 장대에 쌓인 원판의 개수 N(1<=N<=20)이 주어진다.
    출력 : 
    첫 째 줄에 옮긴 횟수 K를 출력한다. 
    두번 째 줄에 수행 과정을 출력한다. 
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
