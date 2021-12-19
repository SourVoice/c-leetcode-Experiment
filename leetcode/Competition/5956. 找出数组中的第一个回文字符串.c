int check(char *word)
{
    int len = strlen(word);
    for (int i = 0, j = len - 1; i != j; i++, j--)
    {
        if (word[i] != word[j])
            return 0;
        if (i + 1 == j)
            return 1;
    }
    return 1;
}
char *firstPalindrome(char **words, int wordsSize)
{
    for (int i = 0; i < wordsSize; i++)
    {
        if (check(words[i]))
            return words[i];
    }
    return "";
}