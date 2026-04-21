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

void check_palindrome(char *p, int n)
{
    int i;

    for (i = 0; i < n / 2; i++) {
        if (*(p + i) != *(p + n - 1 - i)) {
            printf("No...\n");
            return;
        }
    }

    printf("Yes! Palindrome!\n");
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

    printf("   input string: ");
    print_char_array(input_chars, count);

    printf("reversed string: ");
    print_char_reverse(input_chars, count);

    check_palindrome(input_chars, count);
    
    return 0;
}