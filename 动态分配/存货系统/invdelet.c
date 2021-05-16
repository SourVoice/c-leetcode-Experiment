/*释放存货数据*/
#include <stdlib.h>
#include "inventor.h"

void discard_inventory_record(Invrec *record)
{
    /*删除记录中的变体部分*/
    switch (record->type)
    {
    case SUBASSY:
        free(record->info.subssy->part);
        free(record->info.subssy);
        record->info.subssy->part = NULL;
        record->info.subssy = NULL;
        break;
    case PART:
        free(record->info.part);
        record->info.part = NULL;
        break;
    }
    free(record);
    record = NULL;
}