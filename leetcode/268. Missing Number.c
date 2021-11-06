/*268. ��ʧ������*/
int missingNumber(int *nums, int numsSize)
{
    int range[numsSize + 1];
    for (int i = 0; i <= numsSize; i++)
    {
        range[i] = i;
    }
    for (int i = 0; i < numsSize; i++)
    {
        range[nums[i]] = -1;
    }
    for (int i = 0; i <= numsSize; i++)
    {
        if (range[i] != -1)
            return range[i];
    }
    return 1;
}
int missingNumber_mathWay(int *nums, int numsSize) //��nums[i]�������Խ������,ԭ���з���Ҫ��
{
    int sum = numsSize * (1 + numsSize) / 2;
    for (int i = 0; i < numsSize; i++)
    {
        sum -= nums[i];
    }
    return sum;
}
int missingNumber_XORCode(int *nums, int numsSize) //xor����Ľ����ɺͽ����
{
    int tmp = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        tmp ^= nums[i] ^ i;
    }
    return tmp;
}
