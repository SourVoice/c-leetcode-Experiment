```c
struct LinkList{
    int val;
    struct LinkList*next;
};
void delet(struct LinkList**rootp,int targetVal){
    struct LinkList*curr = (struct LinkList*)malloc(sizeof(struct LinkList));
    curr = *rootp;
    while(curr){
        if(curr->val==targetVal){
            *rootp = curr->next;
            free(curr);
            curr = *rootp;
            continue;
        }
        rootp = &curr->next;
        curr = curr->next;
    }
}

```
