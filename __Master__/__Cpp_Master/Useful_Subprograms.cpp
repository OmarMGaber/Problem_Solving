#include <iostream>
#include <fstream>
#include <stack>
#include <iomanip>
#include <cmath>
#include <queue>
#include <list>
#include <algorithm>
#include <utility>
#include <bits/stdc++.h>
#include <string>

#ifndef ONLINE_JUDGE

//#include "LeetCode.h"

#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define el '\n'
#define OmarMGaber return 0
#define tc ll t;cin >> t;while (t--)
#define ReadArray(v, n) loop(n - 1) { cin >> v[i]; }
#define vi vector<int>
#define vii vector<pair<int,int>>
#define vl vector<long>
#define vll vector<long long>
#define sf(n) scanf("%d", &n)
#define loopFrom1To(n) for(int i = 1; i <= (n); i++)
#define loop(n) for(int i = 0; i <= (n); i++)

/*
 * function that checks whether the string s2 is sub string from string s1
 * Time complexity: O(N^2)
 * Auxiliary space: O(1)
 */
bool isSubstring(const string &s1, const string &s2) {
    if (s2.empty()) {
        return true; // Empty substring
    }
    ll len1 = s1.length();
    ll len2 = s2.length();
    if (len1 < len2) {
        return false; // Substring is longer than the main string.
    }

    for (ll i = 0; i <= len1 - len2; ++i) {
        ll j;
        for (j = 0; j < len2; ++j) {
            if (s1[i + j] != s2[j]) {
                break;
            }
        }
        if (j == len2) {
            return true;
        }
    }
    return false;
}

/*
 * Time complexity: O(N)
 * Auxiliary space: O(1)
 */
bool isPalindrome(const string &s) {
    int len = s.length();
    for (int i = 0, j = len - 1; i != len / 2; i++, j--) {
        if (s[i] != s[j])
            return false;

    }
    return true;
}

/* Combine Strings method takes 2 strings s and t and return the combination between them
 * Example: s = aaaa, t = bbbbbbb, the function will return the string ababababbbb.
 * Time complexity: O(N)
 * Auxiliary space: O(N)
 */
string combineStrings(const string &s, const string &t, size_t index = 0) {
    if (index >= s.length() && index >= t.length()) {
        return "";
    }

    string result;
    if (index < s.length()) {
        result += s[index];
    }
    if (index < t.length()) {
        result += t[index];
    }

    return result + combineStrings(s, t, index + 1);
}

/* Function that returns the sum of a range (query) from a "1 BASED" prefix sum array.
* Time complexity: O(1)
* Auxiliary space: O(1)
*/
ll PrefixSumFromLtoR(ll (&arr)[], ll l, ll r) {
    if (l != 1)
        return (arr[r - 1] - arr[l - 2]);
    else
        return arr[r - 1];
}

/*
 * Function that removes all zeros from real number and return the number without zeros
 * Time complexity: O(N)
 * Auxiliary space: O(1)
 */
ll removeZero(ll n) {
    int i = 0;
    string str = to_string(n);
    string res = "";
    while (i != str.length()) {
        if (str[i] != '0') {
            res += str[i];
        }
        i++;
    }
    return stoll(res);
}

/* converts the number to binary and removes leading zeroes
 * Time Complexity: O(1)
 * Auxiliary Space: O(1)
 * Reference: GeeksForGeeks
*/
string binaryRep(unsigned n) {
    return bitset<32>(n).to_string().substr(32 - log2(n));
}

/*
 * Time complexity: O(sqrt(n))
 * Auxiliary space: O(1)
 */
bool isPrime(ll n) {
    if (n <= 1)
        return false;
    if (n == 2 || n == 3 || n == 5 || n == 7)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 11; i * i <= n; i += 2)
        if (n % i == 0)
            return false;

    return true;
}

/*
 * Function that returns the number of divisors for a certain integer n
 * Time complexity: O(Sqrt(N))
 * Auxiliary space: O(1)
 */
int numOfDivisors(int n) {
    int div = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0)
            div++;
    }
    return div;
}

/*
 * Selection Sort Algorithm (Mainly used for some special problems)
 * Time complexity: O(N^2)
 * Auxiliary space: O(1)
 */
void selectionSort(vector<int> &arr) {
    int temp;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/*
 * Function that returns the sum of all characters ascii in a certain string s
 * Time complexity: O(N)
 * Auxiliary space: O(1)
 */
ll sumASCII(const string &s) {
    ll sum = 0;
    for (char c: s)
        sum += c;
    return sum;
}

/*
 * Function that displays all array/vector elements (Mainly used for old school debugging).
 * Time complexity: O(N)
 * Auxiliary space: O(1)
 */
void display(vector<short> arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << el;
}

/*
 * Kadane’s algorithm to find the max contiguous array sum
 * Time Complexity: O(N)
 * Auxiliary Space: O(1)
 */
ll maxSubArraySum(ll a[], ll size) {
    ll max = INT_MIN, currentMax = 0;

    for (int i = 0; i < size; i++) {
        currentMax = currentMax + a[i];
        if (max < currentMax)
            max = currentMax;

        if (currentMax < 0)
            currentMax = 0;
    }
    return max;
}

/*
 * Function that checks whether the array/vector contains only zeros in each cell.
 * Time complexity: O(N)
 * Auxiliary space: O(1)
 */
bool isArrayOfZeros(vector<ll> &arr, int n) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] != 0) {
            return false;
        }
    }
    return true;
}

