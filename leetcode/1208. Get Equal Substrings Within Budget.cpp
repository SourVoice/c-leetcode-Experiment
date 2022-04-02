//1208. 尽可能使字符串相等
#include<string>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int sum = 0, ans = 0;
        int n = s.size();
        int left = 0, right = 0;
        for (right = 0;right<n;right++){
               sum+=abs(s[right]-t[right]); 
               if(sum>maxCost){
                   sum-=abs(s[left]-t[left]);
                   left++;
               }
               ans = max(ans,right-left+1);
        }
        return right - left;
    }
};