#include <bits/stdc++.h>
using namespace std;

int Naive(vector<int> v1, int n)
{
    int product = 0;
    for (int i = 1; i < n; ++i) 
    {
        for (int j = i + 1; j < n; ++j) {
            product = max(product, v1[i] * v1[j]);
        }
    }

    return product;
}

int64_t Fast(vector<int> v1, int n)
{
    int index = 1;
    for (int i = 2; i < n; ++i) {
        if (v1[i] > v1[index]) {
            index = i;
        }
    }
    swap(v1[index], v1[n - 1]);
    int index2 = 1;
    for (int i = 2; i < n - 1; ++i) {
        if (v1[i] > v1[index2]) {
            index2 = i;
        }
    }

    return v1[index] * v1[index2];
}

void StressTest(int n1)
{
    while (true) {
        srand(time(NULL));
        int n = rand() % 1000 + 2;
        vector<int> v2;
        for (int i = 1; i < n; ++i) {
            v2.push_back(rand() % 1000);
        }
        int result1 = Naive(v2, n1);
        int result2 = Fast(v2, n1);
        if (result1 == result2) {
            cout << "OK\n";
        }
        else {
            cout << "Wrong answer: " << result1 << " " << result2;
            return;
        }
    }
}

int main()
{
    vector<int> v;
    int n, temp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    //if (v[v.size() - 2] * v[v.size() - 1] > v[0] * v[1]) {
    cout << v[v.size() - 2] * v[v.size() - 1] << "\n";
    /*}
    else {
        cout << v[0] * v[1];
    }*/
    cout << Naive(v, n) << "\n";
    cout << Fast(v, n) << "\n";
}