#include <stdio.h>

struct node{

int val;
struct node* left;
struct node* right;
};

struct node* create(){
  struct newNode*  = (sturct node*)malloc(sizeOf(struct node*));
  return newNode;
}



int main(void) {
  struct node* root;
  int n,temp;
  printf("Enter number of elements");
  scanf("%d",&n);
  printf("Enter elements : ");
  scanf("%d",&temp);
  root->val = temp;
  for(int i = 0; i<n-1; i++){
    printf("Enter elements : ");
    scanf("%d",&temp);
    
  }
  
  return 0;
}