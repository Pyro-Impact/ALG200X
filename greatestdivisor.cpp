#include <bits/stdc++.h>
using namespace std;

int NaiveGCD(int a, int b)
{
    int ret = 0;
    for (int i = 1; i < a + b; ++i) {
        if (a % i == 0 && b % i == 0) {
            ret = i;
        }
    }

    return ret;
}

int EuclidGCD(int a, int b)
{
    if (b == 0) {
        return a;
    }
    int aprime = a % b;

    return EuclidGCD(b, aprime);
}

int lcm(int a, int b)
{
    return a * b / EuclidGCD(a, b);
}

int main()
{
    //2-3 
    cout << EuclidGCD(3256855, 90568) << "\n";
    //2-4
    cout << lcm(358925389,2930580);
}