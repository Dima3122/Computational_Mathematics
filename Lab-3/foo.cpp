#include "foo.h"

double func(double x)
{
	return sin(M_PI * x / 180) - 1 / x;
}

bool Check_func(double a, double b)
{
	if (func(a)* func(b) < 0)
	{
		return true;
	}
	return false;
}

double bisection_method(double a, double b) // функция, которая ищет ноль на промежутке от a до b
{
	if (Check_func(a,b) == false)
	{
		cout << "Условие на сходимость не выполнено" << endl;
		return NULL;
	}
	const double e = 0.0001;//точность
	while (b - a > e) // пока не будет достигнута необходимая точность
	{
		if (func(a) * func((b + a) / 2) > 0)//если значение функции больше нуля, то а сдвигаем.
		{
			a = (b + a) / 2;
		}
		else if (func(a) * func((b + a) / 2) < 0)//если значение функции меньше нуля, то б сдвигаем.
		{
			b = (b + a) / 2;
		}
		else//иначе выходим
		{
			break;
		}
	}
	return (b + a) / 2;//возвращаем среднее арифмитическое
}

double Newton_method (double x)
{
	double f, df; int iter = 0;
	const double e = 0.00001;
	do 
	{
		f = func(x);//считаем чему равно при х
		df = M_PI / 180 * cos(M_PI * x / 180) + 1 / (x * x);//считаем чему равно при производной при том же х
		x = x - f / df;//высчитываем х
		iter++;//+1 итерация
	} while (abs(f) > e && iter < 2000);
	return x;
}

double chord_method(double a, double b)
{
	if (Check_func(a, b) == false)
	{
		cout << "Условие на сходимость не выполнено" << endl;
		return NULL;
	}
	double rez = b, f1, f2;
	const double e = 0.00001;
	do 
	{
		f1 = func(rez);
		f2 = func(a);
		rez = rez - f1 / (f1 - f2) * (rez - a);
	} while (abs(f1) > e);
	return rez;
}