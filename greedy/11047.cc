/*
    Traing algorithm everyday
    2018-08-12
    
    greedy algorithm(���� ���)
    ������ N ����, ������ ������ ������ ����.
    ������ ������ ����� ��ġ ���� K�� ����
    ���� ������ �ּҰ��� ���ϴ� ���α׷��� �ۼ�
    N���� �ٿ� ������ ��ġ A_i�� ������������ �־���
    (1<=A_i<=1,000,000, A_1=1, i>=2�� ��쿡�� A_i�� A_i-1�� ���)
*/

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];
    // n���� ������ ��ġ�� �Է�
    int ans = 0;
    for (int i=n-1; i>=0; i--){
        ans += k/a[i];
        k %= a[i];
    }
    cout << ans << '\n';
    return 0;

    
}
