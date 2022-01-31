#ifndef MINITALK_H
# define MINITALK_H

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void send_message(int pid, char *message);
void clienthandler(int signum, siginfo_t *siginfo, void *context);
void binaryToDecimal(int binary, int pid);
void    ft_putchar_fd(char c, int fd);
void    ft_putnbr_fd(int n, int fd);
void serverhandler(int signum, siginfo_t *siginfo, void *context);
void    ft_putstr_fd(char *s, int fd);

#endif