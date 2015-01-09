#ifndef APUE_OPEND_H_
#define APUE_OPEND_H_

#include "apue.h"
#include <errno.h>

#define CS_OPEN "/home/jian/opend" /* well-known name */
#define CL_OPEN "open"

extern int debug;       /* nonzero if interactive (not daemon) */
extern char errmsg[];           /* error message string to return to client */
extern int oflag;               /* open() flag: O_XXX ... */
extern char *pathname;          /* of file to open() for client */

typedef struct {                /* one Client struct per connected client */
    int fd;                     /* fd, or -1 if available */
    uid_t uid;
} Client;
extern Client *client;          /* ptr to malloc'ed array */
extern int client_size;         /* # entries in client[] array */

int cli_args(int, char **);
int client_add(int, uid_t);
void client_del(int);
void loop(void);
void request(char *, int, int, uid_t);

#endif // APUE_OPEND_H_
