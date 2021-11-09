#include <bits/stdc++.h>
using namespace std;

int FibRecurs(int n) {
    if (n <= 1) {
        return n;
    }
    else {
        return FibRecurs(n - 1) + FibRecurs(n - 2);
    }
}

int Fibveccall(vector<int> &v, int n)
{
    if (n <= 1) {
        return v[n];
    }
    else {
        for (int i = 2; i < n; ++i) {
            v[i] = v[i - 1] + v[i - 2];
        }
        return v[n - 1] + v[n - 2];
    }
}

char lastdigit(vector<int> v, int n)
{
    string s = to_string(Fibveccall(v, n));
    return s[s.size() - 1];
}

int main()
{
    vector<int> Fibvec {0, 1};
    //2-1
    cout << Fibveccall(Fibvec, 20) << "\n";
    //2-2
    cout << lastdigit(Fibvec, 20);
}