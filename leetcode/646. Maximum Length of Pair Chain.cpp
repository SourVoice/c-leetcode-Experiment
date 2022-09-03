// 646. 最长数对链
#include <stack>
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
// 动态规划
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b){return  a[0]  < b[0];});
        vector<int> dp(n, 1);//第i组结尾时能够形成的最长数对链
        for(int i = 0; i < n; i++){
            for(int j  = 0; j < i;j++){
                if(pairs[i][0] > pairs[j][1]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};
// 贪心 https://leetcode.cn/problems/maximum-length-of-pair-chain/solution/zui-chang-shu-dui-lian-by-leetcode-solut-ifpn/1735955
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b){return  a[1]  < b[1];});
        int ans = 0, cur = INT_MIN;
        for(auto &pair:pairs){
            if(cur < pair[0]){
                ans++;
                cur =  pair[1];
            }
        }
        return ans;
    }
};