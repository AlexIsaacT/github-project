#include <stdio.h>
#define MAX 1000
#define IN 1
#define OUT 0

int sum(int num1, int num2); // declaration

int main()
{
        char buffer[MAX];
        int cc = 0, pc = 0, in_single_comment = OUT;
        int buffer_length = 0;
        for (int i = 0; i < MAX; i++){
          buffer[i] = 0;
        }
        while(cc = getchar() != EOF) {
    
        }

        return 0;
}

// function definition
int sum(int num1, int num2) {
        return num1 + num2;
}
