#include <stdio.h>
#include <stdlib.h>

/* If compiling on Windows, compile these functions */
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

/* Fake readline function */
char* readline(char *prompt) {
	fputs(prompt, stdout);
	fgets(buffer, 2048, stdin);
	char* cpy = malloc(strlen(buffer) + 1);
	strcpy(cpy, buffer);
	cpy[strlen(cpy) - 1] = '\0';
	return cpy;
}

/* Fake add history method */
void add_history(char* unused) {}

/* otherwise include editline headers */
#else 
#include <editline/readline.h>
#endif

int main(int argc, char** argv) {

	puts("Lisp version 0.0.0.0.0.0");
	puts("Press ctrl-c to exit\n");

	while (1) {
		// output prompt and get input
		char* input = readline("lispy> ");

		// add history to input
		add_history(input);

		// echo input
		printf("Input: %s\n", input);

		free(input);
	}
	return 0;
}