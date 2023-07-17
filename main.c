#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main(int argc, char* argv[]) {

	char v[8];
	int i;
	char x = '(', y = ')';
	Stack *s = init(s);

	printf("Enter your string of 6 parentheses.\n");
	scanf("%s", v);

	if(strlen(v) < 5){
		printf("Not enough values to parse!");
		return -1;
	}
	printf("Is %s ordered??\n", v);

	for(i = 0; i < 8; ++i) {
		if(v[i] == x) {
			push(s, v[i]);
			printf("pushed %c!\n", v[i]);
		}
		else if(v[i] == y) {
			pop(s);
			printf("Popped %c!\n", v[i]);
		}

	}

	if(isEmpty(s)) {
		printf("The string is ordered properly! Well done!\n");
	}
	else {
		printf("The string is not ordered properly! BOOOOOOOO\n");
	}

	destroy(s);

	// printf("%s\n", userString);
	return 0;

}
