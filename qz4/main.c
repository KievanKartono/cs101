#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int swap(int* i, int*j) {
    int tmp;
    tmp = *i;
    *i = *j;
    *j = tmp;
}

int swapArray(int* source, int* dest, int size) {
    for(int i=0; i < size; i++) {
        swap(&source[i], &dest[i]);
    }
}

int printArray(int* source, int size) {
    for(int i=0; i < 10; i++) {
        if(i != size-1) {
            printf("%i, ", source[i]);
        } else {
            printf("%i]\n", source[i]);
        }   
    }
}

char* copy_string(char* s) {
    char* s2;
    s2 = (char*)malloc(20);
    strcpy(s2,s);
    return(char*)s2;
}

void function1() {
    int n, m;
    n=1;
    m=2;
    swap(&n,&m);
    printf("after swap, n=%d, m=%d\n", n, m);
}

void function2() {
    int size = 10;
    int source[10] = {0,9,8,7,6,5,4,3,2,1};
    int dest[10] = {10,20,30,40,50,60,70,80,90,100};
    swapArray(source, dest, size);
    printf("after swap array, source array = [");
    printArray(source, size);
    printf("after swap array, dest array = [");
    printArray(dest, size);
}

void function3() {
    char str[] = "IU!IU!IU!IU!";
    char* cp_str = copy_string(str);
    printf("copy string = %s\n", cp_str);
    free(cp_str);
}

int main() {
    printf("No.1 ----------------\n");
    function1();
    printf("No.2 ----------------\n");
    function2();
    printf("No.3 ----------------\n");
    function3();
    return 0;
}
