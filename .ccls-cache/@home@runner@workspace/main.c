#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node *left;
  struct Node *right;
  int data;
} node;

node *root;

int search(int val, node *current) {
  if (current->data == val) {
    return 1;
  } else if (val > current->data && current->right != NULL) {
    search(val, current->right);
  } else if (val < current->data && current->left != NULL) {
    search(val, current->left);
  } else if (current->right == NULL && current->left == NULL) {
    return 0;
  }
}

void insertNode(int val, node *current, node *newNode) {
  if (val > current->data && current->right != NULL) {
    insertNode(val, current->right, newNode);
  } else if (val < current->data && current->left != NULL) {
    insertNode(val, current->left, newNode);
  } else if (val > current->data && current->right == NULL) {
    current->right = newNode;
  } else if (val < current->data && current->left == NULL) {
    current->left = newNode;
  }
}

node *create() {
  node *temp = (node *)malloc(sizeof(node));
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

void insertData(int val) {
  if (root == NULL) {
    root = create();
    root->data = val;
  } else {
    node *temp = create();
    if(search(val,root)){
      printf("Error value already in binary tree.\n");
      return;
    }
    temp->data = val;
    insertNode(val, root, temp);
    return;
  }
}

void inOrder(node *current) {
  if (current != NULL) {
    inOrder(current->left);
    printf("%d \t", current->data);
    inOrder(current->right);
  } else {
    return;
  }
}

void postOrder(node *current) {
  if (current != NULL) {
    postOrder(current->left);
    postOrder(current->right);
    printf("%d \t", current->data);
  } else {
    return;
  }
}

void preOrder(node *current) {
  if (current != NULL) {
    printf("%d \t", current->data);
    preOrder(current->left);
    preOrder(current->right);
  } else {
    return;
  }
}

int main() {
  int op, temp;
  while (1) {
    printf("\nEnter operation : \n");
    printf("1 - Insert an element into tree\n");
    printf("2 - Inorder Traversal\n");
    printf("3 - Preorder Traversal\n");
    printf("4 - Postorder Traversal\n");
    printf("5 - Search\n");
    printf("6 - Exit\n");
    scanf("%d", &op);
    switch (op) {
    case 1:
      printf("Enter a value : ");
      scanf("%d", &temp);
      insertData(temp);
      printf("\n");
      break;
    case 2:
      inOrder(root);
      printf("\n");
      break;
    case 3:
      preOrder(root);
      printf("\n");
      break;
    case 4:
      postOrder(root);
      printf("\n");
      break;
    case 5:
      printf("Enter key : ");
      scanf("%d", &temp);
      temp = search(temp, root);
      if(temp)
          printf("Key found in tree. \n");
      else
          printf("Key not founf in tree. \n");
      break;
    case 6:
      exit(0);
    default:
      printf("Wrong Operation Entered");
      printf("\n");
      break;
    }
  }

  return 0;
}