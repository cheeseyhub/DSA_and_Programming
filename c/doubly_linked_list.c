#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct doublyLinkedListNode {
  char *data;
  struct doublyLinkedListNode *prev;
  struct doublyLinkedListNode *next;
} doublyLinkedListNode;

typedef struct doublyLinkedList {
  doublyLinkedListNode *firstNode;
  doublyLinkedListNode *lastNode;
} doublyLinkedList;

void transverseListForward(doublyLinkedList *l) {
  doublyLinkedListNode *node = l->firstNode;

  while (node != NULL) {
    printf("%s ", node->data);
    node = node->next;
  }
}
void transverseListBackward(doublyLinkedList l) {
  doublyLinkedListNode *node = l.lastNode;

  while (node != NULL) {
    printf("%s ", node->data);
    node = node->prev;
  }
}
void insertAfterNode(doublyLinkedList *list, doublyLinkedListNode *node,
                     doublyLinkedListNode *newNode) {
  newNode->prev = node;
  if (node->next == NULL) {
    newNode->next = NULL;
    list->lastNode = newNode;
  } else {
    node->next->prev = newNode;
    newNode->next = node->next;
  }
  node->next = newNode;
}
void insertBefore(doublyLinkedList *list, doublyLinkedListNode *node,
                  doublyLinkedListNode *newNode) {
  newNode->next = node;
  if (node->prev == NULL) {
    node->prev = NULL;
    list->firstNode = newNode;
  } else {
    node->prev->next = newNode;
    newNode->prev = node->prev;
  }
  node->prev = newNode;
}
doublyLinkedListNode *createNode(const char *text) {
  doublyLinkedListNode *node = calloc(1, sizeof(doublyLinkedListNode));
  node->data = strdup(text);
  node->next = NULL;
  node->prev = NULL;
  return node;
}
void RemoveNode(doublyLinkedList *list, doublyLinkedListNode *node) {
  if (node->prev == NULL) {
    list->firstNode = node->next;
  } else {
    node->prev->next = node->next;
  }
  if (node->next == NULL) {
    list->lastNode = node->prev;
  } else {
    node->next->prev = node->prev;
  }
  free(node->data);
  free(node);
}
void clearList(doublyLinkedList *list) {
  doublyLinkedListNode *current = list->firstNode;
  while (current != NULL) {
    doublyLinkedListNode *next = current->next;
    RemoveNode(list, current);
    current = next;
  }
  free(list);
};
doublyLinkedList *createList(doublyLinkedListNode *start,
                             doublyLinkedListNode *end) {
  doublyLinkedList *newList = calloc(1, sizeof(doublyLinkedList));
  newList->firstNode = start;
  newList->lastNode = end;
  start->next = end;
  end->prev = start;
  return newList;
}
int main() {

  doublyLinkedListNode *start = createNode("This is the start");
  doublyLinkedListNode *end = createNode("This is the end");

  doublyLinkedList *list = createList(start, end);

  doublyLinkedListNode *middle = createNode("This is the middle ");
  insertAfterNode(list, start, middle);
  transverseListForward(list);

  printf("\n");
  RemoveNode(list, middle);
  transverseListForward(list);
  clearList(list);
}
