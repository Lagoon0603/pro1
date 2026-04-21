#include <stdio.h>
#include <math.h>

struct circle{
    float x;
    float y;
    float r;
};

int circle_intersect(struct circle* c1, struct circle* c2){

    float dist_sq = (c1->x - c2->x) * (c1->x - c2->x) + (c1->y - c2->y) * (c1->y - c2->y);

    float r_sum = c1->r + c2->r;
    float r_sum_sq = r_sum * r_sum;

    float r_diff = c1->r - c2->r;
    float r_diff_sq = r_diff * r_diff;

    if (dist_sq > r_sum_sq) {
        return 0;
    } else if (dist_sq < r_diff_sq) {
        return 0;
    } else if (dist_sq == r_sum_sq || dist_sq == r_diff_sq) {
        return 1;
    } else {
        return 2;
    }
}


int main()
{
    struct circle c1, c2;

    printf("input c1.x c1.y c1.r:");
    scanf("%f %f %f", &c1.x, &c1.y, &c1.r);

    printf("input c2.x c2.y c2.r:");
    scanf("%f %f %f", &c2.x, &c2.y, &c2.r);

    int intersections = circle_intersect(&c1, &c2);

    printf("# of intersections = %d\n", intersections);
    return 0;
}