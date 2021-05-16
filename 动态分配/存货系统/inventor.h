/*创建存货记录*/

/*零件信息的结构*/
typedef struct
{
    int cost;
    int supplier;
} Partinfo;
/*零配件专用信息*/
typedef struct
{
    int n_parts;
    struct SUBASSYPART
    {
        char partno[10];
        short quan;
    } * part;

} Subassyinfo;
/*存货记录*/
typedef struct
{
    char partno[10];
    int quan;
    enum
    {
        PART,
        SUBASSY
    } type;
    union
    {
        Partinfo *part;
        Subassyinfo *subssy;
    } info;
} Invrec;