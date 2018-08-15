/*
    Traing algorithm everyday
    2018-08-13
    
    greedy algorithm(회의실 배정)
    회의실 사용표 만들기
    각 회의의 시작 시간과 끝나는 시간이 주어져 있고,
    각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는
    최대 수의 회의를 찾아라 (중간에 중단 불가, 끝과 동시에 시작 가능)
    회의 시작 시간과 끝 시간이 같을 수 있다.(시작하자 마자 끝)

    반례가 나오는 순간 greedy는 불가, 깔끔한 풀이가 불가능하다.
    일찍 끝나는 회의를 선택하는 것이 가장 깔끔한 풀이!
    정렬 문제로 바뀌게 된다.
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
// 위 comparator function을 통해서 end 값이 같을 경우
// begin 값이 작은 Meeting 객체가, end 값이 다를 경우
// end 값이 작은 Meeting 객체가 앞에 가도록 정렬된다.

int main()
{
    int n=0;
    int idx=0;
    cin >> n;
    vector<Meeting> a(n);
    for (int i=0; i<n; i++)
        scanf("%d %d",&a[i].begin,&a[i].end);
    
    // 전체를 비교해서, end가 작은 값의 인덱스를 저장
    // 해당 인덱스의 끝 값을 기억하고 그 값보다 크면서
    // end가 가장 작은 값의 인덱스를 저장 <반복>

    sort(a.begin(), a.end(), cmp);
    // a < b 이면 true, 아니면 false를 반환
    // iterator는 random access가 가능해야 하며, 수정이 가능해야함
    // vector와 arr은 위 조건에 만족
    // class를 자료형으로 쓰려면 operator < 를 오버로딩하거나
    // 사용자 정의 함수를 통해서 정렬
    // pair를 사용할 경우, pair의 첫 번째 원소를 기준으로 정렬
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
