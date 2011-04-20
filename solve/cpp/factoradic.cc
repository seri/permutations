#include "common.hh"

int f[MAX];

void precompute()
{
    f[0] = 1;
    for (int i = 1; i != n; ++i)
    {
        f[i] = f[i - 1] * i;
    }
}

void permute(int k)
{
    for (int i = 0; i != n; ++i)
    {
        int j = i + k/f[n - 1 - i];

        char c = a[j];
        for (; j != i; --j)
        {
            a[j] = a[j - 1];
        } 
        a[i] = c;

        k %= f[n - 1 - i];
    }
}

int main(int argc, char *argv[])
{
    if (init(argc, argv, ORDERED) == 0)
    { 
        precompute(); 
        for (int i = 0; i != f[n - 1]*n; ++i)
        {
            undo();
            permute(i);
            output();
        } 
        return final();       
    }
    return 1; 
}
