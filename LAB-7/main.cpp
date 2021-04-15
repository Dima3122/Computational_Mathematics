#include <iostream>
#include <cmath>

//решение ДУ(Метод Эйлера, методы Рунге-Кнута) с двойным перерасчетом
using namespace std;

double func(double x, double y)
{
    return x * x * x - 5 * y;
}

double eiler(double a, double b, double y0, int n)
{
    double* x = new double[n];
    x[0] = a;
    for (int i = 1; i < n; i++)//инициализация иксов
    {
        x[i] = x[i - 1] + (b - a) / n;
    }
    double h = (b - a) / n;//ищем высоту
    double* y = new double[n];
    y[0] = y0;
    for (int i = 1; i < n; i++) 
    {
        y[i] = y[i - 1] + h * func(x[i - 1], y[i - 1]);//считаем y[i]
    }
    h = y[n - 1] + h * func(x[n - 1], y[n - 1]);//подставляем в формулу и находим ответ
    return h;
}

double runge(double a, double b, double y0, int n)
{
    double* x = new double[n];
    double h = (b - a) / n;
    double *y = new double[n];
    double k;
    y[0] = y0;
    x[0] = a;
    for (int i = 1; i < n; i++)//инициализация иксов 
    {
        x[i] = x[i - 1] + h;
    }
    for (int i = 1; i < n; i++) 
    {
        k = y[i - 1] + h * func(x[i - 1], y[i - 1]) / 2;//высчитываем коэфициент для подстановки
        y[i] = y[i - 1] + h * (func(x[i - 1], y[i - 1]) + func(x[i - 1] + h, k)) / 2;//высчитываем следующее y[i]
    }                                                                                //по формуле
    k = y[n - 1] + h * (func(x[n - 1], y[n - 1]) + func(x[n - 1] + h, k)) / 2;//считаем ответ по формуле
    return k;
}
double double_counting(double a, double b, double y0, int n, double e)
{
    double DF1 = runge(a, b, y0, n);
    double DF2 = runge(a, b, y0, n * 2);
    int i = 2;
    while (abs(DF2 - DF1) > e) {
        DF1 = DF2, i *= 2;
        DF2 = runge(a, b, y0, n * i);
    }
    return DF2;
}

int main()
{
    int n = 10, ans = 0;
    double a = 1;
    double b = 4;
    double e = 0.00001;
    cout << "a = " << a << ", b = " << b << ", n = " << n << ", e = " << e << endl;
    cout << "Runge rezult: " << double_counting(a, b, ans, n, e) << endl;
    cout << "Eirler rezult: "<< eiler(a, b, ans, n) << endl;
    return 0;
}