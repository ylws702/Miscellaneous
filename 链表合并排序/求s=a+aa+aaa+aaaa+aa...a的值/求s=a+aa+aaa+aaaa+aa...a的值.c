// 求s=a+aa+aaa+aaaa+aa...a的值.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct MyStruct
{
    int m, e;
    char *s;
}p[20];
void swap(struct MyStruct*a, struct MyStruct*b)
{
    int t;
    char*tmp;
    t = a->e;
    a->e = b->e;
    b->e = t;
    t = a->m;
    a->m = b->m;
    b->m = t;
    tmp = a->s;
    a->s = b->s;
    b->s = tmp;
}
int main()
{
    int n, i, j, m = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        p[i].s = (char*)malloc(20 * sizeof(char));
        scanf("%s%d%d", p[i].s, &p[i].m, &p[i].e);
    }
    for (i = 0; i < n; i++)
        for (j = i; j < n - 1; j++)
            if (((p[j]).m + (p[j]).e) < ((p[j + 1]).m + (p[j + 1]).e))
                swap(&(p[j]), &(p[j + 1]));
    for (i = 0; i < n; i++)
        printf("%s %d\n", p[i].s, p[i].m + p[i].e);
    return 0;
}

