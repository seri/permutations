#include "common.hh"

void recurse(char c)
{
    if (c == LAST)
    {
        output();
    }
    else
    { 
        for (int i = 0; i != n; ++i)
        {
            if (a[i] == 0)
            {
                a[i] = c;
                recurse(c + 1);
                a[i] = 0;
            }
        } 
    }
}

int main(int argc, char *argv[])
{
	if (init(argc, argv, UNORDERED) == 0)
    {
        fill(a, a + n, 0);
        recurse(FIRST); 
        return final(); 
    }
    return 1;
}
