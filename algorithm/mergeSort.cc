/*
    합병 정렬은 알아본 선택, 삽입, 버블 정렬과는
    다르게 분할정복법이라는 개념을 사용한다. 
    1. 분할 : 해결하고자 하는 문제를 작은 크기의 동일 문제로 분할
    2. 정복 : 각각의 작은 문제를 순환적으로 해결한다. 
    3. 합병 : 작은 문제의 해를 합하여 원래 문제에 대한 해를 구한다.

    분할을 반복하다보면 마지막은 길이가 1인 구간으로 나눠진다.
    더 이상 분할이 불가능할 때 다시 합병하면서 정렬을 하는 것
    그렇기 때문에 합병 정렬에서 가장 중요한 부분은 실제 정렬을
    수행하는 합병하는 과정이다.

    문제가 겹치지 않기 때문에 Memoization을 쓸 필요 없다.

*/
#include <iostream>
using namespace std;

enum{
    START = 0,
    END = 9,
    SIZE = 10
};

void print_arr(int arr[], int size)
{
    for(int i=START; i<END; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

void merge(int arr[], int left, int mid, int right)
{
    int i,j,k;
    i = left;
    j = mid + 1;
    k = left;

    int tmp_arr[SIZE];
}

void merge_sort(int arr[], int left, int right)
{

    if(left < right) // left == right 인 경우는 하나의 원소만 존재
    {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid); // 정렬됨 
        merge_sort(arr, mid + 1, right); // 정렬됨 
        merge(arr, left, mid, right); // 합치기
    }
}
int main()
{
    int arr[10] = {15, 2, 24, 18, 7, 13, 12, 4, 21, 9};
    print_arr(arr, SIZE);
    merge_sort(arr, START, END);
    print_arr(arr, SIZE);

    return 0;
}
