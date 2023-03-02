#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> temp;
        for(int i = 0; i < (int)nums.size(); i++){
            if(nums[i] != val){
                temp.emplace_back(nums[i]);
            }
        }
        nums = temp;
        return (int)nums.size();
    }
};