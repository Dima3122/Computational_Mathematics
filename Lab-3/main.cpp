#include "foo.h"
//нелинейные уравнения бисекция хорд ньютона
int main()//хорды
{
    setlocale(LC_ALL, "ru");
    cout << bisection_method(-20, 10) << endl;
    cout << Newton_method(-20) << endl;
    cout << chord_method(-20, 10) << endl;
    return 0;
}
