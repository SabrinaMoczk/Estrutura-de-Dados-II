/* Nome: Sabrina Moczulski
Disclina: Estruturas de Dados II
Matrícula: 1611100045
Email: sabrina.moczulski@gmail.com */

#include <stdio.h>
#include <stdlib.h>
 
struct node{
    int key;
    struct node *l;
    struct node *r;
}*root = NULL, *temp = NULL, *t2, *t1;
 
void create();
void insert();
void search(struct node *t);
void search_new(struct node *t,int n);
void delete_node();
void delete();
void inorder(struct node *t);
void preorder(struct node *t);
void posorder(struct node *t);
int smallest(struct node *t);
int largest(struct node *t);
 
int flag = 1;
 
void create(){
    int n;
    printf("Enter value of node to be inserted : ");
    scanf("%d", &n);
    temp = (struct node *)malloc(1*sizeof(struct node));
    temp->key = n;
    temp->l = temp->r = NULL;
}
 
void insert(){
    create();
    if (root == NULL) 
        root = temp;
    else    
        search(root);    
}
 
void search(struct node *t){
    if ((temp->key > t->key) && (t->r != NULL))      
        search(t->r);
    else if ((temp->key > t->key) && (t->r == NULL))
        t->r = temp;
    else if ((temp->key < t->key) && (t->l != NULL))    
        search(t->l);
    else if ((temp->key < t->key) && (t->l == NULL))
        t->l = temp;
}

void search_new(struct node *t, int n){ //procura o lugar pro novo nodo
    if ((n>t->key)){
        t1 = t;
        search_new(t->r, n);
    }else if ((n < t->key)){
        t1 = t;
        search_new(t->l, n);
    }else if ((n==t->key)){
        delete_node(t);
    }
}

void delete_node(struct node *t){
    int k;
    if ((t->l == NULL) && (t->r == NULL)){ //exclui o no da folha
        if (t1->l == t){
            t1->l = NULL;
        }else{
            t1->r = NULL;
        }
        t = NULL;
        free(t);
        return;
    }else if ((t->r == NULL)){  //exclui o no com filho a esquerda
        if (t1 == t){
            root = t->l;
            t1 = root;
        }else if (t1->l == t){
            t1->l = t->l;
        }else{
            t1->r = t->l;
        }
        t = NULL;
        free(t);
        return;
    }else if (t->l == NULL){ //exclui o no com filho a direita
        if (t1 == t){
            root = t->r;
            t1 = root;
        }else if (t1->r == t)
            t1->r = t->r;
        else
            t1->l = t->r;
        t == NULL;
        free(t);
        return;
    }else if ((t->l != NULL) && (t->r != NULL)){ //exclui o no com dois filhos
        t2 = root;
        if (t->r != NULL){
            k = smallest(t->r);
            flag = 1;
        }else{
            k =largest(t->l);
            flag = 2;
        }search_new(root, k);
        t->key = k;
    }
 
}
 
void delete(){ //verifica o nodo que excluido
    int n;
    if (root == NULL){
        printf("No elements in a tree to delete");
        return;
    }
    printf("Enter the value to be deleted : ");
    scanf("%d", &n);
    t1 = root;
    t2 = root;
    search_new(root, n);
}
 
void inorder(struct node *t){
    if (root == NULL){
        printf("No elements in a tree to display");
        return;
    }
    if (t->l != NULL)    
        inorder(t->l);
    printf("%d -> ", t->key);
    if (t->r != NULL)    
        inorder(t->r);
}

void preorder(struct node *t){
    if (root == NULL){
        printf("No elements in a tree to display");
        return;
    }
    printf("%d -> ", t->key);
    if (t->l != NULL)    
        preorder(t->l);
    if (t->r != NULL)    
        preorder(t->r);
}
 
void posorder(struct node *t){
    if (root == NULL){
        printf("No elements in a tree to display ");
        return;
    }
    if (t->l != NULL) 
        posorder(t->l);
    if (t->r != NULL) 
        posorder(t->r);
    printf("%d -> ", t->key);
}
 
int smallest(struct node *t){ //encontra o minimo 
    t2 = t;
    if (t->l != NULL)
    {
        t2 = t;
        return(smallest(t->l));
    }else    
        return (t->key);
}
 
int largest(struct node *t){ //encontra o maximo
    if (t->r != NULL){
        t2 = t;
        return(largest(t->r));
    }else    
        return(t->key);
}

void main(){
    int op;
    printf("\n1 - Insert\n");
    printf("2 - Delete\n");
    printf("3 - Print Inorder\n");
    printf("4 - Print Preorder\n");
    printf("5 - Print Posorder\n");
    printf("6 - Exit\n");
    while(1){
        printf("\nEnter your option : ");
        scanf("%d", &op);
        switch (op){
        case 1:    
            insert();
            break;
        case 2:    
            delete();
            break;
        case 3:    
            inorder(root);
            break;
        case 4:    
            preorder(root);
            break;
        case 5:    
            posorder(root);
            break;
        case 6:    
            exit(0);
        default :     
            printf("Wrong choice, enter another value: ");
            break;    
        }
    }  
}