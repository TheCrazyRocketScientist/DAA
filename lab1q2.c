#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

  int data;
  struct Node *next;

} node;

node *getLast(node *current) {
  if (current == NULL) {
    return NULL;
  }
  while (current->next != NULL) {
    current = current->next;
  }
  return current;
}

void printList(node *current) {
  printf("\n");
  while (current->next != NULL) {
    printf("%d->", current->data);
    current = current->next;
  }
  printf("%d", current->data);
  printf("\n");
}

int main() {
  int edges, v;
  int src, dest;
  int n, temp;
  int *adjMat;
  node **adjList;
  node *current;

  printf("Enter number of Edges : ");
  scanf("%d", &edges);
  printf("\n");

  printf("Enter number of vertices : ");
  scanf("%d", &v);
  printf("\n");

  adjMat = (int *)calloc(v * v, sizeof(int));
  adjList = (node **)malloc(v * sizeof(node *));

  for (int i = 0; i < v; i++) {
    adjList[i] = (node *)malloc(sizeof(node));
    adjList[i]->data = i + 1;
    adjList[i]->next = NULL;
  }

  for (int i = 0; i < edges; i++) {
    printf("Enter Edge : SRC -> DEST");
    printf("Source\n");
    scanf("%d", &src);
    printf("Dest\n");
    scanf("%d", &dest);
    adjMat[((src - 1) * v) + (dest - 1)] = 1;
    adjMat[((dest - 1) * v) + (src - 1)] = 1;
    current = getLast(adjList[src - 1]);
    current->next = (node *)malloc(sizeof(node));
    current->next->data = dest;
    current->next->next = NULL;
    current = getLast(adjList[dest - 1]);
    current->next = (node *)malloc(sizeof(node));
    current->next->data = src;
    current->next->next = NULL;
  }

  printf("Adj Matrix : ");
  for (int i = 0; i < v * v; i++) {
    if (i % v == 0) {
      printf("\n");
    }
    printf("%d\t", adjMat[i]);
  }
  printf("\n");

  printf("Adj List : ");
  for (int i = 0; i < v; i++) {
    printList(adjList[i]);
  }

  return 0;
}