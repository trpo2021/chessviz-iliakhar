#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE* fp;
    // printf("$ %s $",argv[1]);
    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    char a[20];
    while (fgets(a, 20, fp)) {
        // fgets(a,20,fp);
        printf("%s", a);
    }
}