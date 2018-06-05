#include <stdio.h>
#include <stdlib.h>

typedef struct node {
        int key;
        int value;
        struct node *left;                      //меньше
        struct node *right;                     //больше
} node;
typedef node* list;

int init(list *root){                           //инициализация
        *root = NULL;
        return 1;
}

list getFreeNode(int value, int key) {
        list tmp = (list) malloc(sizeof(node));
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->value = value;
        tmp->key = key;
        return tmp;
}

void insert(list *root, int key, int value) {
        node *tmp = NULL;
        if (*root == NULL) {                            //если дерево пустое
                *root = getFreeNode(value, key);
                return;
        }

        tmp = *root;
        while (tmp) {
                if (key > tmp->key) {                   //Если значение больше, чем значение текущего узла
                        if (tmp->right) {               //Если при этом правый узел не пустой, то за корень теперь считаем правую ветвь и начинаем цикл сначала
                                tmp = tmp->right;
                                continue;
                        }
                        else {                          //Если правой ветви нет, то вставляем узел справа
                            tmp->right = getFreeNode(value, key);
                            return;
                        }
                }
                else if (key < tmp->key) {              //То же самое с левой ветвью
                        if (tmp->left) {
                                tmp = tmp->left;
                                continue;
                        }
                        else {
                            tmp->left = getFreeNode(value, key);
                            return;
                        }
                } else exit(2);
        }
}

list search(list *root, int key){
        int levl=-1;
        int znach=0;
        list tmp = NULL;
        tmp = *root;
        while(tmp){
                if(key < tmp->key){
                    if(tmp->left!=NULL){
                            tmp = tmp->left;
                            levl++;
                            continue;
                    }
                    if(tmp->left==NULL && key<tmp->key) {
                            printf("-1\n");
                            return tmp;
                    }
                }
                if(key > tmp->key){
                        if(tmp->right!=NULL){
                                tmp = tmp->right;
                                levl++;
                                continue;
                        }
                        if(tmp->right==NULL && key>tmp->key) {
                                printf("-1\n");
                                return tmp;
                        }
                }
                if(key == tmp->key){
                        znach=(tmp)->value;
                        printf(" %d %d\n",levl+1,znach);
                        return tmp;
                }
        }
        return NULL;
}

int main() {
        list root;
        init(&root);
        int n, a, b, e, f, g;

        scanf("%d", &n);                            //заполнение дерева
        if (n > 0) {
            for(int i=0;i<n;i++){
                scanf("%d%d", &a, &b);
                insert(&root,a,b);
            }
        }
        printf("\n");

        scanf("%d%d%d",&e, &f, &g);                 //поиск по ключам
        search(&root,e);
        search(&root,f);
        search(&root,g);
        printf("\n");

        return 0;
}

