#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    FILE* fp;
    char name[16];
    int n,T,a;
    T=6;
    n=2;
    a=5;
    srand(T);
    time_t curtime;
    time(&curtime);
    sprintf(name, "lotto.txt");
    fp = fopen(name, "w+");
    if(n>5) {
        fprintf(fp, "Invalid number!");
    } else {
    fprintf(fp, "======= Lotto 659 ========\n");
    fprintf(fp, "%s", ctime(&curtime));
    for(int j=1; j<a+1; j++) {
        fprintf(fp, "[%d]: ", j);
        if(j<n+1) {
        for(int i=0; i<T; i++) {
            if(i < 5) {
                fprintf(fp, "%02d ", rand() % 69);
            } else {
                fprintf(fp, "%02d ", rand() % 10);
            }
        }
    } else {
    for(int i=0; i<T; i++) {
        fprintf(fp, "-- ");
    }
}
    fprintf(fp, "\n");
    }
    fprintf(fp, "======= csie@CGU =========\n");
}
    fclose(fp);
    return 0;
}