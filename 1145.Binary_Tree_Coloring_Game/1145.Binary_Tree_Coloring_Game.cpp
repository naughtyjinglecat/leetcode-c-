#include<string>
#include<vector>
#include<queue>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


int main(void){
    return 0;
}


class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int n1, n2, n3;
        TreeNode *player2 = find(root, x);
        n1 = count(player2->left);
        n2 = count(player2->right);
        n3 = n - n1 - n2 - 1;
        if(n1*2 > n || n2*2 > n || n3*2 > n){
            return true;
        }
        return false;
    }
    int count(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        else{
            return count(root->left) + count(root->right) + 1;
        }
    }
    TreeNode* find(TreeNode *root, int n){
        queue<TreeNode*> Q;
        TreeNode *temp;
        if(root != NULL){
            Q.push(root);
        }
        while(!Q.empty()){
            temp = Q.front();
            Q.pop();
            if(temp->val == n){
                return temp;
            }
            if(temp->left != NULL){
                Q.push(temp->left);
            }
            if(temp->right != NULL){
                Q.push(temp->right);
            }
        }
        return NULL;
    }
};