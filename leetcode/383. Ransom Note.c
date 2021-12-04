/*383.Êê½ğĞÅ*/
#define bool int
#define false 0
#define true 1
#define max(a, b) a < b ? b : a

bool canConstruct(char *ransomNote, char *magazine)
{
    int poolM[26] = {0};
    int poolR[26] = {0};

    memset(poolM, 0, sizeof(int) * 26);
    memset(poolR, 0, sizeof(int) * 26);

    for (int i = 0; i < strlen(magazine); i++)
    {
        poolM[magazine[i] - 'a']++;
    }
    for (int i = 0; i < strlen(ransomNote); i++)
    {
        poolR[ransomNote[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (poolR[i] > poolM[i])
            return false;
    }
    return true;
}