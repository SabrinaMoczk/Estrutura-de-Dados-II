/* Nome: Sabrina Moczulski
Disclina: Estruturas de Dados II
Matrícula: 1611100045
Email: sabrina.moczulski@gmail.com */

#include <stdio.h>
#include <stdlib.h>
#define red 1
#define black 0

typedef struct _nodo{
  int key;
  int color;
  struct _nodo *left;
  struct _nodo *right;
}TpNodo;

TpNodo *initialize(){
  return NULL;
}

int returnColor(TpNodo *tree){
  return tree == NULL ? 0 : tree->color; 
}

void caseOne(TpNodo *tree){
  tree->color = red; 
  tree->left->color = black; 
  tree->right->color = black; 
}

void caseTwoLeft(TpNodo *tree){
  TpNodo *aux;
  aux = tree->left->right; 
  tree->left->right = aux->left;
  aux->left = tree->left; 
  tree->left = aux; 
}

void caseTwoRight(TpNodo *tree){
  TpNodo *aux;
  aux = tree->right->left; 
  tree->right->left = aux->right;
  aux->right = tree->right; 
  tree->right = aux; 
}

void caseThreeLeft(TpNodo **tree){
  (*tree)->color = red;
  (*tree)->left->color = black;
  TpNodo *aux;
  aux = (*tree)->left; 
  (*tree)->left = aux->right;
  aux->right = (*tree);
  (*tree) = aux;
}

void caseThreeRight(TpNodo **tree){
  (*tree)->color = red;
  (*tree)->right->color = black;
  TpNodo *aux;
  aux = (*tree)->right; 
  (*tree)->right = aux->left;
  aux->left = (*tree);
  (*tree) = aux;
}

int insert(TpNodo **tree, int n){
  int inserido=0;
  if((*tree) == NULL){ 
    (*tree) = (TpNodo *) malloc(sizeof(TpNodo));
    (*tree)->key = n;
    (*tree)->color = red;
    (*tree)->left = NULL;
    (*tree)->right = NULL;
    return 1;
  }

  TpNodo *aux = (*tree);

  if(n < (*tree)->key){ 
    if((inserido = insert(&(aux->left),n)) == 1){ 
      if(n < aux->key){ 
        if(n != aux->left->key){ 
          if(aux->left->color != black){
            if(returnColor(aux->right) == red) { 
              caseOne(aux);
              return 0;
            } else {
              if(n > aux->left->key)
                caseTwoLeft(aux);
              caseThreeLeft(tree);
              return 0;
            } 
          } else 
            return 0;
        }
      } else { 
        if(n != aux->right->key){ 
          if(aux->right->color != black){
            if(returnColor(aux->left) == red) { 
              caseOne(aux);
              return 0;
            } else {
              if(n < aux->right->key)
                caseTwoRight(aux);
              caseThreeRight(tree);
              return 0;
            }
          } else
            return 0;
        }
      }
    }
  } else if(n > aux->key){ 
    if((inserido = insert(&(aux->right),n)) == red){ 
      if(n < aux->key){ 
        if(n != aux->left->key){ 
          if(aux->left->color != black){
            if(returnColor(aux->right) == red) { 
              caseOne(aux);
              return 0;
            } else {
              if(n > aux->left->key)
                caseTwoLeft(aux);
              caseThreeLeft(tree);
              return 0;
            } 
          } else
            return 0;
        }
      } else { 
        if(n != aux->right->key){ 
          if(aux->right->color != black){
            if(returnColor(aux->left) == 1) {
              caseOne(aux);
              return 0;
            } else {
              if(n < aux->right->key)
                caseTwoRight(aux);
              caseThreeRight(tree);
              return 0;
            }
          } else
            return 0;
        }
      }
    }
  } else { 
    printf("This number is already in the tree.\n");
    wait();
  }
  return inserido;
}

void print(TpNodo *tree, int i){
  int j;
  if(tree != NULL){
    for(j = 0; j < i; j++)
      printf(".");
    if(tree->color == red)
      printf("%d [red]\n", tree->key);
    else
      printf("%d [black]\n", tree->key);
    print(tree->left, i+1);
    print(tree->right, i+1);
  }
}

int menu() {
  int op;
  printf("1) Insert in tree\n2) Print tree\n0) Exit\n\n");
  scanf("%d", &op);
  return op;
}

void wait() {
  printf("\nPress Enter to continue.");
  scanf("%*c");
  scanf("%*c");
}

int main() {
  TpNodo *tree;
  int op, exit=0, num;
  
  tree = initialize();

  while(!exit) {
    
    system("clear");
    fflush(stdin);
    op = menu();
    
    switch(op) {
    case 1:
      system("clear");
      printf("Write the number that you desire add to tree: ");
      scanf("%d", &num);
      insert(&(tree), num);
      tree->color = 0;
      break;
  
    case 2:
      system("clear");
      printf("Tree: \n"); 
      print(tree, 1);
      printf("\n");
      wait();
      break;
    case 0:
      exit = 1;
      break;
    }
  }

  return 0;
}