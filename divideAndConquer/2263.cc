/*
    Traing algorithm everyday
    2018-08-29
    
    ���� ����(Ʈ���� ��ȸ)
    N���� ������ ������ ���� Ʈ���� ������ 1���� N���� ��ȣ�� �ߺ����� �Ű���
   �ִ�. �� ���� Ʈ���� in-order, post-order�� �־����� ��, pre-order�� ���ϴ�
   ����

    pre-order : root left right
    in-order : left root right
    post-order : left right root
*/

#include <iostream>
#include <vector>
using namespace std;

void makeTree(vector<int> in, vector<int> post)
{
    int root = post.back();

    for (vector<int>::iterator i = in.begin(); i != in.end(); ++i)
    {
        if (root == *i)
        {
            vector<int> nextIn;
            vector<int> nextPost;
            makeTree(nextIn.assign(in.begin(), *i), post);
        }
    }
}
int main()
{
    int treeSize;
    cin >> treeSize;

    vector<int> post(treeSize);
    vector<int> in(treeSize);
    vector<int> pre(treeSize);

    for (int i = 0; i < treeSize; i++)
        cin >> in[i];
    for (int i = 0; i < treeSize; i++)
        cin >> post[i];

    makeTree(in, post);
}
