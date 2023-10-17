#ifndef MHEAD_H
#define MHEAD_H

#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define EXITCCODE 5
#define FORKSKIIP 6
#define NOTTHATANDTHAT 2
#define PTRGEPFXIX 4
#define EXCUTTEU_DO_BRO 7
#define FTAHLSHE 0
#define TTRHUEE 1
#define MTAHTCEH 3


/**
 * struct Alias - Alist is linked sig
 * @name: allisas name
 * @value: aliiasle vallue called
 * @next: pnextnnode called
 */
typedef struct Alias
{
	char *name;
	char *value;
	struct Alias *next;
} alias;

extern char **environ;

extern int thestatus;

extern int numberoflines;

extern char *the_name_of_shell;

int moondmang_gerfunct(char **args);

int thebuilti_nfunctons(char **args);

int theandoorfunct(char **args, char operator, int last_compare);

char *comondschecker(char **args);

int coomdodexucutes(char **args);

char *theinpuutscaan(char *old_buf, size_t *old_size);

int theerrormessagechck(char *ptr);

void theerrormessage(char *arg0, char *arg1);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

int _getline(char **line_ptr, size_t *n, int file);

char *checkvarrs(char *arg);

int _lengthofstr(char *str);

char *_stingduplicaing(char *src);

char *strinone(char *s1, char *s2);

int twostringcompare(char *s1, char *s2, int pref_or_match);

char *findaallarrayelemnt(char **array, char *element_name);

char **arraymaker(char *str, char delim, char **if_sep);

int lengthiflist(char **list, char *entry);

char **copyofarray(char **old_array, int new_size);

int arrayfree(char **args);

int envaset(const char *name, const char *value);

int _varunse(const char *name);

int dirchan(char *name);

int aliasfun(char **args, int free);

int makealiasfree(alias *alias_ptr);

int ifaliasesisfounded(char **args, alias *alias_ptr);

int aliassesprint(alias *alias_ptr);

int aliasval(char *arg, alias *alias_ptr);

int aliassettt(char *arg, alias *alias_ptr, char *new_value);

int envpriiint(void);

char *tiait(int n);

int _tato(char *s);

#endif
