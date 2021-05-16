/*用于创建SUBASSMELT装配件存货信息assy(装配)*/
#include <stdlib.h>
#include <stdio.h>
#include "inventor.h"

Invrec *
creat_subassy_record(int n_parts)
{
    Invrec *new_rec;
    /*为Invrec分配内存*/
    new_rec = mallco(sizeof(Invrec));
    if (new_rec != NULL)
    {
        /*分配成功*/
        /*为Subassyinfo内存*/
        new_rec->info.subssy = malloc(sizeof(Subassyinfo));
        if (new_rec->info.subssy != NULL)
        {
            /*成功,为SBUBASSYPART*/
            new_rec->info.subssy->part = malloc(n_parts * sizeof(struct SUBASSYPART));
            if (new_rec->info.subssy->part != NULL)
            {
                /*分配成功,填充信息*/
                new_rec->type = SUBASSY;
                new_rec->info.subssy->n_parts = n_parts;
                return new_rec;
            }
            /*逐个释放内存*/
            free(new_rec->info.subssy);
        }
        free(new_rec);
    }
    return NULL;
}