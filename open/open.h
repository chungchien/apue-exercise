#ifndef APUE_OPEN_H
#define APUE_OPEN_H

#include "apue.h"
#include <errno.h>

#define CL_OPEN "open"         /* client's requrest for server */
#define CS_OPEN "/home/jian/opend" /* server's well-known name */

int csopen(char *, int);

#endif // APUE_OPEN_H
