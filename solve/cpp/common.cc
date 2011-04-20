#include "common.hh"    
#include <iostream>
#include <sstream>
#include <new>

ofstream ofs;

char a[MAX];
int n;

char LAST;

static char *buffer;

int factorial(int n)
{
    int ret = 1;
    for (int i = n; i; --i)
    {
      ret *= i;
    }
    return ret;
}

static void optimize()
{
    int maxsize = 20 + factorial(n)*(n + 1);
    buffer = new char[maxsize];
    ofs.rdbuf()->pubsetbuf(buffer, maxsize);
}

void undo()
{
    for (int i = 0; i != n; ++i)
    {
        a[i] = FIRST + i;
    }
}

static void precompute()
{
    LAST = FIRST + n;
    undo();
}

void output(char *p)
{
    ofs.write(p, n);
    ofs.put(ENDL);
}

void output()
{
    output(a);
}

static int getargs(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Usage: " << argv[0] << " <size> [filename]" << endl;
        return 1;
    }
    istringstream iss(argv[1]); iss >> n;
    if (n < 1 || n > MAX)
    {
        cerr << "Constraint: 1 <= size <= " << MAX << " (got " << n << ")" << endl;
        return 1;
    }
    if (argc > 2)
    {
        ofs.open(argv[2]);
        if (!ofs.good())
        {
            cerr << "Cannot open " << argv[2] << " for writing" << endl;
            return 1;
        }
    }
    else
    {
        ofs.basic_ios<char>::rdbuf(cout.rdbuf());
    }
    return 0;
}

int init(int argc, char *argv[], bool ordered)
{
    if (getargs(argc, argv) == 0)
    {
        precompute();
        optimize();
        ofs << n << " " << (ordered ? "ordered" : "unordered") << endl;
        return 0;
    }
    return 1;
}

int final()
{
    ofs.close();
    delete buffer;
    return 0;
}
