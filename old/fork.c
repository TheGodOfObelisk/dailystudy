#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
 /*  �˰汾�����������ӽ��̽���֮�������*/
void error_msg(char *msg){
    fprintf(stderr, "%s: %d\n", msg, strerror(errno));
    exit(0);
}
 
int Fork(){
    pid_t pid;
    if ( ( pid = fork() ) < 0 )
        error_msg("fork failed");
    return pid;
}
 
void main(){
 
    pid_t pid;
 
    fprintf(stdout, "I am the first process, my pid is %d, my parent pid is %d\n", getpid(), getppid());
 
    pid = Fork();
    if ( 0 == pid ){
    	sleep(2);
    	fprintf(stdout, "\nI am the child procress, my pid value is %d, but my real pid is %d, my parent pid is %d\n", pid, getpid(), getppid());
    }
        
    else if (pid > 0){
    	sleep(5);//������������5�룬���ӽ��̽������ټ������� 
    	fprintf(stdout,"I am the parent process, my child pid is %d, my pid is %d, my parent pid is %d\n", pid, getpid(), getppid());
    } else {
        printf("error!\n");
    }
}
        