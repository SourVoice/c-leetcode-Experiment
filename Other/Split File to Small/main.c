#include <stdio.h>

int main()
{
    FILE *p_ReadFile;
    FILE *p_WriteFile;
    char line[128]; // linesize
    char fileOutPutName[15];
    int fileCounter = 1, lineCounter = 1;

    p_ReadFile = fopen("test.txt", "r");
    if (!p_ReadFile)
        return 1;

    sprintf(fileOutPutName, "file_part%d", fileCounter);
    p_WriteFile = fopen(fileOutPutName, "w");

    while (fgets(line, sizeof line, p_ReadFile) != NULL)
    {
        if (lineCounter == 5)
        {
            fclose(p_WriteFile);
            lineCounter = 1;
            fileCounter++;
            sprintf(fileOutPutName, "file_part%d", fileCounter);
            p_WriteFile = fopen(fileOutPutName, "w");
            if (!p_WriteFile)
                return 1;
        }
        fprintf(p_WriteFile, "%s\n", line);
        lineCounter++;
    }
    fclose(p_ReadFile);
    return 0;
}
