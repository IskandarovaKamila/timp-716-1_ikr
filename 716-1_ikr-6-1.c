#include <stdio.h>
#include <stdlib.h>

typedef struct Line{
    int value;
    struct Line *next;
    struct Line *prev;
} Line;

typedef struct OptLine{
    Line *head;
    Line *tail;
} OptLine;

OptLine *InitOptLine(){
    struct Line *tmp;

    tmp = malloc(sizeof(struct Line));
    tmp -> value = -1;
    tmp -> next = NULL;
    tmp -> prev = NULL;

    struct OptLine *tmp1;

    tmp1 = malloc(sizeof(struct OptLine));
    tmp1 -> head = tmp;
    tmp1 -> tail = tmp;

    return tmp1;
}

int isEmptyLine(OptLine *h){
    if ((h -> head -> value == -1))
        return 1;
    else
        return 0;
}

void AddInLine(int a, OptLine *h){
    {
        if (h -> head -> value == -1){
            h -> head -> value = a;
        }
        else        {
            struct Line *tmp = malloc(sizeof(struct Line));
            h -> tail -> next = tmp;
            tmp -> value = a;
            tmp -> prev = h -> tail;
            tmp -> next = NULL;
            h -> tail = tmp;
        }
    }
}

void DeleteLine(OptLine *h){
    if (h -> head != NULL)    {
        Line *tmp = h -> head;
        Line *n = NULL;
        int i = 1;
        for (i; tmp != NULL ; i++){
            n = tmp -> next;
            tmp = NULL;
            tmp = n;
        }
        h -> head = NULL;
        h -> tail = NULL;
        h = NULL;
    }
    else printf("Empty Line\n");
}

void DeleteFirstInLine(OptLine *h){
    for (;;){
    if (h -> head != h -> tail)
    {
        Line *tmp = h -> head;
        h -> head = h -> head -> next;
        h -> head -> prev = NULL;
        free(tmp);
        break;
    }

    if ((h -> head == h -> tail) && (h -> head -> value != -1)){
        h -> head -> value = -1;
        h -> head -> next = NULL;
        h -> head -> prev = NULL;
        break;
    }

    if (isEmptyLine(h) == 1){
        printf("Empty Line\n");
        break;
    }
    }
}

int ShowFirstInLine(OptLine *h){
    if (isEmptyLine(h) == 0){
        int val = h -> head -> value;
        //DeleteFirstInLine(h);
        return val;
    }
    else printf("Empty Line\n");
}

typedef struct BinTree{
    int key;
    int value;
    struct BinTree *left;
    struct BinTree *right;
} BinTree;

typedef struct RootTree{
    BinTree *head;
} RootTree;

RootTree *CreateTree(){
    BinTree *tmp = malloc(sizeof(BinTree));

    tmp -> key = -1;
    tmp -> value = -1;
    tmp -> left = NULL;
    tmp -> right = NULL;

    RootTree *tmp1 = malloc(sizeof(RootTree));

    tmp1 -> head = tmp;

    return tmp1;
}


void AddInBinTree(int a, int b, RootTree *h){
    int tmpKey = h -> head -> key;
    BinTree *tmp = h -> head;

    if (tmpKey == -1){
        tmp -> key = a;
        tmp -> value = b;
    }
    else{
        BinTree *list = malloc(sizeof(BinTree));

        list -> key = a;
        list -> value = b;
        list -> left = NULL;
        list -> right = NULL;

        for (;;){
            if (tmpKey > a){
                if (tmp -> left == NULL){
                    tmp -> left = list;
                    break;
                }
                tmp = tmp -> left;
                tmpKey = tmp -> key;
                continue;
            }

            if (tmpKey < a){
                if (tmp -> right == NULL){
                    tmp -> right = list;
                    break;
                }
                tmp = tmp -> right;
                tmpKey = tmp -> key;
            }
        }
    }
}

BinTree *SearchNodeBinTree(int a, RootTree *h){
    int tmpKey = h -> head -> key;
    BinTree *tmp = h -> head;

    for (;;){
        if (tmpKey == a){
            return tmp;
        }

        if (tmpKey > a){
            tmp = tmp -> left;
            if (tmp == NULL) {return NULL; break;}
            tmpKey = tmp -> key;
            continue;
        }

        if (tmpKey < a){
            tmp = tmp -> right;
            if (tmp == NULL) {return NULL; break;}
            tmpKey = tmp -> key;
            continue;
        }
    }
}

void WidthBinTree(RootTree *h){
    OptLine *Ochered1 = InitOptLine();
    BinTree *tmp = h -> head;

    AddInLine(tmp -> key, Ochered1);

    for(;;){

		if (tmp -> left != NULL)
			AddInLine(tmp -> left -> key, Ochered1);

		if (tmp -> right != NULL)
			AddInLine(tmp -> right -> key, Ochered1);

		printf ("%d ", tmp -> value);

		DeleteFirstInLine(Ochered1);

		if (isEmptyLine(Ochered1) == 1) break;

		tmp = SearchNodeBinTree(ShowFirstInLine(Ochered1), h);
	}

	DeleteLine(Ochered1);
	Ochered1 = NULL;
}

void DeleteTree(RootTree *h){
    BinTree *tmp = NULL;
    BinTree *prev = NULL;

    for (;;){
        prev = NULL;
        tmp = h -> head;

        while (tmp -> left != NULL){
            prev = tmp;
            tmp = tmp -> left;
        }

        while (tmp -> right != NULL){
            prev = tmp;
            tmp = tmp -> right;
        }

        if (prev == NULL){
            free(tmp);
            free(h);
            break;
        }

        if (prev -> left == tmp){
            free(tmp);
            prev -> left = NULL;
            continue;
        }

        if (prev -> right == tmp){
            free(tmp);
            prev -> right = NULL;
            continue;
        }
    }
}


int main(){

    RootTree *BinTree1 = CreateTree();

    int i = 0, key = 0, value = 0, quantity = 0;

    scanf("%d", &quantity);

    for (i; i < quantity; i++){
        scanf("%d %d", &key, &value);
        AddInBinTree(key, value, BinTree1);
    }

    WidthBinTree(BinTree1);

    DeleteTree(BinTree1);
    BinTree1 = NULL;
    printf("\n");
    return 0;
}

