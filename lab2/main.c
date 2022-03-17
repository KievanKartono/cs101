#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
typedef struct lotto_record {
    int emp_id;
    int lotto_no;
    int lotto_receipt;
    char lotto_date[32];
    char lotto_time[32];
} lotto_record_t;

int main() {
    FILE* fp;
    char name[16];
    int T,a,n,operator[]={-1},b;
    lotto_record_t record[1];
    T=7;
    a=5;
    srand(T);
    time_t curtime;
    time(&curtime);
    printf("Operator Id (0-5)=");
    scanf("%d", &operator[0]);
    printf("Number (1-5)=");
    scanf("%d", &n);
    fp=fopen("operator_id.bin", "wb+");
    fwrite(operator, sizeof(int), sizeof(n), fp);
    fclose(fp);
    for (int i=1,j=0; j==0; i++) {
        sprintf(name, "lotto[%04d].txt",i);
        if (access(name,F_OK)!=0) {
            fp = fopen(name, "w+");
            fprintf(fp, "======= Lotto 659 ========\n");
            fprintf(fp, "=======+ No.%05d +======\n", i);
            b = i;
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
    fprintf(fp, "=======* Op.%05d *=========\n", operator[0]);
    fprintf(fp, "======= csie@CGU =========\n");
    fclose(fp);

    record[0].emp_id = operator[0];
    record[0].lotto_no = b;
    record[0].lotto_receipt = n*50*1.1;
    strftime(record[0].lotto_date, 100, "%Y%m%d", localtime(&curtime));
    strftime(record[0].lotto_time, 100, "%H:%M:%S", localtime(&curtime));
    fp=fopen("records.bin", "ab+");
    fwrite(record, sizeof(int), sizeof(record), fp);
    fclose(fp);

    printf("Your output will be at %s.txt\n", name);
    return 0;
}
