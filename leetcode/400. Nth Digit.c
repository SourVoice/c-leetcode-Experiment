/*400. µÚ N Î»Êý×Ö*/
int findNthDigit(int n)
{
    if (n < 10)
        return n;
    long sum = 0; // rec the total num of the prefix
    long long cnt = 9;
    int digit = 1;
    while (sum <= n)
    {
        sum += digit * cnt;
        digit++;
        cnt *= 10;
    }
    // set the range to
    // digit 1 for 1-9
    // digit 2 for 10-99
    // digit 3 for 100-999
    // so on
    long long numth = pow(10, digit - 2);
    long long diff = n - (sum - (digit - 1) * cnt / 10);
    // printf(" numth = %d digit = %d diff = %d",numth,digit,diff);
    int count = 0;
    while (count < diff)
    {
        numth++;
        count += digit - 1;
    }
    return (numth - 1) / (int)pow(10, count - diff) % 10;
}