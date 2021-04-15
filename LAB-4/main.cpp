#include <iostream>
#include <vector>
using namespace std;
//интерполяция формула ньютона
double InterpolateNewtonPolynomial(double x, vector<double> xv, vector<double> yv)
{
	double sum = yv[0];//Значение функции
	for (int i = 1; i < xv.size(); ++i)//каждый раз друг на друга наслаивается 0,1,2...
	{
		double F = 0;//значение при каждой итерации
		for (int j = 0; j <= i; ++j) 
		{
			double den = 1;
			for (int k = 0; k <= i; ++k)
			{
				if (k != j)
				{
					den *= (xv[j] - xv[k]);
				}
			}
			F += yv[j] / den;
		}
		for (int k = 0; k < i; ++k)
		{
			F *= (x - xv[k]);//собираем все по формуле
		}
		sum += F;
	}
	return sum;
}

double InterpolateLagrangePolynomial(double x, vector<double> xv, vector<double> yv)
{
	double sum = 0; //Значение функции
	for (int i = 0; i < xv.size(); i++)
	{
		double mul = 1; //Произведение
		for (int j = 0; j < xv.size(); j++)
		{
			if (i != j)
			{
				mul *= (x - xv[j]) / (xv[i] - xv[j]);//считаем по формуле полинома лагранжа
			}
		}
		sum += yv[i] * mul;//общая сумма, так же по формуле
	}
	return sum;
}

int main() 
{
	setlocale(LC_ALL, "ru");
	int counter = 0;
	double a = -3; //Левая грань
	double b = 3; //Правая грань
	int fragments = 10; //Разбиение
	vector<double> xv{};
	vector<double> yv{};
	int size, count = 0;
	cout << "Сколько пар Х?: ";
	cin >> size;
	size = size * 2;
	double inp;
	while (count < size)//Заполнение
	{
		if (count % 2)
		{
			cout << "Введите точку y: ";
			cin >> inp;
			yv.push_back(inp);
		}
		else
		{
			cout << "Введите точку x: ";
			cin >> inp;
			xv.push_back(inp);
		}
		count++;
	}
	cout << "Метод лагранжа" << endl;
	for (int i = 0; i < fragments; i++) 
	{
		double x = a + (b - a) / (fragments - 1) * i;//расчитываем х
		printf("%6.3lf\t%6.3lf\n", x, InterpolateLagrangePolynomial(x, xv, yv));//расчитываем y
	}
	cout << endl;
	cout << "Метод Ньютона" << endl;
	for (int i = 0; i < fragments; i++)
	{
		double x = a + (b - a) / (fragments - 1) * i;//расчитываем х
		printf("%6.3lf\t%6.3lf\n", x, InterpolateNewtonPolynomial(x, xv, yv));//расчитываем y
	}
	return 0;
}