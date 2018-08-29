/*
    Traing algorithm everyday
    2018-08-29
    
    분할 정복(트리의 순회)
    N개의 정점을 가지는 이진 트리의 정점에 1부터 N까지 번호가 중복없이 매겨져
   있다. 이 이진 트리의 in-order, post-order가 주어졌을 때, pre-order를 구하는
   문제

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
