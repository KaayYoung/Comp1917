#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

struct node{
  int val;
  Lnode next;  
};


struct list{
    Lnode head;
    int num_nodes;
};

Lnode new_node(int val) {
    Lnode new = malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Out of memory:(\n");
        exit(1);
    }
    new->val = val;
    new->next = NULL;
    return new;
}
List newList(void){
    List new = malloc(sizeof(struct list));
    if (new == NULL) {
        printf("Out of memory:(\n");
        exit(1);
    }
    new->head = NULL;
    new->num_nodes = 0;
    return new;
}

void append(List l, int val) {
    assert(l != NULL);
    Lnode cur = l->head;
    Lnode new = new_node(val);
    if (cur == NULL) {
        l->head = new;
    }else {
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new;
        
    }
    l->num_nodes++;
}

void printList(List l) {
    assert(l!= NULL);
    Lnode cur = l-> head;
    while(cur != NULL) {
        printf("[%d]->",cur->val);
        cur = cur->next;
    }
    printf("X\n");
}


void deleteList(List l) {
    Lnode curr = l->head;
    if (l->head == NULL) {
        free(l);
    } else {
      curr = l->head;
      l->head = l->head->next;
      deleteList(l);
      free(curr);
    }
}


