#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v {6, 7, -1, -2, 0, 5, 10};
    sort(v.begin(), v.end());
    if (v[v.size() - 2] * v[v.size() - 1] > v[0] * v[1]) {
        cout << v[v.size() - 2] << ", " << v[v.size() - 1];
    }
    else {
        cout << v[0] << ", " << v[1];
    }
}