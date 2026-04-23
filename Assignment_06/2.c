#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    printf("Program started !!! PID=%d\n", getpid());

    int a = fork();

    if(a == 0)
    {
        
        printf("Process B PID=%d PPID=%d\n", getpid(), getppid());

        int b = fork(); 

        if(b == 0)
        {
        
            printf("Process C PID=%d PPID=%d\n", getpid(), getppid());

            int c = fork();  

            if(c == 0)
            {
                
                printf("Process D PID=%d PPID=%d\n", getpid(), getppid());

                sleep(5);
                printf("Process D Finished PID=%d\n", getpid());
                _exit(0);
            }

            sleep(5);
            waitpid(c, NULL, 0);
            printf("Process C Finished PID=%d\n", getpid());
            _exit(0);
        }

        sleep(5);
        waitpid(b, NULL, 0);
        printf("Process B Finished PID=%d\n", getpid());
        _exit(0);
    }

   
    sleep(5);
    waitpid(a, NULL, 0);
    printf("Process A Finished PID=%d\n", getpid());

    return 0;
}
