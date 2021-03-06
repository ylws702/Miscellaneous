// 链表合并排序.c: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct node
{
    struct node *next;
    int num, prf;
}a, b, *t, *a_start, *b_start, *start, *t0, *tmp;
typedef struct node node;
int main()
{
    int i, n, m;
    size_t size = sizeof(node);
    scanf("%d%d", &n, &m);
    t = a_start = (struct node*)malloc(size);
    scanf("%d%d", &t->num, &t->prf);
    for (i = 1; i < n; i++)
    {
        t->next = (node*)malloc(size);
        t = t->next;
        scanf("%d%d", &t->num, &t->prf);
    }
    t->next = 0;
    t = b_start = (node*)malloc(size);
    scanf("%d%d", &t->num, &t->prf);
    for (i = 1; i < m; i++)
    {
        t->next = (node*)malloc(size);
        t = t->next;
        scanf("%d%d", &t->num, &t->prf);
    }
    t->next = a_start;
    t0 = start = (node*)malloc(size);
    t = b_start;
    t0->num = t->num;
    t0->prf = t->prf;
    t0->next = 0;
    while (t = t->next)
    {
        t0 = start;
        if (t0->num > t->num)
        {
            tmp = start;
            start = (node*)malloc(size);
            start->num = t->num;
            start->prf = t->prf;
            start->next = tmp;
            continue;
        }
        while (1)
        {
            if (t0->next == 0)
            {
                t0->next = (node*)malloc(size);
                t0 = t0->next;
                t0->num = t->num;
                t0->prf = t->prf;
                t0->next = 0;
                break;
            }
            if (t0->next->num > t->num)
            {
                tmp = t0->next;
                t0->next = (node*)malloc(size);
                t0 = t0->next;
                t0->num = t->num;
                t0->prf = t->prf;
                t0->next = tmp;
                break;
            }
            t0 = t0->next;
        }
    }
    t = start;
    while (t = t->next) printf("%d %d\n", t->num, t->prf);
    return 0;
}

