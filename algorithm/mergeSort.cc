/*
    �պ� ������ �˾ƺ� ����, ����, ���� ���İ���
    �ٸ��� �����������̶�� ������ ����Ѵ�. 
    1. ���� : �ذ��ϰ��� �ϴ� ������ ���� ũ���� ���� ������ ����
    2. ���� : ������ ���� ������ ��ȯ������ �ذ��Ѵ�. 
    3. �պ� : ���� ������ �ظ� ���Ͽ� ���� ������ ���� �ظ� ���Ѵ�.

    ������ �ݺ��ϴٺ��� �������� ���̰� 1�� �������� ��������.
    �� �̻� ������ �Ұ����� �� �ٽ� �պ��ϸ鼭 ������ �ϴ� ��
    �׷��� ������ �պ� ���Ŀ��� ���� �߿��� �κ��� ���� ������
    �����ϴ� �պ��ϴ� �����̴�.

    ������ ��ġ�� �ʱ� ������ Memoization�� �� �ʿ� ����.

    Ż�� ������ �ΰ� �̸��� ��Ұ� ���Ե� ���� �迭(right<=left))
    ��Ұ� �ϳ��� ���ų� �ϳ��� �ִ� ���� �迭�� �̹� ���ĵ� ��
    �ϳ��� ���� ���� ����. �׷��Ƿ� right == left�� �ص� ������ ��

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
    // mid�� �������� [0,mid] [mid+1,end]��
    // �迭�� �������� ����
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
    if(left < right) // left == right �� ���� �ϳ��� ���Ҹ� ����
    {
        int mid = (left + right) / 2;
        // mid�� ���� ����ؼ� �ѱ⳪ �Ѱܼ� ����ϳ� ����
        merge_sort(arr, left, mid); 
        merge_sort(arr, mid + 1, right); 
        merge(arr, left, mid, right); 
        // �� �迭�� ��ġ�µ�, �� �迭�� ��� ���ĵ� ����
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
