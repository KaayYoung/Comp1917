#include "Stack.h"
#include "Pancake.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct stack {
    int numPancakes;
    Pancake array[MAX_PANCAKES];
};

Stack createStack(void) {
	Stack s = malloc(sizeof(struct stack));
	assert(s != NULL);
	s->numPancakes = 0;
	return s;
}
// if stack is already full, do nothing
void addPancake(Stack s, char *topping, int size) {
    if (s->numPancakes < MAX_PANCAKES) {
        s->array[s->numPancakes] = bake(topping,size);
        s->numPancakes++;
    }
}
// if stack is already empty, do nothing
void eatPancake(Stack s) {
	if (s->numPancakes > 0) {
	   
	   eat(s->array[s->numPancakes-1]);
	   
	   s->numPancakes--; 
	}
}

int numPancakes(Stack s) {
	return s->numPancakes;
	
}

int totalSize(Stack s) {
	int totalsize = 0;
	int i = s->numPancakes - 1;
	while (i >= 0) {
       totalsize += getSize(s->array[i]);
       i--;
	}
	return totalsize;
}

void printToppings(Stack s) {
	int i = s->numPancakes - 1;
	while (i >= 0) {
	   printf("%s\n",getTopping(s->array[i]));
	   i--;
	}
}


void consumeStack(Stack s) {
    while (s->numPancakes > 0) {
        eat(s->array[s->numPancakes-1]);
        s->numPancakes--;
    }
    free(s);
}

