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
  FILE* fp, * rfp = fopen("records.bin", "r");
  char now[9], dates[9] = "";
  int slots = 0, receipts = 0, tdates = 1, tslots = 0, treceipts = 0;
  lotto_record_t record[1];
  time_t dates = time(NULL);
  srand((unsigned)time(NULL));
  if (rfp == NULL) {
    printf("Empty record\nReport will not be generated\n");
    return 0;
  } else fp = fopen("report.txt", "w+");
  fprintf(fp, "========= lotto649 Report =========\n");
  fprintf(fp, "- Date ------ Num. ------ Receipt -\n");
  for (int i = 0; fread(record, sizeof(lotto_record_t), sizeof(record) / sizeof(record[0]), rfp); i++) {
    if (dates[0] == '\0' || strcmp(dates, record[0].lotto_date) == 0) {
      sprintf(dates, "%s", record[0].lotto_date);
      slots++;
      receipts += record[0].lotto_receipt;
      tslots++;
      treceipts += record[0].lotto_receipt;
    } else if (strcmp(dates, record[0].lotto_date) != 0) {
      fprintf(fp, "%s\t%d/%d\t\t%d\n", dates, slots, receipts / 55, receipts);
      sprintf(dates, "%s", record[0].lotto_date);
      slots = 1;
      receipts = record[0].lotto_receipt;
      tdates++;
      tslots++;
      treceipts += record[0].lotto_receipt;
    };
  };
  fprintf(fp, "%s\t%d/%d\t\t%d\n", dates, slots, receipts / 55, receipts);
  fclose(rfp);
  fprintf(fp, "-----------------------------------\n");
  fprintf(fp, "       %d\t%d/%d\t\t%d\n", tdates, tslots, treceipts / 55, treceipts);
  strftime(now, 100, "%Y%m%d", localtime(&date));
  fprintf(fp, "======== %s Printed =========\n", now);
  fclose(fp);
  return 0;
}
