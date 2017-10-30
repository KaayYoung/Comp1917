#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"


void test_delete_none(void);
void test_delete_one(void);
void test_delete_many(void);


int main(void){
    test_delete_none();
    test_delete_one();
    test_delete_many();

    return 0;
}

void test_delete_none(void){
    printf("Testing delete with no nodes\n");
    List l = newList();
    deleteList(l);
}

void test_delete_one(void){
    printf("Testing delete with one nodes\n");
    List l = newList();
    append(l,27);
    deleteList(l);
}

void test_delete_many(void){
    printf("Testing delete with no nodes\n");
    List l = newList();
    int i;
    for(i = 0; i < 10; i++){
        append(l,i);
    }
    deleteList(l);
}



