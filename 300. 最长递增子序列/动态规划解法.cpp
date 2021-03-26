#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.resize(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++){
            int maxLen = 1;
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i]){
                    int tmpLen = dp[j] + 1;
                    maxLen = maxLen > tmpLen ? maxLen : tmpLen;
                }
            }
            dp[i] = maxLen;
        }
        return *max_element(dp.begin(), dp.end());
    }
};