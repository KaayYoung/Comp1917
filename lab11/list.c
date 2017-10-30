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

Lnode new_node(int val){
    Lnode new = malloc(sizeof(struct node));
    if(new == NULL){
        printf("Out of memory:(\n");
        exit(1);
    }
    new->val = val;
    new->next = NULL;
    return new;
}
List newList(void){
    List new = malloc(sizeof(struct list));
    if(new == NULL){
        printf("Out of memory:(\n");
        exit(1);
    }
    new->head = NULL;
    new->num_nodes = 0;
    return new;
}

void append(List l, int val){
    assert(l != NULL);
    Lnode cur = l->head;
    Lnode new = new_node(val);
    if(cur == NULL){
        l->head = new;
    }else{
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = new;
    }
    l->num_nodes++;
}

void printList(List l){

    assert(l!= NULL);
    Lnode cur = l-> head;
    while(cur != NULL){
        printf("[%d]->",cur->val);
        cur = cur->next;
    }
    printf("X\n");
}


void destroy(List l){
    assert(l!= NULL);
    Lnode cur = l->head;
    Lnode prev = NULL;
    // free every single element of the list
    while(cur!= NULL){
        prev = cur;
        cur = cur->next;
        free(prev);
    }
    // free the list structure itself
    free(l);
}
int num_nodes(List l){
    return l->num_nodes;
}
//Given a linked list print it out in reverse
//Do not reverse original list
//Example:
//Given linked list [1]->[2]->[3]->X
//print_reverse output: [3]->[2]->[1]->X
void print_reverse(List l){
    Lnode curr1 = l->head;
    List new = newList();
    int i = 0;
    int j = l->num_nodes - 1;
    if (l->num_nodes == 1) {
        append(new,l->head->val);
    } else if (l->num_nodes == 0) {
        new = NULL;
    } else {
        while (i < j+1) {
            curr1 = l->head;
          while (i < j) {
               curr1 = curr1->next;
               i++;
          }
          i = 0;
          j--;
          append(new,curr1->val);
        }
    }
    if (new == NULL){
        printf("X\n");
    } else {
        printList(new);
    }
}
//Given a linked list create a new list containing only unique 
//elements of the current list. The order of the elements should remain 
// the same as in original linked list. Do not modify the original list.
//Example
//Input: 1->1->2->3->3->3->0->X
//Output:1->2->3->0->X
List extract_unique(List l){
    
    Lnode curr1 = l->head;
    List new = newList();
    Lnode curr2 = NULL;
    int count = 0;
    if (l->num_nodes == 0) {
        printf("X\n");
    } else if (l->num_nodes == 1) {
        append(new,l->head->val);
    } else {
        append(new,l->head->val);
        curr1 = curr1->next;
        while (curr1 != NULL) {
            curr2 = new->head;
            count = 0;
            while (curr2 != NULL) { 
               if (curr1->val == curr2->val) {
                 count++;             
               }
               curr2 = curr2->next;
            }
             if (count == 0){
                append(new,curr1->val);
               }
            curr1 = curr1->next;
        }
    }

    if (new->num_nodes != 0) {
        printList(new);
    }
   
    return new;
}








