#include <iostream>
#include <cstring>
#include <vector>
#include <vector>
#include <map>
#include<algorithm>
#include <set>
#include <queue>
using namespace std;

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
};

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

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> Q;
        Node *p, *pre = NULL;
        int thisfloor = 0, nextfloor = 0, allthisFloor = 1;
        if(root != NULL){
            Q.push(root);
        }
        while(!Q.empty()){
            p = Q.front();
            Q.pop();
            if(p->left != NULL){
                Q.push(p->left);
                nextfloor++;
            }
            if(p->right != NULL){
                Q.push(p->right);
                nextfloor++;
            }
            if(pre != NULL){
                pre->next = p;
            }
            pre = p;
            thisfloor++;
            if(thisfloor == allthisFloor){
                pre = NULL;
                p->next = NULL;
                allthisFloor = nextfloor;
                nextfloor = 0;
                thisfloor = 0;
            }
        }
        return root;
    }
};