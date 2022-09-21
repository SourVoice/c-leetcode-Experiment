// 81. ������ת�������� II
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;
// ������
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n <= 10 && find(begin(nums), end(nums), target) != end(nums))
            return true;
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            while (left < right && nums[left] == nums[left + 1])
                left++;
            while (left < right && nums[right] == nums[right - 1])
                right--;
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
        return false;
    }
};
// ȥ��
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n <= 10 && find(begin(nums), end(nums), target) != end(nums))
            return true;
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int &l = left, &r = right;
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            // ������ nums[l] == nums[mid] ���� nums[r] == nums[mid] ʱ�����޷��ж���һ���������
            if (nums[l] == nums[mid] && nums[mid] == nums[r]) //ȥ��
                ++l, --r;
            else if (nums[mid] < nums[left])
            { //�Ҳ�����
                if (target == nums[right])
                    return right;
                if (target > nums[mid] && target < nums[right]) //�����Ҳ�
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else
            { //�������
                if (target == nums[left])
                    return left;
                if (target < nums[mid] && target > nums[left]) // �������
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return false;
    }
};