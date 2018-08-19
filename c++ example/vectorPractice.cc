#include <iostream>
#include <vector>
using namespace std;

/*
    https://www.acmicpc.net/board/view/23961(����)�� ������
    ������ �ɼ����� Optimization flag�� ������ STL�� �� ������.
    c++ �����Ϸ� �ɼ��� �پ��ϴ�.

    vector �����̳ʴ� ��ǥ���� ������ �����̳ʷ� �迭�� ����ϸ�
    ����� ����� ���� ���ȴ�. vector�� ���� ���� �ݺ��ڸ� �����ϴ�
    �迭 ��� �����̳��̴�. ���� ū Ư¡ �� �ϳ��� ���Ұ� �ϳ���
    �޸� ��Ͽ� �����ϰ� ����ȴٴ� ��. �׷��� ���� ���Ұ� �߰��� ��
    �޸� ���Ҵ��� �߻��� �� �ְ�, ����� ����� �䱸�ȴ�. 
    �׷��� �޸� �Ҵ� ũ�⸦ �� �� �ְ� capacity() �Լ��� �����ϸ�
    �ѹ��� �޸𸮸� �Ҵ��� �� �ִ� reserve() �Լ��� �����ȴ�.

    ���Ұ� �����ϰ� ����ǹǷ� 
*/

int main()
{
    vector<int> v;
    v.reserve(8);

    int a[8] = {10,20,30,40,50};

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    // std::vector�� �ε����� ����
    for(vector<int>::size_type i=0; i<v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
    // std::vector�� iterator�� ����
    for(vector<int>::iterator it=v.begin(); it != v.end(); it++)
        cout << *it << ' ' ;
    cout << endl;
    // �迭�� �ε����� ����
    for(size_t i=0; i!=(sizeof a/sizeof *a); i++)
        cout << a[i] << ' ' ;
    cout << endl;
    // �迭�� iterator�� ����

    for(int* it = a; it != (a + sizeof(a) / sizeof(*a)); it++)
        cout << *it << ' ';
    cout << endl;
}
