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

    탈출 조건은 두개 미만의 요소가 포함된 하위 배열(right<=left))
    요소가 하나도 없거나 하나만 있는 하위 배열은 이미 정렬된 것
    하나도 없을 수는 없다. 그러므로 right == left로 해도 무관할 듯

    nlogn
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
    // mid를 기준으로 [0,mid] [mid+1,end]로
    // 배열이 나누어진 상태
    int sorted_arr[SIZE];
    int idx_left = left;
    int idx_right = mid+1;
    int idx = left;

    // idx, idx_left, idx_right
    // mid = 3, right = 6
    // 0, 0, 4
    // 1, 1, 4
    // 2, 2, 4
    // 3, 2, 5
    // 4, 3, 5
    // 5, 4, 5
    // 6, 5, 6
    // 7, 5, 7
    while(idx_left <= mid && idx_right <= right)
    {
        if(arr[idx_left] > arr[idx_right])
            sorted_arr[idx++] = arr[idx_right++];
        else
            sorted_arr[idx++] = arr[idx_left++];
    }
    if(idx_left > mid)
        while(idx_right <= right)
            sorted_arr[idx++] = arr[idx_right++];       
    
    else if(idx_right > right)
        while(idx_left <= mid)
            sorted_arr[idx++] = arr[idx_left++];
   
    for(int i=left;i<right+1;i++)
        arr[i] = sorted_arr[i];
}

void merge_sort(int arr[], int left, int right)
{
    if(left < right) // left == right 인 경우는 하나의 원소만 존재
    {
        int mid = (left + right) / 2;
        // mid의 값을 계산해서 넘기나 넘겨서 계산하나 무관
        merge_sort(arr, left, mid); 
        merge_sort(arr, mid + 1, right); 
        merge(arr, left, mid, right); 
        // 두 배열을 합치는데, 두 배열은 모두 정렬된 상태
    }
}
int main()
{
    int arr[SIZE] = {15, 2, 24, 18, 7, 13, 12, 4, 21, 9};
    //int arr[SIZE] = {1,3,7,11,4,15,17};
    print_arr(arr, SIZE);
    merge_sort(arr, START, END);
    print_arr(arr, SIZE);

    return 0;
}
