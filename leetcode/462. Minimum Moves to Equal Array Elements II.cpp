// 462. �����ƶ�����ʹ����Ԫ����� II

//��ѧ
class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size();
        int mid = nums[j / 2], ant = 0;
        j--;

        while (i <= j)
        {
            ant += (mid - nums[i++]) + (nums[j--] - mid);
        }
        return ant;
    }
};