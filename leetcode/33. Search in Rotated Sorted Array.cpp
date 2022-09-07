// 33. ������ת��������
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;
// ���ֲ���
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < nums[left])
            { //�Ҳ�����
                if (target == nums[right])
                    return right;
                if (target > nums[mid] && target < nums[right])
                { //�����Ҳ�
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }
            else
            { //�������
                if (target == nums[left])
                    return left;
                if (target < nums[mid] && target > nums[left])
                { // �������
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }
        }
        return -1;
    }
};