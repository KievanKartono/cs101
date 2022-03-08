#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main() {
    FILE* fp;
    char name[16];
    int T,a, n;
    T=7;
    a=5;
    srand(T);
    time_t curtime;
    time(&curtime);
    printf("n=");
    scanf("%d", &n);
    for (int i=1,j=0; j==0; i++) {
        sprintf(name, "lotto[%04d].txt",i);
        if (access(name,F_OK)!=0) {
            fp = fopen(name, "w+");
            fprintf(fp, "======= Lotto 659 ========\n");
            fprintf(fp, "=======+ No.%05d +======\n", i);
            j=1;
        };
    }
    fprintf(fp, "%s", ctime(&curtime));
    for(int j=1; j<a+1; j++) {
        fprintf(fp, "[%d]: ", j);
        if(j<n+1) {
        for(int k=0; k<T; k++) {
            if(k < 5) {
                fprintf(fp, "%02d ", rand() % 69);
            } else {
                fprintf(fp, "%02d ", rand() % 10);
            }
        }
    } else {
    for(int k=0; k<T; k++) {
        fprintf(fp, "-- ");
    }
}
    fprintf(fp, "\n");
    }
    fprintf(fp, "======= csie@CGU =========\n");
    fclose(fp);
    return 0;
}