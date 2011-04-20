#include <fstream>
#include <algorithm>
using namespace std;

extern ofstream ofs;

const int MAX = 12;
extern char a[MAX];
extern int n;

const char ENDL = '\n', 
           FIRST = 'a';
extern char LAST;

const bool ORDERED = true, 
           UNORDERED = false;

int init(int argc, char *argv[], bool ordered);
int final(); 
void output();
void output(char *p);
void undo();

int factorial(int n);
