#include "common.hh"

void recurse(int k)
{
    if (k == 0)
    {
        output();
    } 
    else
    { 
        for (int i = 0; i <= k; ++i)
        {
            char temp = a[i];
            a[i] = a[k];
            a[k] = temp;
            recurse(k - 1);
            a[k] = a[i];
            a[i] = temp;
        } 
    }
}

int main(int argc, char *argv[])
{
    if (init(argc, argv, UNORDERED) == 0)
    { 
        recurse(n - 1); 
        return final();
    }
    return 1;
}
