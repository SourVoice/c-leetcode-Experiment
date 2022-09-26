// 1508. ������������������
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;
// ģ��
class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        int mod = 1e9 + 7;
        int sumsLenth = (n + 1) * n / 2;
        vector<int> sums;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
                sum += nums[j], sums.push_back(sum);
        }
        sort(begin(sums), end(sums));
        int ret = 0;
        for (int i = left - 1; i < right; i++)
            ret = (ret + sums[i]) % mod;
        return ret % mod;
    }
};
// ǰ׺��+����
class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        this->n = n;
        vector<int> prefixOfnums(n + 1, 0);
        prefixOfnums[1] = nums[0];
        for (int i = 2; i <= n; i++)
            prefixOfnums[i] = nums[i - 1] + prefixOfnums[i - 1];
        vector<int> prefixOfprefixOfnums(n + 1, 0);
        prefixOfprefixOfnums[1] = prefixOfnums[1];
        for (int i = 2; i <= n; i++)
            prefixOfprefixOfnums[i] = prefixOfnums[i] + prefixOfprefixOfnums[i - 1];
        for (int i = 0; i <= n; i++)
            cout << prefixOfnums[i] << " ";
        cout << endl;
        for (int i = 0; i <= n; i++)
            cout << prefixOfprefixOfnums[i] << " ";
        // ��left - 1����������͵ĺ�
        int l = getSumOfPrefixOfperfixOfnums(prefixOfnums, prefixOfprefixOfnums, left - 1);
        // ��right����������͵ĺ�
        int r = getSumOfPrefixOfperfixOfnums(prefixOfnums, prefixOfprefixOfnums, right);

        return r - l;
    }
    // ��������͵���С��ǰk����
    int getSumOfPrefixOfperfixOfnums(vector<int> &prefixOfnums, vector<int> &prefixOfprefixOfnums, int k)
    {
        int num = getKthMinElemAmoungPrefixOfnums(prefixOfnums, k);
        cout << endl
             << num;
        int sum = 0;
        int cnt = 0;
        for (int i = 0, j = 1; i < n; i++)
        {
            while (j <= n && prefixOfnums[j] - prefixOfnums[i] < num)
                j++;
            j--;
            // TODO:ûŪ��, Ҫ��ȥprefixOfnums[i]����ֻ����Ϊǰ׺�ʹ���һλ
            sum += prefixOfprefixOfnums[j] - prefixOfprefixOfnums[i] - prefixOfnums[i] * (j - i);
            sum %= mod;
            cnt += j - i;
        }
        // cnt Ϊ�ϸ�С��num�� ������͵ĸ���
        // �����ϵ���num����
        return sum + (k - cnt) * num;
    }
    // �õ������������е�k����С��Ԫ��
    int getKthMinElemAmoungPrefixOfnums(vector<int> &prefixOfnums, int k)
    {
        int l = 0, r = prefixOfnums[n]; // range among [0, prefixOfnums[n-1]]
        auto getCount = [&](const int &guess) -> int
        {
            int count = 0;
            for (int i = 0, j = 1; i < n; i++)
            {
                while (j <= n && prefixOfnums[j] - prefixOfnums[i] <= guess)
                    j++;
                j--;
                count += j - i; // begin with i, end among i + 1 to j could be acceped subarray
            }
            return count;
        };
        while (l < r)
        {
            int mid = (l + r) / 2;
            int count = getCount(mid); // count����Ϊ�ж��ٸ�������ĺ�û�г���mid(�²�ֵ)
            if (count < k)             // ��k����С�������λ�ڴ���mid��, С��mid��������͵���������k��
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }

private:
    int n; // Array size, both for prefixOfnums and prefixOfprefixOfnums
    int mod = 1e9 + 7;
};
