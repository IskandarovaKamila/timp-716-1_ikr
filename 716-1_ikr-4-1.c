#include<stdio.h>
#include<stdlib.h>
typedef struct list{
    int value;
    struct list *right;
    struct list *left;
}list;
list *head=NULL;
list *tail=NULL;

list init (int date){
    list *ptr=(list*)malloc(sizeof(list));
    ptr->value=date;
    ptr->right=NULL;
    ptr->left=NULL;
    head=ptr;
    tail=ptr;
}
int isEmpty(){
    if (head==NULL && tail==NULL)
        return 1;
    else return 0;
}
void insertEnd (int date){
    if (isEmpty()==1)
        init (date);
    else{
        list *ptr=(list*)malloc(sizeof(list));
        ptr->value=date;
        ptr->right=NULL;
        ptr->left=tail;
        tail=ptr;
        ptr->left->right=ptr;
    }
}
void insertList(){
    list *ptr=head;
    while (ptr!=NULL){
        printf ("%d ", ptr->value);
        ptr=ptr->right;
    }
}
int delit(){
    if (isEmpty())
    {return 0;}
    list *ptr=head;
    if (ptr==tail){
        head=NULL;
        tail=NULL;
        free(ptr);
        return 1;
    }
    list *ptr1=NULL;
    ptr1=ptr->right;
    free(ptr);
    head=ptr1;
    return 1;
}
int main(){
    int k, date;
    scanf("%d", &k);
    scanf("%d", &date);
    init(date);
    for(int i=0;i<k-1;i++){
        scanf ("%d", &date);
        insertEnd(date);
    }
    insertList();
    printf ("\n");

    for (int i=0;i<k;i++){
        delit();
        insertList();
        printf("\n");
    }
    return 0;
}
