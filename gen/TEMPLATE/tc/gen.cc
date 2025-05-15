#include "testlib.h"
#include <cassert>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 0);
    int n = rnd.next(1, 1000);
    cout << n << endl;
}
