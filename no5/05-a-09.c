/* explain why this code is incorrect.
struct point *p;:
ポインタ変数 p は宣言されているが、初期化されていない。

struct point *q = NULL;:
ポインタ変数 q は NULL で初期化されている。NULL は、どこも指していないことを明示的に示す特別な値であるため、不正なメモリアクセスとなってクラッシュするから。
*/
#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
};

void print_point(struct point *p)
{
    printf("(%d, %d)\n", p->x, p->y);
}

int main()
{
    struct point *p, *q = NULL;

    print_point(p);
    print_point(q);

    return 0;
}
