// Copyright 2021 Romanyuk Sergey
#include "include/permutation.h"
#include <algorithm>
#include<iostream>

int* Permutation::get_arr(int n) {
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;
    return arr;
}

void Permutation::swap(int *a, int i, int j) {
    int s = a[i];
    a[i] = a[j];
    a[j] = s;
}

bool Permutation::NextSet(int *a, int n) {
    int j = n - 2;
    while (j != -1 && a[j] >= a[j + 1]) j--;
    if (j == -1)
        return false;
    int k = n - 1;
    while (a[j] >= a[k]) k--;
    swap(a, j, k);
    int l = j + 1, r = n - 1;
    while (l < r)
        swap(a, l++, r--);
    return true;
}
