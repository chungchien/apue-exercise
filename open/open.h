#ifndef APUE_OPEN_H
#define APUE_OPEN_H

#include "apue.h"
#include <errno.h>

#define CL_OPEN "open"         /* client's requrest for server */

int csopen(char *, int);

#endif // APUE_OPEN_H
