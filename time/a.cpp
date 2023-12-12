#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    pid_t pid;
    printf("Begin\n");
    pid = fork();
    if (pid == 0)
    {
        execl("/bin/echo", "echo", "hello", 0);
        printf("I am the child process\n");
    }
    else if (pid > 0)
        printf("I am the parent process\n");
    return 0;
}
