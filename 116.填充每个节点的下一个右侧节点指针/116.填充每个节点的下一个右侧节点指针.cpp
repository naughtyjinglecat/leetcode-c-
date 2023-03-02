#include <iostream>
#include <cstring>
#include <vector>
#include <vector>
#include <map>
#include<algorithm>
#include <set>
#include <queue>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> Q;
        Node *p, *pre = NULL;
        int i = 0;
        int pos = 0;
        if(root != NULL){
            Q.push(root);
            pos = 0;
        }
        while(!Q.empty()){
            p = Q.front();
            i++;
            Q.pop();
            if(p->left != NULL){
                Q.push(p->left);
                Q.push(p->right);
            }
            if(i == 2 * pos + 1){
                p->next = NULL;
                pos = i;
                if(pre != NULL){
                    pre->next = p;
                    pre = NULL;
                }
            }
            else{
                if(pre != NULL){
                    pre->next = p;
                    pre = p;
                }
                else{
                    pre = p;
                }
            }
        }
        return root;
    }
};