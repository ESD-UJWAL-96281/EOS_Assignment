#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/wait.h>
#include<sys/types.h>

#define MSG_KEY 0x1234

#define REQ  1
#define RESP 2

typedef struct msgbuff
{
    long mtype;
    float op1;
    float op2;
    float res;
    int err;
    char ch;
}msg_t;

int msgid;

void sigchld(int sig)
{
    waitpid(-1, NULL, WNOHANG);

    
}

int main()
{
   

    msgid = msgget(MSG_KEY, 0600);
    if(msgid != -1)
    {
        msgctl(msgid, IPC_RMID, NULL);
    }
    msgid = msgget(MSG_KEY, IPC_CREAT | IPC_EXCL | 0600);
    
    if(msgid == -1)
    {
        perror("msgget failed");
        _exit(1);
    }

    int pid = fork();

    if(pid > 0)
    {
     
        msg_t m2 = {0};
        int ret = msgrcv(msgid, &m2, sizeof(msg_t), REQ, 0);
        if(ret == -1)
        {
            perror("msgrcv erro");
            _exit(ret);
        }

        if(m2.ch == '+')
        {
            m2.res = m2.op1 + m2.op2;
        }
        else if(m2.ch == '-')
        {
            m2.res = m2.op1 - m2.op2;
        }
        else if(m2.ch == '*')
        {
            m2.res = m2.op1 * m2.op2;
        }
        else if(m2.ch == '/')
        {
            if(m2.op2 == 0)
            {
                m2.err = 1;
            }
            else
            m2.res = m2.op1 / m2.op2;
        }

        m2.mtype = RESP;
        ret = msgsnd(msgid, &m2, sizeof(msg_t), 0);
        if(ret == -1)
        {
            perror("msgsnd failed");
            _exit(ret);
        }

        wait(NULL);  
        msgctl(msgid, IPC_RMID, NULL);   
    }
    else if(pid == 0)
    {
        msg_t m1 = {0};
        printf("Child [%d]\n", getpid());
        printf("op1 = "); scanf("%f", &m1.op1);
        printf("Operator = "); scanf(" %c", &m1.ch);
        printf("op2 = "); scanf("%f", &m1.op2);
        m1.mtype = REQ;

        int ret = msgsnd(msgid, &m1, sizeof(msg_t) , 0);
        if(ret == -1)
        {
            perror("msgsnd failed");
            _exit(ret);
        }

        printf("Child [%d] : Message sent Successfully\n", getpid());


        ret = msgrcv(msgid, &m1, sizeof(msg_t), RESP, 0);
        if(ret == -1)
        {
            perror("msgrcv failed");
            _exit(ret);
        }

        if(m1.err != 1)
        {
            printf("Child [%d] Data recieved!\n", getpid());
            printf("%.2f %c %.2f = %.2f\n", m1.op1, m1.ch, m1.op2, m1.res);
          
        }
        else
        {
            printf("Divide by Zero error\n");
        }

        _exit(0);
    }

    return 0;
}
