#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
  long long int i = 0;
  int status;
  int count = 1;

  while(1)
  {
  int ret = fork();
   if(ret == -1)

     {

        printf("Maximum fork limit reached\n");
        _exit(-1);
      }
    else if(ret == 0)
    {

       printf("Return value : %d\n",ret);
       _exit(0); 
        }
     
     else
      {
       count++;
       printf("child[%d] : count-> %d\n",getpid(),count);
      }
      }
     printf("Program Finished!!!\n");
     return 0;

    }
