#include "apue.h"

int main(void){
    pid_t pid;

    if((pid = fork()) < 0)
        err_sys("fork error");
    else if(pid != 0){  /* parent */
        sleep(2);
        exit(2);    /* terminate with exit status 2 */
    }

    if((pid = fork()) < 0)
        err_sys("fork error");  /* first child */
    else if(pid != 0){
        sleep(4);
        abort();    /* terminate with core dump */
    }

    if((pid = fork()) < 0)
        err_sys("fork error");
    else if(pid != 0){  /* third child */
        sleep(8);
        exit(0);
    }

    sleep(6);       /* fourth child */
    kill(getpid(), SIGKILL);    /* terminate w/signal, no core dump */
    exit(6);        /* shouldn't get here */
}