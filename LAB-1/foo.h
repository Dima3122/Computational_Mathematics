#pragma once
#include <iostream>
using namespace std;

void print_Matr(double** arr, int n);
void init_Matr(double** arr, int n);
void print_arr(double* arr, int n);
void Gauss_method(double** arr, double* result, int n);
void Jordan_Gauss_method(double** arr, double* result, int n);
void Get_res(double** arr, double* result, int n);
void set_matrix(double** arr, int n);
int check_matrix(double** arr, int n);