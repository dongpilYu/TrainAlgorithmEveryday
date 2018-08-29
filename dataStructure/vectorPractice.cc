/*
    ���ʹ� ��Ұ� ���Եǰų� ������ �� ����Ұ�
    �����̳ʿ� ���� �ڵ������� �ٷ��� ä�� 
    �ڵ����� ���������� �� �ִ� ���� �迭�� ����.
    ������ ��Ҵ� ���������� ����ǹǷ� ��ҵ���
    iterator�� ���� ���� �Ǵ� ��ȸ�� �� �ִ�.
    ���Ϳ��� �����ʹ� �� �ڿ� ���ԵǴµ� ���Ե� ��
    �迭�� Ȯ���ϴ� �ð��� �ʿ��� �� �����Ƿ� �ð���
    ������ �ٸ���. �����ϴ� ���� ��� �ð��� �ɸ���.
    �߰��� �ִ� ��Ҹ� �����ϰų� �����ϴ� ���� ����
    �ð��� �ҿ�ȴ�.
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
