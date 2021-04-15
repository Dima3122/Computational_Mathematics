#include "foo.h"

void print_Matr(double** arr, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n + 1; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void init_Matr(double** arr, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n + 1; j++)
		{
			arr[i][j] = rand() % 20;
		}
	}
}

void print_arr(double* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

void Get_res(double** arr, double* result, int n)
{
	for (int i = 0; i < n; i++)
	{
		result[i] = arr[i][n];
	}
}

int check_matrix(double** arr, int n)
{
    int check = n * n, count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                count++;
            }
        }
    }
    if (check == count)
    {
        return -1;
    }
    return 0;
}
void set_matrix(double** arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << "arr[" << i << "][" << j << "] = ";
            cin >> arr[i][j];
        }
    }
}

bool check_convergence_conditions(double** arr, int n)
{
	double h = 0, sum = 0;
	for (int i = 0; i < n; i++)
	{
		h = abs(arr[i][i]);
		for (int j = i + 1; j < n; j++)
		{
			sum += abs(arr[i][j]);//считаем числа по модулю, которые справа все что справа
		}
		for (int v = i - 1; v > 0; v--)
		{
			sum += abs(arr[i][v]);
		}
		if (h < sum)
		{
			return false;
		}
		h = 0;
		sum = 0;
	}
	return true;
}

bool get_next_step(double* Xn, double* res, int n, double e)
{
	for (int i = 0; i < n - 1; i++) 
	{
		if (abs(Xn[i] - res[i]) > e) 
		{
			return true;
			break;
		}
	}
	return false;
}

void simple_iteration_method(double** arr, double* result, int n)
{
	if (!check_convergence_conditions(arr, n))
	{
		cout << "Условие на сходимость не выполнено." << endl;
		return;
	}
	Get_res(arr, result, n);
	const double e = 0.00001;
	double* Xn = new double[n];//результат в итерации последний
	double* res = new double[n];//результат в итерации предпоследний
	do 
	{
		for (int i = 0; i < n; i++) 
		{
			res[i] = Xn[i];
			Xn[i] = result[i] / arr[i][i];
			for (int j = 0; j < n; j++) 
			{
				if (i != j)
				{
					Xn[i] -= arr[i][j] / arr[i][i] * res[j];//считаем по формуле
				}//каждая новая итерация равна коэф\диагональный элем* на результат предыдущей
			}	 //итерации
		}
	} while (get_next_step(Xn, res, n, e));//смотрим точность
	for (int i = 0; i < n; i++)
	{
		result[i] = Xn[i];
	}
}

void Zeisel_Method(double** arr, double* result, int n)
{
	if (!check_convergence_conditions(arr, n))
	{
		cout << "Условие на сходимость не выполнено." << endl;
		return;
	}
	Get_res(arr, result, n);
	const double e = 0.00001;
	double* Xn = new double[n];//результат в итерации предпоследний
	double* res = new double[n];//с помощью рес мы считаем точность
	do
	{
		for (int i = 0; i < n; ++i)
		{
			res[i] = Xn[i];//сохраняем предыдущую итерацию
			Xn[i] = result[i] / arr[i][i];
			for (int j = 0; j < n; ++j)
			{
				if (i != j)
				{
					Xn[i] -= arr[i][j] / arr[i][i] * Xn[j];
				}
			}
		}
	} while (get_next_step(Xn, res, n, e));
	for (int i = 0; i < n; i++)
	{
		result[i] = Xn[i];
	}
}