#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(void)
{
    int ret, s;
    printf("program started !!!\n");

    ret = fork();

    if(ret == 0)
    {
        execlp("google-chrome", "google-chrome", "https://www.google.com", NULL);

        perror("execlp failed");
        exit(1);
    }
    else
    {
        wait(&s);
        printf("exit status of child process : %d\n", WEXITSTATUS(s));
    }

    printf("program finished !!!\n");
    return 0;
}
