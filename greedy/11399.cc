/*
    Traing algorithm everyday
    2018-08-15
    
    greedy algorithm(ATM) 
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int num = 0;
    cin >> num;
    vector<int> arr(num);

    for(int i=0;i<num;i++)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end());
    
    int mini = 0;
    int idx = num;
    for(int i=0;i<num;i++)
    {
        mini += arr[i] * idx;
        idx --;
    }
    
    cout << mini << endl;
}
