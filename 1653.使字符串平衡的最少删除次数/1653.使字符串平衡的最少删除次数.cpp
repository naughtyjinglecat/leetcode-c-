#include<string>
using namespace std;



class Solution {
public:
    int minimumDeletions(string s) {
        int b = 0;//统计出现了多少个b
        int count = 0;//统计一共出现了多少个ba序列
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'b'){
                b++;//出现了b则b的可用数量加1
            }
            else{
                if(b > 0){
                    b--;//遇到了a之后检查变量b是否可以构成ba序列，构成了则消耗一个‘b’
                    count++;//ba序列数量加1
                }
            }
        }
        return count;
    }
};