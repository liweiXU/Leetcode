class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> frequency;
        for (char ch : s){
            ++frequency[ch];
        }
        for (int i = 0; i < s.size(); i++){
            if (frequency[s[i]] == 1){
                return s[i];
            }
        }
        return ' ';
    }
};