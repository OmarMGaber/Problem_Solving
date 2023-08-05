#include <bits/stdc++.h>
#include <fstream>
#include <string>

#ifndef ONLINE_JUDGE

//#include "LeetCode.cpp"
//#include "LeetCode.h"
#include "Useful_Subprograms.cpp"

#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define el '\n'
#define OmarMGaber return 0

#define vb    vector<bool>
#define vsh   vector<short>
#define vi    vector<int>
#define vii   vector<pair<int,int>>
#define vl    vector<long>
#define vll   vector<long long>
#define vllll vector<pair<long long,long long>>
#define vstr  vector<string>

#define tc ll t;cin >> t;while (t--)
#define ReadArray(v, n) loop(n - 1) { cin >> v[i]; }

#define loopFrom1To(n) for(int i = 1; i <= (n); i++)
#define loop(n) for(int i = 0; i <= (n); i++)

void InputOutput();

int main() {
    InputOutput();

    OmarMGaber;
}

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void fileInput() {
    freopen("in.txt", "r", stdin);
}

void fileOutput() {
    freopen("out.txt", "w", stdout);
}

void fileIO() {
    fileInput();
    fileOutput();
}

void InputOutput() {
    fastIO();
#ifndef ONLINE_JUDGE
    fileIO();
#endif
}