/*
 * Binary Search Algorithm (Mainly used for custom binary search problems).
 * Time complexity: O(log(N))
 * Auxiliary space: O(1)
 */
bool binarySearch(vi &vec, int size, int target) {
    int mid, low, high;
    low = 0;
    high = size - 1;

    while (low <= high) {
        mid = low + ((high - low) / 2);
        if (vec[mid] == target) {
            return true;
        }

        if (target < vec[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return false;
}

ll sumDigits(ll n) {
    ll sum = 0;
    while (n != 0) {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}

struct pqComp {
    constexpr bool operator()(pair<string, ll> const &a, pair<string, ll> const &b) const noexcept {
        return a.second > b.second;
    }
};

double distanceBetween2Points(double &x1, double &y1, double &x2, double &y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

vector<int> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;

    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

bool isValidBrackets(string &str) {
    stack<char> s;
    loop(str.length() - 1) {
        if (str[i] == '(')
            s.push(str[i]);
        else {
            if (s.empty())
                return false;
            s.pop();
        }
    }
    return s.empty();
}

bool isValidParentheses(string &s) {
    stack<char> parentheses;
    map<char, char> closeToOpenMap;
    closeToOpenMap[')'] = '(';
    closeToOpenMap[']'] = '[';
    closeToOpenMap['}'] = '{';

    for (char p: s) {
        if (p == '(' || p == '[' || p == '{')
            parentheses.push(p);
        else if (p == ')' || p == ']' || p == '}') {
            if (parentheses.empty())
                return false;

            if (parentheses.top() == closeToOpenMap[p])
                parentheses.pop();
            else
                return false;
        }
    }
    return parentheses.empty();
}

void generateLuckyNums(int num, int limit, vector<int> &luckyNums) {
    if (num <= limit) {
        luckyNums.push_back(num);
        generateLuckyNums(num * 10 + 4, limit, luckyNums);
        generateLuckyNums(num * 10 + 7, limit, luckyNums);
    }
}

ll sumOdd(ll n) {
    ll terms = (n + 1) / 2;
    ll sum = terms * terms;
    return sum;
}

struct Trie {
    Trie *child[MAX_CHAR]{};
    bool isWord;

    Trie() {
        memset(child, 0, sizeof(child));
        isWord = false;
    }

    void insert(char *str) {
        if (*str == '\0') {
            isWord = true;
            return;
        }
        int current = *str - 'a';
        if (!child[current])
            child[current] = new Trie();
        child[current]->insert(str + 1);
    }
};

#define MAX_CHAR 26

struct TrieNode {
    TrieNode *pTrieNode[MAX_CHAR]{};
    bool isWord;

    TrieNode() {
        isWord = false;
        fill(pTrieNode, pTrieNode + 26, (TrieNode *) NULL);
    }

    virtual ~TrieNode() = default;
};

class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }

    virtual ~Trie() = default;

    TrieNode *getTrieNode() {
        return this->root;
    }

    void insert(const string &word) {
        TrieNode *current = root;
        for (char c: word) {
            int i = c - 'a';
            if (current->pTrieNode[i] == nullptr)
                current->pTrieNode[i] = new TrieNode();
            current = current->pTrieNode[i];
        }
        current->isWord = true;
    }

    bool search(const string &word) {
        TrieNode *current = root;
        int ch = 0;
        for (char c: word) {
            ch = c - 'a';
            if (current->pTrieNode[ch] == nullptr)
                return false;
            current = current->pTrieNode[ch];
        }
        return current->isWord;
    }

    bool startsWith(const string &prefix) {
        TrieNode *current = root;
        int ch = 0;
        for (char c: prefix) {
            ch = c - 'a';
            if (current->pTrieNode[ch] == nullptr)
                return false;
            current = current->pTrieNode[ch];
        }
        return true;
    }
};

template<typename T>
class Vector {
private:
    T *arr;
    int size{};
    int current_size{};

public:
    Vector() {
        this->size = 10;
        this->current_size = 0;
        this->arr = new T[this->size];
    }

    explicit Vector(int _size) {
        this->size = _size;
        this->current_size = 0;
        this->arr = new T[this->size];
    }

    Vector(int _size, T filler) {
        this->size = _size;
        this->current_size = _size;
        this->arr = new T[this->size];
        fill(this->arr, this->arr + this->size, filler);
    }

    void push_back(T elem) {
        if (this->current_size == this->size) {
            int new_size = this->size * 2;
            T *newArr = new T[new_size];

            for (int i = 0; i < this->size; ++i)
                newArr[i] = this->arr[i];

            delete[] this->arr;
            this->arr = newArr;
            this->size = new_size;
        }
        this->arr[this->current_size] = elem;
        this->current_size++;
    }

    void print() {
        for (int i = 0; i < this->current_size; ++i)
            cout << this->arr[i] << ' ';
        cout << '\n';
    }

    T &operator[](int index) {
        if (index < 0 || index >= this->current_size) {
            throw std::out_of_range("Index out of range");
        }
        return this->arr[index];
    }

    T *begin() {
        return this->arr;
    }

    T *end() {
        return this->arr + this->current_size;
    }

    ~Vector() {
        delete[] this->arr;
    }
};


bool isPerfectSquare(int n) {
    double root = sqrt(n);
    return (root - (double) ((int) root) == 0);
}