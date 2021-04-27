// Copyright 2021 Romanyuk Sergey
#include <gtest/gtest.h>
#include <tuple>
#include "include/permutation.h"

TEST(Permutation_Generate, Test1_value4) {
    Permutation p;
    int n = 4;
    int* a = new int[n];
    a = p.get_arr(n);


    for (int i = 0; i < 10; i++) {
        p.NextSet(a, n);
    }

    int res[] = { 2, 4, 1, 3 };

    for (int i = 0; i < 4; i++) {
        ASSERT_EQ(res[i], a[i]);
    }
}


TEST(Permutation_Generate, Test2_value10) {
    Permutation p;
    int n = 10;
    int *a = new int[n];
    a = p.get_arr(n);


for (int i = 0; i < 879; i++) {
    p.NextSet(a, n);
}
int res[] = { 1, 2, 3, 5, 6, 7, 9, 8, 10, 4 };
for (int i = 0; i < 10; i++) {
     ASSERT_EQ(res[i], a[i]);
}
}

TEST(Permutation_Generate, Test3_while) {
    Permutation p;
    int n = 3;
    int *a = new int[n];
    a = p.get_arr(n);

    for (int i = 0; i < 20; i++) {
        p.NextSet(a, n);
    }

    int res[] = { 3, 2, 1};
    for (int i = 0; i < n; i++) {
        ASSERT_EQ(res[i], a[i]);
    }
}

typedef testing::TestWithParam<std::tuple<double, double, double>>
Permutation_Generate_Param;
TEST_P(Permutation_Generate_Param, Test4_PARAM) {
    Permutation p;
    int n = std::get<0>(GetParam());
    int iterations = std::get<1>(GetParam());
    if (iterations > p.fact(n)) {
        iterations = p.fact(n);
    }
    std::cout << "n = "<< n << std::endl;
    std::cout << "iterations = " << iterations << std::endl;
    int* a = new int[n];
    int* checker = new int[n];
    a = p.get_arr(n);
    checker = p.get_arr(n);
    for (int i = 0; i < iterations; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "a[j] = " << a[j] << std::endl;
            std::cout << "checker[j] = " << checker[j] << std::endl;
            ASSERT_EQ(a[j], checker[j]);
        }
        p.NextSet(a, n);
        std::next_permutation(checker, checker + n);
    }
}

INSTANTIATE_TEST_CASE_P(/**/, Permutation_Generate_Param, testing::Combine(
    testing::Values(2.0, 7.0),
    testing::Values(2.0, 12.0)
));
