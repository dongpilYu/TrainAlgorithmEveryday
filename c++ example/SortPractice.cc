/*
    1. ����
    �˰��� ������Ͽ��� �����ϴ� STL, ���������� 
    ���ҵ��� �����Ѵ�. ��������, ��������, ����� ����
    ����, ����, ��� �� ������ ��� ���ҿ� ���� ����
    Ŭ���� ��ü�� ��� ������ �����ε� Ȥ�� compare function��
    �����ϸ� ���� �����ϴ�.

    2. ����
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
    // ���� ����
    
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
