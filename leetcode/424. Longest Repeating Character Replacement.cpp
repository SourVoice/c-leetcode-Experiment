// 424. 替换后的最长重复字符
#include <string>
#include <functional>
#include <set>
#include<vector>
using namespace std;
//滑动窗口
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        function<int(string, int, char)> helper = [](string s, int k, int ch)
        {
            int n = s.size();
            int ans = 0, left = 0, right = 0;
            int sum = 0;
            for (int right = 0; right < n; right++)
            {
                sum += s[right] == ch ? 1 : 0;
                while (sum > k)
                {
                    sum -= s[left++] == ch ? 1 : 0;
                }
                ans = max(ans, right - left + 1);
            }
            return ans;
        };
        set<char> st;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (st.count(s[i]))
            {
                continue;
            }
            st.insert(s[i]);
            ans = max(ans, helper(s, k, s[i]));
        }
        return ans;
    }
};


// 滑动窗口2
class Solution2{
    public:
    int characterReplacement(string s, int k){
        int n = s.size();
        int left = 0,right = 0;
        vector<int> num(26,0);
        int sum = 0;
        for (right = 0; right < n;right++){
            num[s[right] - 'A']++;
            sum  = max(sum, num[s[right] - 'A']);
            if(right-left+1 - sum > k) {
                num[s[left] - 'A']--;
                left++;
            }
        }
        return right - left;
    }
};