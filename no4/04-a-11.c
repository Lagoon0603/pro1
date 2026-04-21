#include <stdio.h>
#include <stdlib.h>

void print_char_array(char *p, int n)
{
    int i;
    for (i = 0; i < n; i++){
        printf("%c", *p++);
    }
    printf("\n");
}

void print_char_reverse(char *p, int n)
{
    int i;
    char *end = p + n - 1;
    for (i = 0; i < n; i++){
        printf("%c", *end--);
    }
    printf("\n");
}

int main()
{
    char input_chars[32];
    int moji;
    int count = 0;

    printf("input string (maxlen = 32): ");

    for (count = 0; count < 32; count++) {
        moji = getchar();

        if (moji == '\n') {
            break;
        }

        *(input_chars + count) = moji;
    }

    printf("regular order: ");
    print_char_array(input_chars, count);

    printf("reverse order: ");
    print_char_reverse(input_chars, count);
    
    return 0;
}