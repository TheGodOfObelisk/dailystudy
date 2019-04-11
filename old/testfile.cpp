#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main(int argc, char const *argv[])
{
    FILE *fp = NULL;
    char *FileName = "testfile";
    char wordline[512];
    char gate[32];

    memset(gate, 0, sizeof(gate));
    
    fp = fopen(FileName, "r");
    if (NULL == fp){
        printf("failed to open file...\n");
        exit(1);
    }

    memset(wordline, 0, sizeof(wordline));
    fgets(wordline, 511, fp);
    
    printf("wordline: %s", wordline);
    printf("\n\n");
    sscanf(wordline, "%s", gate);
    fclose(fp);

    if(0 != strlen(gate)){
        
        printf("gate: %s", gate);
        return 1;
    }
    return 0;
}
