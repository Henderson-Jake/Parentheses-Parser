#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int isEmpty(Stack *s) {
	if(s->size == 0) {
		return 1;
	}
	return 0;
}

void push(Stack *s, char c) { //pushes c onto the stack
	if(s->size == s->cap) {
		s->cap += 10;
		s->data = realloc(s->data, (s->cap * sizeof(Stack)));
	}

	//push onto the stack
	s->data[s->size] = c;

	//increase the size
	s->size++;
}

char pop(Stack *s) {
	if(s->size == 0) {
		printf("Tried popping an empty stack\n");
		exit(0);
	}
	//decrease size
	s->size--;

	//return what you're popping
	return s->data[s->size];
}

char peek(Stack *s) {
	if(s->size == 0) {
		fprintf(stderr, "tried peeking an empty stack\n");
		exit(0);
	}
	//return top val
	return s->data[s->size - 1];
}

Stack *init() {
	Stack *s = malloc(sizeof(Stack)); 
	if(s == NULL) {
		perror("error allocating stack\n");
		exit(1);
	}

	s->size = 0;
	s->cap = 20; //set value

	s->data = malloc(s->cap * sizeof(Stack));

	if(s->data == NULL) {
		perror("error allocating stack\n");
		exit(1);
	}

	return s;
}

void destroy(Stack *s) {
	free(s->data);
	free (s);
}
