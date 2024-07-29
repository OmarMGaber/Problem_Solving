#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

//#include "LeetCode.cpp"
//#include "LeetCode.h"
//#include "Useful_Subprograms.cpp"

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

#define uset  unordered_set
#define umap  unordered_map
#define umset unordered_multiset
#define ummap unordered_multimap

#define yes  cout << "YES" << el;
#define no  cout << "NO" << el;

#define tc ll t;cin >> t;while (t--)
#define ReadArray(v, n) loop(n - 1) { cin >> v[i]; }

#define loopFrom1To(n) for(int i = 1; i <= (n); i++)
#define loop(n) for(int i = 0; i <= (n); i++)

void InputOutput();

double distanceBetween2Points(double &x1, double &y1, double &x2, double &y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

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
