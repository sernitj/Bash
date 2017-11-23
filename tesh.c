#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <winsock2.h>

#define MAX_INSTRUCTION_LENGTH 256
#define MAX_HOST_LENGTH 64
#define MAX_PATH_LENGTH 128
#define BUFSIZE 256

// Renvoie la longueur d'une cha�ne de caract�res
int string_length(char* string) {

	int length = 0;

	while (string[length] != '\0') {
		length++;
	}

	return length;
}

// On met les commandes et arguments dans un tableau
char** parseSentence(char* sentence) {

	int length = string_length(sentence);
	char** tabSentence = (char**) malloc((length/2)*sizeof(char*));
	const char delimiter[2] = " ";
	char* word;
	int count = 0;

	word = strtok(sentence, delimiter);

	while (word != NULL) {
		tabSentence[count] = word;
		count++;
		word = strtok(NULL, delimiter);
	}

	//Affichage pour test
	printf("Tableau final :\n");

	for (int i=0; i<count; i++) {
		printf( "%s\n", tabSentence[i]);
	}

	return tabSentence;
}

void analyseInstruction(char* sentence, char* path) {
	char** tabSentence = parseSentence(sentence);

	printf("Test test\n");

	if(!strcmp(sentence, "cd")) {

	}

	sentence = "";
}

char* getInstruction(char* sentence) {
	char* endOfLine = NULL;

	if(fgets(sentence, MAX_INSTRUCTION_LENGTH, stdin) != NULL) {
		endOfLine = strchr(sentence, '\n');

		if(endOfLine != NULL)
			*endOfLine = '\0';

		return sentence;
	} else return NULL;

	analyseInstruction(sentence, "");
}

/*
// >>
void appendFile(char* args) {
	int fd[2];
	pipe(fd);
	char bufin[BUFSIZE] = "empty";
	char bufout[ ] = "hello";

	if(!fork()) {
		fd = open(args[1], O_WRONLY | O_APPEND);
		dup2(fd, 1);
		close(fd);
		execlp(args[0], args[0], NULL);
		//

	}
}

// >
void createFile(char* args) {
	int fd[2];
	pipe(fd);

	if(!fork()) {
		fd = open(args[1], O_WRONLY);
		dup2(fd, 1);
		close(fd);
		execlp(args[0], args[0], NULL);
		//

	}
}

// <
void readFromFile(char* args) {
	int fd[2];
	pipe(fd);

	if(!fork()) {
		fd = open(args[1], O_RDONLY);
		dup2(fd, 0);
		close(fd);
		execlp(args[0], args[0], NULL) ;
		//


	}
}

// |
void pipeOperation(char* args) {
	int fd[2];
	pipe(fd);

	if(fork() == 0) {
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		execlp(args[0], args[0], NULL);
	}

	if(fork() == 0) {
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		execlp(args[1], args[1], NULL);
	}

	wait(NULL);
	wait(NULL);
}

// &&
void logicalAnd(char* args) {
	int status;

	if(fork() == 0)
		execlp(args[0], args[0], NULL);

	wait(&status);




	wait(NULL);
}

// ||
void logicalOr(char* args) {
	int status;

	if(fork() == 0)
		execlp(args[0], args[0], NULL);

	wait(&status);

	if((WEXITED(status) && (WEXITSTATUS(status) != 0)) && fork() == 0)
		execpl(args[1], args[1], NULL);

	wait(NULL);
}*/

int main() {
	char sentence[MAX_INSTRUCTION_LENGTH];
	char* user = getenv("USERNAME");
	char host[MAX_HOST_LENGTH];
	char path[MAX_PATH_LENGTH];

    //gethostname(host, MAX_HOST_LENGTH);
    getcwd(path, MAX_PATH_LENGTH);

    while(1) {
    	printf("%s@%s:%s$ ", user, host, path);
    	getInstruction(sentence);

    	if(strcmp(sentence, ""))
    		analyseInstruction(sentence, path);
    }

    return 0;
}
