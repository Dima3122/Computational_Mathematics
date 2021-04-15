#include <iostream>
#include <cmath>

using namespace std;

double func(double x)
{
    return x*x+x;
}

double Integral(double a, double b, int n)
{
    double h = (b - a) / n;
    double* x = new double[n];
    double result = 0;
    x[0] = a, x[n - 1] = b;
    for (int i = 1; i < n - 1; i++)//инициализируем х
    {
        x[i] = x[i - 1] + h;
    }
    for (int i = 0; i < n; i++)//Считаем значение функции во всех точках 
    {   
        result += func(x[i]);
    }
    result *= h;
    delete(x);
    return result;
}

double Runge(double a, double b, int n, double e)
{
    double I1 = Integral(a, b, n);
    double I2 = Integral(a, b, n * 2);
    int i = 2;
    while (abs(I2 - I1) > e) 
    {
        I1 = I2;
        i *= 2;
        I2 = Integral(a, b, n * i);
    }
    return I2;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int n = 1000, ans = 0;
    double a = 0;
    double b = 5;
    double e = 0.00001;
    cout << "a = " << a << ", b = " << b << ", n = " << n << ", e = " << e << endl;
    cout << "Простое интегрирование "<<Integral(a, b, n) << endl;
    cout << "Метод рунге " << Runge(a, b, n, e) << endl;
    return 0;
}