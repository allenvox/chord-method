#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
    return 0.5 * exp(-sqrt(x)) - 0.2 * sqrt(x * x * x) + 2;
}

double findRoot(double (*f)(double), double a, double b,
                double eps = 0.001)
{
    double t;
    while (fabs(b - a) >= eps)
    {
        t = a + (f(b) * (b - a)) / (f(b) - f(a));

        if (f(a) * f(t) < 0)
        {
            b = t;
        }
        else if (f(t) * f(b) < 0)
        {
            a = t;
        }
        else
        {
            return t;
        }
    }
    return t;
}

int main()
{
    cout.setf(ios::fixed);
    double a, b;
    cout << "\nEnter the limits,\n\nLeft limit,a= ";
    cin >> a;
    cout << "\nRight limit,b= ";
    cin >> b;
    double t = findRoot(f);
    cout << "x=" << t << "f(x)=" << f(t) << endl;
    return 0;
}