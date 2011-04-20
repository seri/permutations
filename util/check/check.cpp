#include <iostream>
#include <fstream>
#include <set>
using namespace std;

ifstream ifs;

int n;
const int MAX = 12;

const char START = 'a';
      char FINISH; 

int factorial(int k)
{
    int ret = 1;
    for (int i = 2; i <= k; ++i) 
    {
        ret *= i;
    }
    return ret;
}

bool check_perm(string &line)
{
    bool used[256];
    fill(used, used + 256, false); 
    for (string::iterator it = line.begin(); it != line.end(); ++it)
    {
        if (*it < START || *it > FINISH || used[*it]) return false;
        used[*it] = true;
    } 
    return line.size() == n;
}

bool check_unordered()
{ 
    set<string> perms; 
    string line;
    int count = 0; 
    while (getline(ifs, line))
    {
        if (line.empty()) break;
        if (!check_perm(line)) return false;
        if (!perms.insert(line).second) return false;
        ++count;
    } 
    return count == factorial(n);
}

bool check_ordered()
{
    string prev = "", next;
    int count = 0; 
    while (getline(ifs, next))
    {
        if (next.empty()) break;
        if (!check_perm(next)) return false;
        if (prev >= next) return false;
        prev = next; ++count;
    } 
    return count == factorial(n);
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cerr << "Usage: check <file-to-check>" << endl;
        return 1;
    } 
    bool passed = false;
    ifs.open(argv[1]); 
    try
    { 
        ifs >> n; FINISH = START + n - 1; 
        string type; ifs >> type; 
        string line; getline(ifs, line);
        passed = (type == "ordered" ? check_ordered() : check_unordered());
        ifs.close(); 
    } 
    catch (exception e)
    {
        cerr << e.what() << endl;
    }
    cout << (passed ? "Passed" : "Failed") << endl;
    return passed ? 0 : 1;
}
