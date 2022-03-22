#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct lotto_record {
    int emp_id;
    int lotto_no;
    int lotto_receipt;
    char lotto_date[32];
    char lotto_time[32];
} lotto_record_t;

int main() {
    FILE* rfp = fopen("records.bin", "r");
    lotto_record_t record[1];
    int i=0;
    printf("========== lotto659 Report =========\n");
    printf("- Date ------ Num. ------ Receipt -\n");
    while(fread(&record[0], sizeof(lotto_record_t), 1, rfp)) {
        printf("%s      %d/50           %d\n", record[0].lotto_date, record[0].lotto_no, record[0].lotto_receipt);
        i++;
    }
    fclose(rfp);
    printf("------------------------------------\n");
    printf("==========  Printed =========\n");
    return 0;
}
