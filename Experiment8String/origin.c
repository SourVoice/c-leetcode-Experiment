#include <stdio.h>
#include <string.h>

int main()
{

    char wrd[256], buffer[10000];
    int n, m, i, j, line;
    int count = 0;

    FILE *fp;
    fp = fopen("test.txt", "r"); // open file

    printf("Enter the word you want to search in the file: ");
    gets(wrd);

    m = strlen(wrd); // length of input word

    printf("All positions of word \"%s\" in the file\n", wrd);

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
            j = 0;
            while (i < n && j < m && buffer[i] == wrd[j])
            {
                ++i, ++j;
            }

            // the following condition implies that the current word of buffer
            // is equal to input word
            if ((i == n || buffer[i] == ' ' || buffer[i] == '\n') && j == m)
            {
                printf("Line: %d ", line);
                printf("Column: %d\n", i - m);
                count++;
            }

            // moving to next word
            while (i < n && buffer[i] != ' ')
            {
                ++i;
            }
            ++i;
        }

        ++line;
    }
    printf("there's %d \"%s\" in the file", count, wrd);
    fclose(fp);
}