/* explain why this code is incorrect.
set_point関数内でmallocを使ってメモリが動的に確保され、そのアドレスがローカルポインタ変数pに格納されるが、
pはset_point関数内でのみ有効なローカル変数であるため、set_point関数が終了するとローカル変数pは自動的に消滅する。
pが消滅すると、mallocで確保したメモリ領域を指すポインタがプログラム上から失われてしまいまい、
結果として、確保したメモリにアクセスすることも、free()で解放することもできなくなる。
*/
#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
};

void set_point(int x, int y)
{
    struct point *p;

    if ((p = (struct point *)malloc(sizeof(struct point))) == NULL) {
        printf("out of memory\n");
        exit(1);
    }

    p->x = x;
    p->y = y;
}

int main()
{
    set_point(1, 3);
    return 0;
}
