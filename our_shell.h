#ifndef OUR_SHELL
#define OUR_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>

char *newpath(char **, char *);
char *strcompare(char *, char *, int *);
char *concat(char *, char *);
int filefind(char *, char *);
char **tokp(char *);
char *read_for_me();
char **separate(char *);
int count_my_word(char *, char *);
int evaluate(char *, char *, char **, char **);
char *copy_me(char *);
int compath(char *, char *);
char **repstring(char *, char **);
char *checkcmd(char **, char *);
int isfullpath(char *, char *);
#endif
