/*���ݿ���*/
int bulbSwitch(int n)
{
    int count = 0;
    for (int i = 1; i * i <= n; i++)
    {
        count++;
    }
    return count;
}
//��n���ڵ���ȫƽ�����ĸ���,
//ֻ����ȫƽ����������Ϊ����,����Ϊ��