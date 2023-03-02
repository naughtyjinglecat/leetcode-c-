#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int curdistance, mindistance;
        int ifinal = 0, jfinal = 2, kfinal = 1;
        sort(nums.begin(), nums.end());
        mindistance = abs(nums[0] + nums[1] + nums[2] - target);
        int i = 0, j = (int)nums.size() - 1, k = 1;
        for(i = 0; i < (int)nums.size() - 2; i++){
            j = (int)nums.size() - 1;
            k = i + 1;
            while(k < j){
                curdistance = abs(nums[i] + nums[k] + nums[j] - target);
                if(curdistance < mindistance){
                    mindistance = curdistance;
                    ifinal = i;
                    jfinal = j;
                    kfinal = k;
                }
                if(nums[i] + nums[k] + nums[j] < target){
                    k++;
                }
                else if(nums[i] + nums[k] + nums[j] == target){
                    return nums[i] + nums[k] + nums[j];
                }
                else{
                    j--;
                }
            }
        }
    return nums[ifinal] + nums[jfinal] + nums[kfinal];
    }
};