#include <string>
#include <vector>
#include <functional>
using namespace std;
//»¬¶¯´°¿Ú,Ë«Ö¸Õë
class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        function<int(string, int, char)> helper = [](string s, int k, char c)
        {
            int n = s.size();
            int left = 0, right = 0;
            int ans = 0, sum = 0;
            for (int right = 0; right < n; right++)
            {
                sum += s[right] != c ? 1 : 0;
                while (sum > k)
                {
                    sum -= s[left++] != c ? 1 : 0;
                }
                ans = max(ans, right - left + 1);
            }
            return ans;
        };
        return max(helper(answerKey, k, 'T'), helper(answerKey, k, 'F'));
    }

};