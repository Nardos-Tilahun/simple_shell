#ifndef OUR_SHELL_H
#define OUR_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <linux/limits.h>
#include <signal.h>
#include <fcntl.h>



extern char **environ;
void new_envi(char **envi);
void freenv(char **env);
char *mycpystrn(char *, char *, int);
int mylenstr(char *);
int mycharput(char);
int _atoi(char *s);
void _myputs(char *str);
int mycmpstr(char *, char *);
int myalphais(int);
void rev_arr(char *arr, int len);
int mylenint(int);
char *myi_to_a(unsigned int);
char *mycatstr(char *, char *);
char *mycpystr(char *, char *);
char *mychrstr(char *, char);
int mycmpstrn(const char *, const char *, size_t);
char *mydcopystr(char *);
void freenv(char **);
void *fillarr(void *a, int el, unsigned int len);
char *mycpymem(char *dest, char *src, unsigned int n);
void *mycal_oc(unsigned int size);
void *myre_loc(void *ptr, unsigned int old_size, unsigned int new_size);
void arrfree(char **input, char *line);


#define myprinter(f) (write(STDERR_FILENO, f, mylenstr(f)))

char *mycpystrn(char *dest, char *src, int n);
int mylenstr(char *s);
int mycharput(char c);
int _atoi(char *s);
void _myputs(char *str);
int mycmpstr(char *s1, char *s2);
int myalphais(int c);
void rev_arr(char *arr, int len);

char *catchline();
char *handspace(char *str);
char *newline(char *string);
void ignore(char *buff);
void printing(void);
unsigned int is_delim(char c, const char *str);
char *mytokstr(char *str, const char *delim);
int myhist(char *input);
char **splits(char *input);


void hit_file(char *file, char **argv);
void catchfile(char *line, int count, FILE *fp, char **argv);
void filecheckext(char **cmd, char *line, FILE *fd);


char **chan_cmd(char *input);
int checkinbuilt(char **cmd, int er);
int input_ch(char **cmd, char *input, int c, char **argv);
void signal_checker(int sig);


void show_err(char *input, int counter, char **argv);
void errpre(char **argv, int c, char **cmd);
void warn_file(char **argv, int c);

extern char **environ;
void new_envi(char **envi);
void freenv(char **env);

/**
 * struct _builtin - Defines a strus
 * with their respective implementans
 * @commd: - Built-in command
 * @function: - Pointer
 * similar functionalities as the built
 */
typedef struct _builtin
{
	char *commd;
	int (*function)(char **line, int st);
} builtin;



void p_num(unsigned int n);
void p_num_int(int n);
int print_echo(char **cmd);


#define BUFSIZE 5012
int comad_place(char **cmd);
char *made(char *token, char *value);
char *shomyenv(char *name);
void myenvh(void);
void myenvseth(void);
void help_unsetenv(void);
void help_myhist(void);
void joy(void);
void alhi(void);
void cdh(void);
void exh(void);
void helper(void);
int herehelp(char **cmd, int st);

int statbuilt(char **cmd);
int checkinbuilt(char **cmd, int st);
void exiting(char **cmd, char *input, char **argv, int c,
		int stat);
int change_dir(char **cmd, int st);
int distrenv(char **cmd, int st);
int echo_bul(char **cmd, int st);
int myhist_dis(char **c, int st);



#endif
