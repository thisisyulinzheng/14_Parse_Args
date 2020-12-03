#include <unistd.h>
#include <string.h>
#include <stdlib.h>
char ** parse_args(char * line) {
	char ** args;
	args = malloc(10*sizeof(char *));
	int i = 0;
	char *p = line;
	while (p) {
		args[i] = strsep(&p, " ");
		i++;
	}
	return args;
}

int main() {
	char line[] = "ls -a -l";
	char ** args = parse_args(line);
	execvp(args[0], args);
	free(args);
	return 0;
}