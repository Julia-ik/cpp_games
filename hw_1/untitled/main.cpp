#include <cstdio>
#include <stdlib.h>

void print(int n) {
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n / 10 != 0)
    {
        print(n / 10);
    }

    putchar((n % 10) + '0');
}
int main()
{
    int k;
    bool is_success= false;
    while(!is_success)
    {
        printf("ent num(0-90)");
        scanf("%d", &k);
        fflush(stdout);

        if (k > 90 || k < 0)
        {
            printf("error\n");
            fflush(stdout);
        }
        else {
            print(rand() % k);
            printf("\n");
            fflush(stdout);
            is_success=true;
        }
    }

    return 0;
}