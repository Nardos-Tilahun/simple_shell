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
#include <signal.h>

typedef void (*mysignalhand)(int);
void myexit_point(int);
char *newpath(char **, char *);
char *strcompare(char *, char *);
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
void child(char *, char *, char *vec_arg[], char *genv[]);
char *checkenv(char *our_env[], char *);
int lenstr(char *);
char *strtokk(char *, char *);
int mainhelp(char ***, char ***, char **, char ***, int *);
int getcmd(char ***, char *our_env[]);
char *helpfun(char *, char *);
char *strconc(char *, char *);
int hgetcmd(char *, char **);
int usetenv(char ***, char ***);
int setmyenv(char *, char *, int, char ***);
int unsetmyenv(char *, char ***);
char **tokenv(char *);
#endif
