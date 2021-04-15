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

double bisection_method(double a, double b) // �������, ������� ���� ���� �� ���������� �� a �� b
{
	if (Check_func(a,b) == false)
	{
		cout << "������� �� ���������� �� ���������" << endl;
		return NULL;
	}
	const double e = 0.0001;//��������
	while (b - a > e) // ���� �� ����� ���������� ����������� ��������
	{
		if (func(a) * func((b + a) / 2) > 0)//���� �������� ������� ������ ����, �� � ��������.
		{
			a = (b + a) / 2;
		}
		else if (func(a) * func((b + a) / 2) < 0)//���� �������� ������� ������ ����, �� � ��������.
		{
			b = (b + a) / 2;
		}
		else//����� �������
		{
			break;
		}
	}
	return (b + a) / 2;//���������� ������� ��������������
}

double Newton_method (double x)
{
	double f, df; int iter = 0;
	const double e = 0.00001;
	do 
	{
		f = func(x);//������� ���� ����� ��� �
		df = M_PI / 180 * cos(M_PI * x / 180) + 1 / (x * x);//������� ���� ����� ��� ����������� ��� ��� �� �
		x = x - f / df;//����������� �
		iter++;//+1 ��������
	} while (abs(f) > e && iter < 2000);
	return x;
}

double chord_method(double a, double b)
{
	if (Check_func(a, b) == false)
	{
		cout << "������� �� ���������� �� ���������" << endl;
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