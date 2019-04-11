#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    char p[20];
    char q[20];
    strcpy(p, "192.168.0.113");
    strcpy(q, "192.168.0.112");
    printf("%s\n", p);
    printf("%s\n", q);
    if(strcmp(p, q) == 0){
        printf("equal\n");
    } else {
        printf("not equal\n");
    }
    return 0;
}
