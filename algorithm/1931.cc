/*
    Traing algorithm everyday
    2018-08-13
    
    greedy algorithm(ȸ�ǽ� ����)
    ȸ�ǽ� ���ǥ �����
    �� ȸ���� ���� �ð��� ������ �ð��� �־��� �ְ�,
    �� ȸ�ǰ� ��ġ�� �ʰ� �ϸ鼭 ȸ�ǽ��� ����� �� �ִ�
    �ִ� ���� ȸ�Ǹ� ã�ƶ� (�߰��� �ߴ� �Ұ�, ���� ���ÿ� ���� ����)
    ȸ�� ���� �ð��� �� �ð��� ���� �� �ִ�.(�������� ���� ��)

    �ݷʰ� ������ ���� greedy�� �Ұ�, ����� Ǯ�̰� �Ұ����ϴ�.
    ���� ������ ȸ�Ǹ� �����ϴ� ���� ���� ����� Ǯ��!
    ���� ������ �ٲ�� �ȴ�.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Meeting {
    int begin, end;
};

bool cmp(const Meeting &u, const Meeting &v)
{
    if (u.end == v.end)
        return u.begin < v.begin;
    else    
        return u.end < v.end;
}

int main()
{
    int n=0;
    int idx=0;
    cin >> n;
    vector<Meeting> a(n);
    for (int i=0; i<n; i++)
        scanf("%d %d",&a[i].begin,&a[i].end);
    
    // ��ü�� ���ؼ�, end�� ���� ���� �ε����� ����
    // �ش� �ε����� �� ���� ����ϰ� �� ������ ũ�鼭
    // end�� ���� ���� ���� �ε����� ���� <�ݺ�>

    sort(a.begin(), a.end(), cmp);
    // a < b �̸� true, �ƴϸ� false�� ��ȯ
    // iterator�� random access�� �����ؾ� �ϸ�, ������ �����ؾ���
    // vector�� arr�� �� ���ǿ� ����
    // class�� �ڷ������� ������ operator < �� �����ε��ϰų�
    // ����� ���� �Լ��� ���ؼ� ����
    // pair�� ����� ���, pair�� ù ��° ���Ҹ� �������� ����
    int now = 0;
    int ans = 0;

    for(int i=0; i<a.size(); i++)
    {
        if(now <= a[i].begin)
        {
            now = a[i].end;
            ans += 1;
        }
    }

    printf("%d\n", ans);
}