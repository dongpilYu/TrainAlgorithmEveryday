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

    if(left < right) // left == right �� ���� �ϳ��� ���Ҹ� ����
    {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid); // ���ĵ� 
        merge_sort(arr, mid + 1, right); // ���ĵ� 
        merge(arr, left, mid, right); // ��ġ��
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
