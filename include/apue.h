#ifndef APUE_H_
#define APUE_H_
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <memory.h>

#define MAXLINE 1024

/*
 * buf[] contains white-space-separated arguments.  We convert it to an
 * argv-style array of pointers, and call the user's function (optfunc)
 * to process the array.  We return -1 if there's a problem parsing buf,
 * else we return whatever optfunc() returns.  Note that user's buf[]
 * array is modified (nulls placed after each token).
 */
int buf_args(char *buf, int (optfunc)(int, char **));

/*
 * Pass a file descriptor to another process.
 * If fd<0, then -fd is send back instead as the error status.
 */
int send_fd(int fd, int fd_to_send);
/*
 * Used when we had planned to send an fd using send_fd(),
 * but encountered an error instead.  We sned the errror back
 * using the sned_fd()/recv_fd() protocol.
 */
int send_err(int fd, int status, const char *errmsg);
/*
 * Receive a file descriptor from a server process.  Also, any data
 * received is passed to (*userfunc)(STDERR_FILENO, buf, nbytes).
 * We have a 2-byte protocol for receiving the fd from send_fd().
 */
int recv_fd(int fd, ssize_t (*userfunc)(int, const void *, size_t));

/*
 * Create a server endpoint of a connection.
 * Returns fd if all OK, <0 on error.
 */
int serv_listen(const char *name);
/*
 * Wait for a client connection to arrive, and accept it.
 * We also obtain the client's user ID from the pathname
 * that it must bind before calling us.
 * Returns new fd if all OK, <0 on error
 */
int serv_accept(int listenfd, uid_t *uidptr);

/*
 * Returns a full-duplex "stream" pipe (a UNIX domain socket)
 * with the two file descriptors returned in fd[0] and fd[1].
*/
int s_pipe(int fd[2]);

/*
 * Read "n" bytes from a descriptor
 */
ssize_t readn(int fd, void *ptr, size_t n);
/*
 * Write "n" bytes to a descriptor
 */
ssize_t writen(int fd, const void *ptr, size_t n);

/*
 * Nonfatal error related to a system call.
 * Print a message and return
 */
void err_ret(const char *fmt, ...);
/*
 * Fatal error related to a system call.
 * Print a message and terminate.
 */
void err_sys(const char *fmt, ...);
/*
 * Fatal error unrelated to a system call.
 * Error code passed as explict parameter.
 * Print a message and terminate.
 */
void err_exit(int error, const char *fmt, ...);
/*
 * Fatal error related to a system call.
 * Print a message, dump core, and terminate.
 */
void err_dump(const char *fmt, ...);
/*
 * Nonfatal error unrelated to a system call.
 * Print a message and return.
 */
void err_msg(const char *fmt, ...);
/*
 * Fatal error unrelated to a system call.
 * Print a message and terminate.
 */
void err_quit(const char *fmt, ...);

#endif // APUE_H_
