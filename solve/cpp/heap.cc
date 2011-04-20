#include "common.hh"

void recurse(int k)
{
	if (k == 0)
	{
		output();
	} 
    else
    { 
        if (k&1) 
        {
            for (int i = 0; i != k; ++i) 
            {
                recurse(k - 1);
                swap(a[i], a[k]);
            } 
        }
        else
        {
            for (int i = 0; i != k; ++i) 
            {
                recurse(k - 1);
                swap(a[0], a[k]);
            } 
        } 
        recurse(k - 1); 
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
