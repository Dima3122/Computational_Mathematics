#include "foo.h"
using namespace std;
//метод гауса + метод жордана гауса
int main()
{
    setlocale(LC_ALL, "ru");
    int n, z, check;
    cout << "Введите размерность матрицы:";
    cin >> n;
    double* result = new double[n];
    double** Matrix = new  double*[n];
    double** Matrix2 = Matrix;
    for (size_t i = 0; i < n+1; i++)
    {
        Matrix[i] = new double[n + 1];
    }
    cout << "\n1)Сгенирировать матрицу \n2)Ввести матрицу вручную" << endl;
    cin >> z;
    if (z == 1)
    {
        init_Matr(Matrix, n);
    }
    else if(z == 2)
    {
        set_matrix(Matrix, n);
        check = check_matrix(Matrix, n);
        if (check == -1)
        {
            cout << "Вы ввели нулевую матрицу. Матрица инициализируется автоматически" << endl;
            cin >> z;
            init_Matr(Matrix, n);
        }
    }
    else
    {
        cout << "Введена неверная команда программа завершается" << endl;
        return -1;
    }
    cout << "Матрица:" << endl;
    print_Matr(Matrix, n);
    Gauss_method(Matrix, result, n);
    cout << "Решение методом ГАУСА" << endl;
    print_arr(result, n);
    Jordan_Gauss_method(Matrix2, result, n);
    cout << endl <<"Решение методом Жордана ГАУСА" << endl;
    print_arr(result, n);
    return 0;
}
