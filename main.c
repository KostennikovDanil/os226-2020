#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int code;

int echo(int argc, char *argv[]) 
{
	for (int i = 1; i < argc; ++i)
    {

		printf("%s%c", argv[i], i == argc - 1 ? '\n' : ' ');
	}
	return argc - 1;
}


int retcode(int argc, char *argv[]) 
{
	printf("%d\n", code);
	return 0;
}



int main(int argc, char* argv[]) {
	char input[1024];
	char* str = NULL;
	char* arg = NULL;
	code = 0;
	while (fgets(input, sizeof input, stdin))
	{
		char* token = strtok_r(input, "\n;", &str);
		while (token != NULL)
		{
			argc = 0;
			char* subtoken = strtok_r(token, " ", &arg);
			while (subtoken != NULL)
			{
				argv[argc++] = subtoken;
				subtoken = strtok_r(NULL, " ", &arg);
			}
			if (!strcmp(argv[0], "echo"))
				code = echo(argc, argv);
			else if (!strcmp(argv[0], "retcode"))
				retcode(argc, argv);
			else
				printf("%s", "\nWrong command");

			token = strtok_r(NULL, "\n;", &str);
		}
	}
	return 0;
}