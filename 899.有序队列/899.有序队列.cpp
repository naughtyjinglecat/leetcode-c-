#include<vector>
#include<string>
#include<algorithm>
using namespace std;


class Solution {
public:
    string orderlyQueue(string s, int k) {
        vector<int> temp;
        string str1, str2;
        char min;
        if(k >= 2){
            sort(s.begin(), s.end());
        }
        else{
            temp.push_back(0);
            min = s[0];
            for(int i = 1; i < (int)s.size(); i++){
                if(s[i] < min){
                    temp.clear();
                    min = s[i];
                    temp.push_back(i);
                }
                else if(s[i] == min){
                    temp.push_back(i);
                }
            }
            str1 = s.substr(temp[0], s.size() - (temp[0])) + s.substr(0, temp[0]);
            for(int i = 1; i < (int)temp.size(); i++){
                str2 = s.substr(temp[i], s.size() - (temp[i])) + s.substr(0, temp[i]);
                if(str1 > str2){
                    str1 = str2;
                }
            }
            s = str1;
        }
        return s;
    }
};