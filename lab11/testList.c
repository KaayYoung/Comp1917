#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

void test_print_reverse(void);
void test_extract_unique(void);

void reverse_one(void);
void reverse2(void);
void reverse3(void);
void reverse4(void);
void unique_empty(void);
void unique2(void);
void unique3(void);
void unique4(void);
int main(void){
    //call individual test functions
    test_print_reverse();
    test_extract_unique();

    return 0;
}


void test_print_reverse(void){
    reverse_one();
    //add any additional functions to test your implementation here
    reverse2();
    reverse3();
    reverse4();
}

void reverse_one(void){
    printf("Testing print_reverse with 1 element\n");
    List new = newList();
    append(new, 0);
    printf("Expected output:\n");
    printf("[0]->X\n");
    printf("Your output:\n");
    print_reverse(new);
    destroy(new);
    printf("=========================\n");
}

void reverse2(void){
    printf("Testing print_reverse with empty list\n");
    List new = newList();
    printf("Expected output:\n");
    printf("X\n");
    printf("Your output:\n");
    print_reverse(new);
    destroy(new);
    printf("=========================\n");
}
void reverse3(void){
    printf("Testing print_reverse with 3 element\n");
    List new = newList();
    append(new, 0);
    append(new, 1);
    append(new, 2);
    printf("Expected output:\n");
    printf("[2]->[1]->[0]->X\n");
    printf("Your output:\n");
    print_reverse(new);
    destroy(new);
    printf("=========================\n");
}

void reverse4(void){
    printf("Testing print_reverse with 5 elements\n");
    List new = newList();
    append(new,2);
    append(new,2);
    append(new,4);
    append(new,3);
    append(new,6);
    printf("Expected output:\n");
    printf("[6]->[3]->[4]->[2]->[2]\n");
    printf("Your output:\n");
    print_reverse(new);
    destroy(new);
    printf("=========================\n");
}

//##################################################################
void test_extract_unique(void){
    unique_empty();
    //add any additional functions to test your implementation here
    unique2();
    unique3();
    unique4();
}

void unique_empty(void){
    printf("Testing extract_unique with empty list\n");
    List new = newList();
    printf("Expected output:\n");
    printf("X\n");
    printf("Your output:\n");
    List u = extract_unique(new);
    assert(num_nodes(new) == 0);
    assert(num_nodes(u) == 0);
    destroy(new);
    destroy(u);
    printf("Passed\n");
    printf("=========================\n");
}

void unique2(void){
    printf("Testing extract_unique with 4 elements\n");
    List new = newList();
    append(new,3);
    append(new,3);
    append(new,3);
    append(new,3);
    printf("Expected output:\n");
    printf("[3]->X\n");
    printf("Your output:\n");
    List u = extract_unique(new);
    assert(num_nodes(new) == 4);
    assert(num_nodes(u) == 1);
    destroy(new);
    destroy(u);
    printf("Passed\n");
    printf("=========================\n");
}

void unique3(void){
    printf("Testing extract_unique with 6 elements\n");
    List new = newList();
    append(new,2);
    append(new,2);
    append(new,6);
    append(new,6);
    append(new,6);
    append(new,5);
    printf("Expected output:\n");
    printf("[2]->[6]->[5]->X\n");
    printf("Your output:\n");
    List u = extract_unique(new);
    assert(num_nodes(new) == 6);
    assert(num_nodes(u) == 3);
    destroy(new);
    destroy(u);
    printf("Passed\n");
    printf("=========================\n");
}

void unique4(void){
    printf("Testing extract_unique with 8 elements\n");
    List new = newList();
    append(new,2);
    append(new,7);
    append(new,5);
    append(new,5);
    append(new,5);
    append(new,7);
    append(new,2);
    append(new,8);
    printf("Expected output:\n");
    printf("[2]->[7]->[5]->[8]->X\n");
    printf("Your output:\n");
    List u = extract_unique(new);
    assert(num_nodes(new) == 8);
    assert(num_nodes(u) == 4);
    destroy(new);
    destroy(u);
    printf("Passed\n");
    printf("=========================\n");
}

