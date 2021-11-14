#include <cstdio>
#include <cstdlib>
#include <cctype>

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
        k = getchar();
        int num = 0;
        while (isdigit(k))
        {
            num = (num * 10) + (k - '0');
            k = getchar();
        }

        if (num > 90 || num < 0)
        {
            printf("error\n");
        }
        else {
            print(rand() % num);
            printf("\n");
            fflush(stdout);
            is_success=true;
        }
    }

    return EXIT_SUCCESS;
}