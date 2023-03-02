#include <stack>
#include <vector>
using namespace std;


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int k = 0;
        int j = 0;
        stack<int> S;
        if(pushed.size() != popped.size()){
            return false;
        }
        for(int i = 0; i < (int)pushed.size()*2; i++){
            if(S.empty()){
                
                S.push(pushed[k]);
                k++;
            }
            else{
                if(S.top() == popped[j]){
                    j++;
                    S.pop();
                }
                else if(k < (int)(pushed.size())){
                    S.push(pushed[k]);
                    k++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};