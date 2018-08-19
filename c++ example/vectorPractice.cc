#include <iostream>
#include <vector>
using namespace std;

/*
    https://www.acmicpc.net/board/view/23961(백준)에 따르면
    컴파일 옵션으로 Optimization flag가 없으면 STL이 좀 느리다.
    c++ 컴파일러 옵션이 다양하다.

    vector 컨테이너는 대표적인 시퀀스 컨테이너로 배열과 비슷하며
    사용이 쉬우며 자주 사용된다. vector는 임의 접근 반복자를 지원하는
    배열 기반 컨테이너이다. 가장 큰 특징 중 하나는 원소가 하나의
    메모리 블록에 연속하게 저장된다는 것. 그렇다 보니 원소가 추가될 떄
    메모리 재할당이 발생할 수 있고, 상당한 비용이 요구된다. 
    그래서 메모리 할당 크기를 알 수 있게 capacity() 함수를 제공하며
    한번에 메모리를 할당할 수 있는 reserve() 함수도 제공된다.

    원소가 연속하게 저장되므로 
*/

int main()
{
    vector<int> v;
    v.reserve(8);

    int a[8] = {10,20,30,40,50};

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    // std::vector에 인덱스로 접근
    for(vector<int>::size_type i=0; i<v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
    // std::vector에 iterator로 접근
    for(vector<int>::iterator it=v.begin(); it != v.end(); it++)
        cout << *it << ' ' ;
    cout << endl;
    // 배열에 인덱스로 접근
    for(size_t i=0; i!=(sizeof a/sizeof *a); i++)
        cout << a[i] << ' ' ;
    cout << endl;
    // 배열에 iterator로 접근

    for(int* it = a; it != (a + sizeof(a) / sizeof(*a)); it++)
        cout << *it << ' ';
    cout << endl;
}
