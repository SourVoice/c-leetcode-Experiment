// 540. ���������еĵ�һԪ��

//���ֶ�+λ����
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == nums[mid ^ 1]) // mid is odd:mid^1 = mid-1; mid is even:mid^1 = mid+1
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return nums[low];
    }
};

//ֱ�����������������
class Solution2
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int ans = 0;
        for (auto &num : nums)
            ans ^= num;
        return ans;
    }
};