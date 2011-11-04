#include "common.hh"

void permute(int k) {
    for (int i = 2; i <= n; ++i) {
        swap(a[i - 1], a[k%i]);
        k /= i;
    }
}

int main(int argc, char *argv[]) {
    if (init(argc, argv, UNORDERED) == 0) {
        for (int i = 0; i != factorial(n); ++i) {
            undo();
            permute(i);
            output();
        }
        return final();
    }
    return 1;
}
