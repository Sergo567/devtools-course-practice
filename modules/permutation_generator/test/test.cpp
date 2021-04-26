// Copyright 2021 Romanyuk Sergey
#include <gtest/gtest.h>
#include<tuple>
#include "include/permutation.h"

TEST(Permutation_Generate, Test1_value3) {
    Permutation p;
    int n = 3;
    int *a = new int[n];
    a = p.get_arr(n);

    for (int i = 0; i < 4; i++) {
        p.NextSet(a, n);
    }

    int res[] = { 3, 1, 2 };

    for (int i = 0; i < 3; i++) {
         ASSERT_EQ(res[i], a[i]);
    }
}

TEST(Permutation_Generate, Test2_value4) {
    Permutation p;
    int n = 4;
    int *a = new int[n];
    a = p.get_arr(n);


    for (int i = 0; i < 10; i++) {
        p.NextSet(a, n);
    }

    int res[] = { 2, 4, 1, 3 };

    for (int i = 0; i < 4; i++) {
        ASSERT_EQ(res[i], a[i]);
    }
}

TEST(Permutation_Generate, Test3_value5) {
    Permutation p;
    int n = 5;
    int *a = new int[n];
    a = p.get_arr(n);


    for (int i = 0; i < 20; i++) {
        p.NextSet(a, n);
    }

    int res[] = { 1, 5, 3, 2, 4};

    for (int i = 0; i < 5; i++) {
         ASSERT_EQ(res[i], a[i]);
    }
}

TEST(Permutation_Generate, Test4_value7) {
    Permutation p;
    int n = 7;
    int *a = new int[n];
    a = p.get_arr(n);


    for (int i = 0; i < 50; i++) {
        p.NextSet(a, n);
    }

    int res[] = { 1, 2, 5, 3, 6, 4, 7};

    for (int i = 0; i < 7; i++) {
         ASSERT_EQ(res[i], a[i]);
    }
}

TEST(Permutation_Generate, Test5_value10) {
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

TEST(Permutation_Generate, Test6_while) {
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

TEST(Permutation_Generate, Test7_Parameterized10) {
    Permutation p;
    int n = 5;
    int* test_permutation = new int[n];
    test_permutation = p.get_arr(n);
    int* true_permutation = new int[n];
    true_permutation = p.get_arr(n);

    do {
        for (int i = 0; i < n; i++) {
            ASSERT_EQ(true_permutation[i], test_permutation[i]);
        }
        p.NextSet(test_permutation, n);
    } while (std::next_permutation(true_permutation, true_permutation + n));
}

TEST(Permutation_Generate, Test8_Parameterized15) {
    Permutation p;
    int n = 10;
    int* test_permutation = new int[n];
    test_permutation = p.get_arr(n);
    int* true_permutation = new int[n];
    true_permutation = p.get_arr(n);

    do {
        for (int i = 0; i < n; i++) {
            ASSERT_EQ(true_permutation[i], test_permutation[i]);
        }
        p.NextSet(test_permutation, n);
    } while (std::next_permutation(true_permutation, true_permutation + n));
}

typedef testing::TestWithParam<std::tuple<double, double>>
Permutation_Generate_Param;
TEST_P(Permutation_Generate_Param, Test9_Param) {
    Permutation p;

    int n1 = std::get<0>(GetParam());
    int n2 = std::get<1>(GetParam());

    int* a = new int[n1];
    a = p.get_arr(n1);

    int* b = new int[n2];
    b = p.get_arr(n2);


    ASSERT_EQ(true, p.NextSet(a, n1));
    ASSERT_EQ(true, p.NextSet(b, n2));
}

INSTANTIATE_TEST_CASE_P(/**/, Permutation_Generate_Param,
    testing::Combine(
    testing::Values(2.0, 5.0),
    testing::Values(6.0, 8.0)
));
