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

int lastdigit(vector<int> v, int n)
{
    return Fibveccall(v, n) % 10;
}

int lastdigitsum(vector<int> v, int n)
{
    return (Fibveccall(v, n + 2) - 1) % 10;
}

long long get_pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }

    return 0;
}

int fibagain(vector<int> v, int n, int m)
{
    long long r = n % get_pisano_period(m);

    return Fibveccall(v, r) % m;
}

int lastdigitpartial(vector<int> v, int m, int n)
{
    int total = 0;
    for (int i = m; i <= n; ++i) {
        total += Fibveccall(v, i);
    }

    return total % 10;
}

int main()
{
    vector<int> Fibvec {0, 1};
    //2-1
    cout << Fibveccall(Fibvec, 20) << "\n";
    //2-2
    cout << lastdigit(Fibvec, 20) << "\n";
    //2-5
    cout << fibagain(Fibvec, 2015, 3) << "\n";
    //2-6
    cout << lastdigitsum(Fibvec, 5) << "\n";
    //2-7
    cout << lastdigitpartial(Fibvec, 3, 7) << "\n";

}