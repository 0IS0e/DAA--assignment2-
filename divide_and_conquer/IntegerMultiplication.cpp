
#include <iostream>
#include <algorithm>
using namespace std;

long long power10(int n)
{
    long long p = 1;

    while (n--)
    {
        p *= 10;
    }

    return p;
}

int digits(long long n)
{
    if (n == 0)
        return 1;

    int count = 0;

    while (n > 0)
    {
        count++;
        n /= 10;
    }

    return count;
}

long long multiply(long long x, long long y)
{
    if (x < 10 || y < 10)
        return x * y;

    int n = max(digits(x), digits(y));
    int m = n / 2;

    long long p = power10(m);

    long long a = x / p;
    long long b = x % p;

    long long c = y / p;
    long long d = y % p;

    long long ac = multiply(a, c);
    long long ad = multiply(a, d);
    long long bc = multiply(b, c);
    long long bd = multiply(b, d);

    return ac * power10(2 * m)
         + (ad + bc) * p + bd;
}

int main()
{
    long long x, y;

    cout << "Enter first integer: ";
    cin >> x;

    cout << "Enter second integer: ";
    cin >> y;

    if (x < 0 || y < 0)
    {
        cout << "Enter non-negative integers.";
        return 0;
    }

    cout << "Product: " << multiply(x, y);

    return 0;
}
