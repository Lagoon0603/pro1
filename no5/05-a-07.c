#include <stdio.h>

struct mydate {
    int year;
    int month;
    int date;
};

struct vec3 {
    float x;
    float y;
    float z;
};

int main() {
    
    printf("char %lu byte\n", sizeof(char));
    printf("int %lu byte\n", sizeof(int));
    printf("float %lu byte\n", sizeof(float));
    printf("struct mydate %lu byte\n", sizeof(struct mydate));
    printf("struct vec3 %lu byte\n", sizeof(struct vec3));

    return 0;
}