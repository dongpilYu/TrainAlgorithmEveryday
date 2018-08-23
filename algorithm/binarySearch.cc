/*
    Traing algorithm everyday
    2018-08-21
*/  
#include <iostream>
#include <algorithm>
using namespace std;

enum{
    START = 0,
    END = 9,
    SIZE = 10,
    TARGET = 4,
};

int main()
{
    int arr[SIZE] = {1,3,-5,-32,4,56,-435,64,34,2};
    //
    int left = START, right = END, mid=0;
    int pos = -1;

    sort(arr, arr+SIZE);
    for(int i=START;i<SIZE;i++)
        cout << arr[i] << ' ';
    cout << endl;

    while(left <= right)
    {
        int mid = (left+right)/2;
        
        if(TARGET == arr[mid])
        {
            pos = mid;
            break;
        }
        else if(arr[mid] > TARGET)
            right = mid - 1;
        else    
            left = mid + 1;
    }

    cout << pos + 1<< "¹ø Â°" << endl;
}
