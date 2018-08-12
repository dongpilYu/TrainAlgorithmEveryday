/*
    Traing algorithm everyday
    2018-08-12
    
    greedy algorithm(동전 배수)
    동전은 N 종류, 각각의 동전은 무수히 많다.
    동전을 적절히 사용해 가치 합을 K로 만듦
    동전 개수의 최소값을 구하는 프로그램을 작성
    N개의 줄에 동전의 가치 A_i가 오름차순으로 주어짐
    (1<=A_i<=1,000,000, A_1=1, i>=2인 경우에는 A_i는 A_i-1의 배수)

*/

#include <iostream>
#include <vector.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];
    // n개의 동전의 가치를 입력
    int ans = 0;
    for (int i=n-1; i>=0; i--){
        ans += k/a[i];
        k %= a[i];
    }
    cout << ans << '\n';
    return 0;

    
}


