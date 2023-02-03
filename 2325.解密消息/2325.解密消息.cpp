#include<string>
#include<vector>
using namespace std;
int main(void){
    return 0;
}
class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<int> chipperKey;
        string decodedMessage;
        int temp = 0;
        for(int i = 0; i < 26; i++){
            chipperKey.push_back(-1);
        }
        for(string::iterator it = key.begin(); it != key.end(); it++){
            if(chipperKey[*it - 'a'] != -1){
                chipperKey[*it - 'a'] = temp;
                temp++;
            }
        }
        for(int i = 0; i < message.size(); i++){
            decodedMessage.push_back('a' + chipperKey[message[i] - 'a']);
        }
        return decodedMessage;
    }
};