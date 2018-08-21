#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[10] = {1,3,-5,-32,4,56,-435,64,34,2};
    //
    int left=0, right=9, mid=0;
    int pos = -1;
    int x = 4;

    sort(arr, arr+10);
    for(int i=0;i<10;i++)
        cout << arr[i] << ' ';
    cout << endl;

    while(left <= right)
    {
        int mid = (left+right)/2;
        
        if(x == arr[mid])
        {
            pos = mid;
            break;
        }
        else if(arr[mid] > x)
            right = mid - 1;
        else    
            left = mid + 1;
    }

    cout << pos + 1<< "¹ø Â°" << endl;
}
