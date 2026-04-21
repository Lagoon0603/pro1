#include <stdio.h>
#include <stdlib.h>

float to_oz(float f){
    float oz;

    oz = f / 28.3;
    return oz;
}

float to_g(float f){
    float g;

    g = f * 28.3;
    return g;
}

int main()
{
    float f;
    char c;

    printf("input oz(o) or gram(g):");

    if (scanf("%f%c", &f, &c) != 2) {
    printf("incorrect input");
    exit(1);
    }else{
        if(c == 'o'){
            float g = to_g(f);
            printf("%.6foz is %.6fg\n", f, g);
        }
        else if(c == 'g'){
            float oz =to_oz(f);
            printf("%.6fg is %.6foz\n", f, oz);
        }
    }
    return 0;
}