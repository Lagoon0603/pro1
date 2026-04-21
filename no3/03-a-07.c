#define TEXT_LEN 14
#include <stdio.h>
#include <stdlib.h>

char plain_text[TEXT_LEN]
= {'k', 'e', 'i', 'o', 'u', 'n', 'i', 'v', 'e', 'r', 's', 'i', 't', 'y'};

int key;

int main(){
    
    printf("input key[1-25]:");
    scanf("%d", &key);

    if(key > 25 || key < 1){
        printf("key should be 1-25\n");
        exit(1);
    }else{
        for(int i = 0; i < 14; i++){
            int num;
            char moji;
            num = plain_text[i] + key;
            moji = num;
            if(num > 'z'){
                num = num - 26;
                moji = num;
            }
            printf("%c", moji);
        }
    printf("\n");
    }
    return 0;
}