#include <stdio.h>

int take(int x, int y, int z)
{
    if (x <= y) {
        return y;
    } else {
        return take(take(x - 1, y, z), take(y - 1, z, x), take(z - 1, x, y));
    }
}

int main(void)
{
    int x, y, z;
    printf("input three integers: ");
    scanf("%d %d %d", &x, &y, &z);

    printf("T(%d, %d, %d) = %d\n", x, y, z, take(x, y, z));

    return 0;
}


/*
 推測:
 この関数 T(x, y, z) は、以下の値を返すと考えられる。
 x <= y のときは y
 y <= z のときは z
 それ以外のときは x
 */
