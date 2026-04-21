/* explain why this code is incorrect.
一つのメモリ領域を複数のポインタが指している場合、いずれか一つのポインタを使って。free()を
呼び出すと、そのメモリ領域は解放されてしまう。
その後、他のポインタ（この場合はq）を使ってそのメモリにアクセスしてしまうと、
開放済みメモリにアクセスしようとするという未定義動作を行うことになり、エラーとなるから。

*/
#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
};

void print_point(struct point *p)
{
    if (p != NULL)
        printf("(%d, %d)\n", p->x, p->y);
    else
        printf("no point\n");
}

int main()
{
    struct point *p, *q;

    p = (struct point *)malloc(sizeof(struct point));
    p->x = 10;
    p->y = 5;
    q = p;

    print_point(p);
    free(p);
    print_point(q);

    return 0;
}
