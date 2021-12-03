#include <stdlib.h>
#include <stdio.h>

typedef struct LINK
{
    char id[5];
    int score;
    struct LINK *link;
} Student;

Student *creat()
{
    char prov_id = 'A';
    Student *A_head = NULL;
    Student *p = NULL;
    p = (Student *)malloc(sizeof(Student));
    if (p == NULL)
        return NULL;
    A_head = p;
    Student *next = NULL;
    int i = 1;
    sprintf(p->id, "%c%d", prov_id, i);
    p->score = rand() % 200 + 400;
    for (int i = 2; i <= 20; i++)
    {
        next = (Student *)malloc(sizeof(Student));
        sprintf(next->id, "%c%d", prov_id, i);
        next->score = rand() % 200 + 400;
        next->link = NULL;
        p->link = next;
        p = next;
    }
    return A_head;
}
void sort(Student *A)
{
    Student *current = NULL;
    Student *end = NULL;
    int temp_int;
    char temp_string[5];
    current = A;
    while (current != end)
    {
        while (current->link != end)
        {
            if (current->score > current->link->score)
            {
                temp_int = current->score;
                current->score = current->link->score;
                current->link->score = temp_int;

                int i = 0;
                while (current->link->id[i] != '\0' || current->id[i])
                {
                    temp_string[i] = current->id[i];
                    current->id[i] = current->link->id[i];
                    current->link->id[i] = temp_string[i];
                    i++;
                }
            }
            current = current->link;
        }
        end = current;
        current = A;
    }
}

void output()
{
    Student *A = creat();
    sort(A);
    for (int i = 1; i <= 20; i++)
    {
        printf("%s\t%d\n", A->id, A->score);
        A = A->link;
    }
}
int main()
{
    output();
    return 0;
}