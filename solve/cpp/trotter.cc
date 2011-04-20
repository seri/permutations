#include "common.hh"

int d[MAX + 1];
char b[MAX + 2];

void precompute()
{
    fill(d, d + n + 1, -1); 

    b[0] = LAST;
    for (int i = 1; i <= n; ++i)
    {
        b[i] = FIRST + i - 1;
    } 
    b[n + 1] = LAST;    
}

void trotter()
{
	while (true)
	{
        output(b + 1);

		int maxi = 0; char maxv = 0;
		for (int i = 1; i <= n; ++i)
        {	
            if (b[i] > b[i + d[i]] && b[i] > maxv) 
            { 
                maxi = i;
                maxv = b[i];
            } 
        }
        if (maxi == 0) break; 

        int i = maxi + d[maxi];
		swap(b[maxi], b[i]);
		swap(d[maxi], d[i]);

		for (int i = 1; i <= n; ++i)
		{
			if (b[i] > maxv) 
            { 
                d[i] *= (-1);
            }
		}
	}
}

int main(int argc, char *argv[])
{
	if (init(argc, argv, UNORDERED) == 0)
    { 
        precompute(); 
        trotter();       
        return final();
    } 
    return 0;
}

