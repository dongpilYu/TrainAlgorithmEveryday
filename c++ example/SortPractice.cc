/*
    1. 정의
    알고리즘 헤더파일에서 제공하는 STL, 범위내에서 
    원소들을 정렬한다. 오름차순, 내림차순, 사용자 정의
    숫자, 문자, 대소 비교 가능한 모든 원소에 대해 정렬
    클래스 객체의 경우 연산자 오버로딩 혹은 compare function을
    구현하면 정렬 가능하다.

    2. 사용법
    template <class RandomAccessIterator>
        void sort(RandomAccessIterator first, RandomAccessIterator last);
    template <class RandomAccessIterator>
        void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Person{
    public:
        string name;
        int age;
        Person(string name, int age)
        {
            this->name = name;
            this->age = age;
        }
        /*
        bool operator < (const Person& a) const
        {
            return this->age < a.age;
        }
        */
       // 
};

bool cmp(const Person& a, const Person& b)
{
    return a.name < b.name;
    // 내림 차순
    
}

bool operator < (const Person& a, const Person& b)
{
    return a.age < b.age;
}

int main()
{
    /*
    int arr[5];
    arr[0] = 0;
    arr[1] = 4;
    arr[2] = 5;
    arr[3] = 2;

    for(int i=0;i<4;i++)
        cout << arr[i] << endl;
    
    sort(arr, arr+4, greater<int>());

    for(int i=0;i<4;i++)
        cout << arr[i] << endl;
    */

    vector<Person> v;
    v.push_back(Person("MinJi", 22));
    v.push_back(Person("Kangho", 28));
    v.push_back(Person("Minho", 26));
    v.push_back(Person("Strange Yun", 25));
    sort(v.begin(), v.end());

    for (int i=0; i<v.size(); i++)
        cout<<v[i].age<<", "<<v[i].name<<endl;

    return 0;
}
