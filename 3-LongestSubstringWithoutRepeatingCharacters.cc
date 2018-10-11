// Given a string, find the length of the longest substring without repeating characters.

// Example 1:
// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 
//
// Example 2:
// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
//
// Example 3:
// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 
//              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.



//situation1: 没有重复，asd
//situation2: 重复的选项是第二个以后开始，dvdf
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std; 

class Solution {
public:
int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (string::size_type i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};
// wrong
class Solution1 {
public:
    int lengthOfLongestSubstring(std::string s) {
        if(s.empty()) return 0;
        int cur = 0;
        int count = 0;
        int flag = false;
        int max = 0;
        std::string tmp;
        int size = s.size();

        while(cur < size){
            if(tmp.empty()){
                tmp += s[cur];
                ++ count;
            }
            else{
                flag = false;
                for(std::string::size_type i = 0; i < tmp.size(); ++ i){
                    if(tmp[i] == s[cur]){
                        max = max > count ? max : count;
                        count = 0;
                        flag = true;
                        tmp = s[i+1];
                        cur = i;
                        break;
                    }
                }
                if(!flag){
                    tmp += s[cur];
                }
                ++ count;
            }
            ++ cur;
        }
        return max > count ? max : count;
    }
};
