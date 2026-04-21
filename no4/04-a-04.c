/* explain here why this program is not correct
変数qが初期化されることなく使用されているため、どのメモリアドレスを指すかが不確かである。
そのため、この状態でpointer_assign関数を呼び出すとアドレスが不明なメモリにXの値を書き込もうとしてしまうためエラーとなる。
*/

#include <stdio.h>
#include <stdlib.h>

void pointer_assign(int *p, int x)
{
    *p = x;
}

int main()
{
    int *q;
    pointer_assign(q, 100);

    return 0;
}
