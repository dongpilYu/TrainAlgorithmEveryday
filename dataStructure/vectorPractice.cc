/*
    벡터는 요소가 삽입되거나 삭제될 때 저장소가
    컨테이너에 의해 자동적으로 다뤄진 채로 
    자동으로 리사이즈할 수 있는 동적 배열과 같다.
    벡터의 요소는 연속적으로 저장되므로 요소들은
    iterator를 통해 접근 또는 순회할 수 있다.
    벡터에서 데이터는 맨 뒤에 삽입되는데 삽입될 때
    배열을 확장하는 시간이 필요할 수 있으므로 시간이
    때때로 다르다. 삭제하는 것은 상수 시간이 걸린다.
    중간에 있는 요소를 삭제하거나 삽입하는 것은 선형
    시간이 소요된다.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> g1;

    for (int i = 0; i <= 5; i++)
        g1.push_back(i);
    cout << "output of begin and end: ";
    for (auto i = g1.begin(); i != g1.end(); i++)
        cout << *i << " ";

    cout << "\nOutput of cbegin and cend: ";
    for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
        cout << *ir << " ";

    cout << "\nOutput of crbegin and crend: ";
    for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
        cout << *ir << " ";
}
