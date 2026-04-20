#include<stdio.h>
#include<unistd.h>
#include<wait.h>
#include<stdlib.h>

int main()
{
int child = 5,status;
int pid[child];
 for(int i = 0; i< child; i++)
 {
  pid[i] = fork();
  if(pid[i] == 0)
  {
 for(int i = 0;i < child; i++)
 {
   printf("child = %d  count -> %d\n",getpid(),i);
  sleep(1);
 }
 exit(0);
  }
 }
  for(int i = 1;i < child; i++)
  {
    waitpid(pid[i],&status,0);
    printf("Parent :child %d completed\n",pid[i]);
   }
    printf("Parent PID : %d\n",getpid());
  
    return 0;
 }
