#include <stdio.h>
void rec_dec (char* s) {
    if(*(s) != 0) {
        printf("%c,", s[0]);
        rec_dec(++s);
    }
    return;
}

void towers(int n, char from, char to, char aux){
    if (n == 1) {
        FILE* fp = fopen("hanoi.txt", "a+");
        fprintf(fp,"Move disk 1 from rod %c to rod %c\n", from, to);
        fclose(fp);
        return;
    }
    towers(n-1, from, aux, to);
    FILE* fp = fopen("hanoi.txt", "a+");
    fprintf(fp, "Move disk %d from rod %c to rod %c\n", n, from, to);
    fclose(fp);
    towers(n-1, aux, to, from);
    return;
}

void Tower_Hanoi (int amount) {
    FILE* fp;
    if ((fp = fopen("hanoi.txt", "r+")) == NULL) {
        fp = fopen("hanoi.txt", "w+");
        fclose(fp);
        
        towers(amount, 'A', 'C', 'B');
        fp = fopen("hanoi.txt", "a+");
        fprintf(fp,"\n\n\n\n\n\n\n");
        fclose(fp);
    } else {
        towers(amount, 'A', 'C', 'B');
        fp = fopen("hanoi.txt", "a+");
        fprintf(fp, "\n==================\n");
        fclose(fp);
    }
    return;
}

void multiplication (int i, int j) {
    printf("%d*%d=%d\t", i, j, i*j);
    if (j < 9) {
        multiplication(i, j+1);
        return;
    } else {
        if (i < 9) {
            printf("\n");
            multiplication(i+1, j-8);
            return;
        }
    }
    return;
}

int main () {
    char s[] = "1234567890";
    rec_dec(s);
    printf("\nfunction#1------------\n");
    Tower_Hanoi(16);
    printf("\nfunction#2------------\n");
    multiplication(1, 1);
    printf("\nfunction#3------------\n");
    return 0;
}
