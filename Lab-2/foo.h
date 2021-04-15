#pragma once
#include <iostream>
#include<cmath>
using namespace std;

void print_Matr(double** arr, int n);
void init_Matr(double** arr, int n);
void print_arr(double* arr, int n);
void Get_res(double** arr, double* result, int n);
int check_matrix(double** arr, int n);
void set_matrix(double** arr, int n);
void simple_iteration_method(double** arr, double* result, int n);
bool check_convergence_conditions(double** arr, int n);
bool get_max_delta(double* result, double* result2, int n);
void Zeisel_Method(double** arr, double* result, int n);