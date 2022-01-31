#include "minitalk.h"

size_t charnum = 0;

size_t          ft_strlen(const char *str)
{
    size_t      index;

    index = 0;
    while (str[index] != '\0')
    {
        index++;
    }
    return (index);
}

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
void decimalToBin(int pid, char message)
{
    int result;
    int i;

	result = 0;
    i = 7;
    while (i >= 0)//8bit까지 표현
    {
        result = message >> i & 1;//>>연산 후 &연산하기.
        if (result == 0)
        {
            if (kill(pid, SIGUSR1) == -1)
            {
                printf("failed to send message\n");
                exit(0);
            }
        }
        else if (result == 1)
        {
            if (kill(pid, SIGUSR2) == -1)//kill을 했을 때 -1이면 에러
            {
                printf("failed to send message\n");
                exit(0);
            }
        }
        i--;
        usleep(100);
    }
}

void send_message(int pid, char *message)
{
    int index;

    index = 0;
    while (message[index] != '\0')
    {
        decimalToBin(pid, message[index]);
        index++;
    }
    return ;
}

void clienthandler(int signum, siginfo_t *siginfo, void *context)
{
    (void)signum;
    (void)siginfo;
    (void)context;
    charnum++;
}

int main(int argc, char **argv)
{
    struct sigaction catch;
    charnum = 0;

    catch.sa_flags = SA_SIGINFO;
    catch.sa_sigaction = clienthandler;//핸들러를 내 핸들러로 지정

    if (sigaction(SIGUSR1, &catch, NULL) == -1)//SIGUSR1이 들어왔을 때 handler로 처리
    {
        exit (1);
    }
    if (sigaction(SIGUSR2, &catch, NULL) == -1)//SIGUSR2가 들어왔을 때 handler로 처리 sigaction(signum, act, oldact);
    {
        exit (1);
    }
    if (argc != 3)//인자 3개 아닐 때
    {
        printf("invalid arguement number\n");
        exit (1);
    }
    else
    {
        send_message(atoi(argv[1]), argv[2]);
        usleep(100);
        if (charnum != ft_strlen(argv[2]))
        {
            write(1, "receive error\n", 15);
            return (1);
        }
        else
        {
            write(1, "message received\n", 18);
        }
        //argv[1]에는 pid, argv[2]에는 보낼 문자열 있음. 서버가 pid를 출력하면 이를 긁어서 클라이언트가 pid 뒤에 문자열 보내서 서버로 뜨게 함
    }
    return (1);
}