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

void Gauss_method(double** arr,double* result, int n)
{
    int k;
    double tmp;
    for (int i = 0; i < n; i++)
    {
        tmp = arr[i][i];
        for (int j = n; j >= i; j--)
        {
            arr[i][j] /= tmp;
        }
        for (int j = i + 1; j < n; j++)
        {
            tmp = arr[j][i];
            for (k = n; k >= i; k--)
            {
                arr[j][k] -= tmp * arr[i][k];
            }
        }
    }
    /*обратный ход*/
    result[n - 1] = arr[n - 1][n];
    for (int i = n - 2; i >= 0; i--)
    {
        result[i] = arr[i][n];
        for (int j = i + 1; j < n; j++) 
        {
            result[i] -= arr[i][j] * result[j];
        }
    }
}

void Get_res(double** arr, double* result, int n)
{
    for (int i = 0; i < n; i++)
    {
        result[i] = arr[i][n];
    }
}

void Jordan_Gauss_method(double** arr, double* result, int n)
{
    Get_res(arr, result, n);
    int imax, i, j, k;
    double amax, c;
    // Пpямой ход
    for (k = 0; k < n; k++)
    {
        // Поиcк макcимального элемента по абcолютной величине
        imax = k;
        amax = fabs(arr[k][k]);//берем по модулю
        for (i = k + 1; i < n; i++)//затем сравниваем по модулю все числа
        {
            if (fabs(arr[i][k]) > amax)//Находим наибольшее
            {
                amax = fabs(arr[i][k]);
                imax = i;
            }
        }
        // Пеpеcтановка cтpок k и imax
        if (k != imax)
        {
            for (j = k; j < n; j++) // пеpеcтавляем чаcть cтpоки
            {
                c = arr[k][j];
                arr[k][j] = arr[imax][j];
                arr[imax][j] = c;
            }
            c = result[k];
            result[k] = result[imax];
            result[imax] = c;
        }
        c = 1 / arr[k][k];
        for (i = k; i < n; i++)//ну а дальше как в обычном гаусе
        {                      //только матрица приводится полностью к единичному виду,
            arr[k][i] *= c;    //потому что строка с наибольшим значением первая
        }
        result[k] *= c;
        for (i = k + 1; i < n; i++)
        {
            for (j = k + 1; j < n; j++)
            {
                arr[i][j] -= arr[i][k] * arr[k][j];
            }
            result[i] -= arr[i][k] * result[k];
        }
    }
    // Обpатный ход
    for (i = n - 2; i >= 0; i--)
    {
        for (j = i + 1; j < n; j++)
        {
            result[i] -= arr[i][j] * result[j];
        }
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
void set_matrix(double ** arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << "arr["<< i << "][" << j << "] = ";
            cin >> arr[i][j];
        }
    }
}