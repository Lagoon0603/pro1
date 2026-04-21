#include <stdio.h>
#include <math.h>

struct vec3{
    float x;
    float y;
    float z;
};

float get_volume(struct vec3 v1, struct vec3 v2, struct vec3 v3){

    float volume = v1.x * (v2.y * v3.z - v3.y * v2.z) + v1.y * (v2.z * v3.x - v3.z * v2.x) + v1.z * (v2.x * v3.y - v3.x * v2.y);

    if(volume < 0)
        volume = -volume;
        
    return volume;
}


int main()
{
    struct vec3 v1, v2, v3;

    printf("input v1.x v1.y v1.z:");
    scanf("%f %f %f", &v1.x, &v1.y, &v1.z);

    printf("input v2.x v2.y v2.z:"); 
    scanf("%f %f %f", &v2.x, &v2.y, &v2.z);

    printf("input v3.x v3.y v3.z:"); 
    scanf("%f %f %f", &v3.x, &v3.y, &v3.z);

    float volume = get_volume(v1, v2, v3);

    printf("volume = %f\n", volume);
    return 0;
}