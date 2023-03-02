#include <vector>
using namespace std;


class Solution {
public:
    int first(vector<vector<int>>& people){
        int ans = -1;
        vector<int> people1;
        for(int i = 0; i < (int)people.size(); i++){
            if(people[i][1] == 0){
                people1.emplace_back(i);
            }
        }
        for(int i = 0; i < (int)people1.size(); i++){
            if(ans == -1){
                ans = people1[0];
            }
            else{
                if(people[ans][0] >= people[people1[i]][0]){
                    ans = people1[i];
                }
            }
        }
        for(int i = 0; i < (int)people.size(); i++){
            if(ans != i){
                if(people[ans][0] >= people[i][0] && people[i][1] > 0){
                    people[i][1]--;
                }
            }
        }
        people[ans][1] = -1;
        return ans;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        int k;
        vector<vector<int>> temp = people;
        for(int i = 0; i < (int)people.size(); i++){
            k = first(temp);
            ans.emplace_back(people[k]);
        }
        return ans;
    }
};