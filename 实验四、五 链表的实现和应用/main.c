#include <stdio.h>
struct h
{
    int coaf;
    int c;
    struct h *next;
};

void AddPolyn(struct h *ha, struct h *hb)
{
    struct h *hc = NULL;
    if (ha->coaf)
    {
        hc->next = ha;
    }
    if (ha)
        ha->next = hb;
    if (!ha && !hb)
        hc->next = NULL; //����pbͷ�ڵ�
    free(pb);
}