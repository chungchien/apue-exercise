#ifndef APUE_OPEND_H_
#define APUE_OPEND_H_

#include "apue.h"
#include <errno.h>

#define CL_OPEN "open"

extern char errmsg[];           /* error message string to return to client */
extern int oflag;               /* open() flag: O_XXX ... */
extern char *pathname;          /* of file to open() for client */

int cli_args(int, char **);
void request(char *, int, int);

#endif // APUE_OPEND_H_
