// 167. ����֮�� II - ������������
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
//˫ָ��
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        for (int i = 0, j = n - 1; i < j;)
        {
            int sum = numbers[i] + numbers[j];
            if (sum == target)
                return vector<int>{i + 1, j + 1};
            else if (sum < target)
                i++;
            else
                j--;
        }
        return vector<int>{};
    }
};