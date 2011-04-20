#include "common.hh"

bool b[256];

void recurse(int i)
{
    if (i == n)
    {
        output();
    }
    else
    {
        for (int c = FIRST; c != LAST; ++c)
        {
            if (b[c])
            {
                a[i] = c;
                b[c] = false;
                recurse(i + 1);
                b[c] = true;
            }
        }       
    } 
}

int main(int argc, char *argv[])
{
	if (init(argc, argv, ORDERED) == 0)
    {
        fill(b, b + 256, true);
        recurse(0); 
        return final();
    }
    return 1;
}
