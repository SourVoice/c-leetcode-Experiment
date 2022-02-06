// 1748. 唯一元素的和

class Solution
{
public:
    int sumOfUnique(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto &i : nums)
        {
            mp[i]++;
        }
        int ans = 0;
        for (auto &i : nums)
        {
            if (mp[i] == 1)
            {
                ans += i;
            }
        }
        return ans;
    }
};

//一次遍历
class Solution2
{
public:
    int sumOfUnique(vector<int> &nums)
    {
        unordered_map<int, int> state;
        int sum = 0;
        for (auto &num : nums)
        {
            state[num]++;
            if (state[num] == 1)
            {
                sum += num;
            }
            if (state[num] == 2)
            {
                sum -= num;
            }
        }
        return sum;
    }
};