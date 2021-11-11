#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define isAlpha(a) ((a >= 'a' && a <= 'z') || (a <= 'Z' && a >= 'A'))
int main()
{

    char *wrd[256];
    char buffer[10000];
    int n, m, i, j, k = 0, line;

    for (int i = 0; i < 256; i++)
        wrd[i] = (char *)malloc(sizeof(char) * 256);

    FILE *fp = NULL;
    fp = fopen("test.txt", "r"); // open file

    printf("Enter the words you want to search in the file and press ctrl+Z( ^Z ) to end input: \n");
    while (gets(wrd[k++]))
    {
    }
    int *count = (int *)malloc(sizeof(int) * (--k));
    memset(count, 0, k);
    for (int i = 0; i < k; i++)
    {
        count[i] = 0;
    }

    line = 0;
    // the following loop the file fp line by line
    // each line is stored in buffer
    while (fgets(buffer, 10000, fp) != NULL)
    {

        i = 0;
        n = strlen(buffer);
        // the followinf loop find position of the input word in the current line and
        // print the position of the word on the screen
        // the loop basically reads each word of the file and compare it with the input word
        while (i < n)
        {

            // comparing current word with input word
            for (int index = 0; index < k; index++)
            {
                char *word = wrd[index];
                j = 0;
                m = strlen(word); // length of input word
                while (i < n && j < m && buffer[i] == word[j])
                {
                    ++i, ++j;
                }

                // the following condition implies that the current word of buffer
                // is equal to input word
                if ((i == n || buffer[i] == '\n' || !isAlpha(buffer[i])) && j == m)
                {
                    printf("target word: %s ", word);
                    printf("Line: %d ", line);
                    printf("Column: %d ", i - m);
                    for (int r = i - m - 1; r <= i; r++)
                    {
                        printf("%c", buffer[r]);
                    }
                    printf("\n");
                    count[index]++;
                }
            }

            // moving to next word
            while (i < n && buffer[i] != ' ')
            {
                ++i;
            }
            ++i;
            while (!isAlpha(buffer[i]))
                ++i;
        }

        ++line;
    }
    for (int i = 0; i < k; i++)
        printf("there's %d \"%s\" in the file   \n", count[i], wrd[i]);
    fclose(fp);
}