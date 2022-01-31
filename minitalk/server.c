#include "minitalk.h"

void    ft_putchar_fd(char c, int fd)
{
    if (fd < 0)
        return ;
    write(fd, &c, 1);
}

void    ft_putnbr_fd(int n, int fd)
{
    if (n == -2147483648)
    {
        write(fd, "-2147483648", 11);
    }
    else if (n < 0)
    {
        write(fd, "-", 1);
        ft_putnbr_fd(-n, fd);
    }
    else if (n < 10 && n >= 0)
    {
        ft_putchar_fd(n + '0', fd);
    }
    else if (n > 0)
    {
        ft_putnbr_fd(n / 10, fd);
        ft_putchar_fd(n % 10 + '0', fd);
    }
}

void    ft_putstr_fd(char *s, int fd)
{
    int             index;

    index = 0;
    if (fd < 0)
            return ;
    while (s[index] != '\0')
    {
            ft_putchar_fd(s[index], fd);
            index++;
    }
}

void binaryToDecimal(int binary, int pid)
{
    static unsigned char ch = 0;
    static int index = 7;

    ch += (binary << index--);
    if (index < 0)
    {
        write(1, &ch, 1);
        index = 7;
        ch = 0;
        if (kill(pid, SIGUSR1) == -1)
        {
            exit(0);
        }
        usleep(100);
    }
}

void serverhandler(int signum, siginfo_t *siginfo, void *context)
{
    (void)siginfo;
    (void)context;
    binaryToDecimal(signum == SIGUSR2, siginfo->si_pid);
}

int main(void)
{
    struct sigaction catch;

    ft_putstr_fd("Server PID : ", 1);
    ft_putnbr_fd(getpid(), 1);
    ft_putchar_fd('\n', 1);

    catch.sa_flags = SA_SIGINFO;
    catch.sa_sigaction = serverhandler;

    if (sigaction(SIGUSR1, &catch, NULL) == -1)
    {
        exit(1);
    }
    if (sigaction(SIGUSR2, &catch, NULL) == -1)
    {
        exit(1);
    }
    while (1)
    {
        pause();
    }
    return (0);
}