#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
    return exp(-sqrt(x)) / 2 - 0.2 * sqrt(x * x * x) + 2;
}

double findRoot(double a, double b, double epsilon)
{
    int i = 0;
    while (fabs(b - a) > epsilon)
    {
        a = b - (b - a) * f(b) / (f(b) - f(a));
        b = a - (a - b) * f(a) / (f(a) - f(b));
        i++;
    }
    return b;
}

int main()
{
    cout.setf(ios::fixed);
    double a, b;
    cout << "Enter the limits:\n(left limit) a = ";
    cin >> a;
    cout << "(right limit) b = ";
    cin >> b;
    double t = findRoot(a, b, 0.001);
    cout << "x = " << t << "\nf(x) = " << f(t) << endl;
    return 0;
}