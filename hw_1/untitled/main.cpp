#include <cstdio>
#include <cstdlib>
#include <cctype>
int scan()
{
    int k;
    int num=0;
    k = getchar();
    while (isdigit(k))
    {
        num = (num * 10) + (k - '0');
        k = getchar();
    }

    return num;
}
void print(int n)
{
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
    int num;
    bool is_success= false;
    while(!is_success)
    {
        printf("ent num(0-90)");
        fflush(stdout);
        num = scan();

        if (num > 90 || num < 0)
        {
            printf("error\n");
            fflush(stdout);
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