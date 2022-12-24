// Copyright (c) 2022 Tamer Zreg All rights reserved.
// .
// Created by: Tamer Zreg
// Date: Dec 23rd, 2022
// This program generates 10 random numbers then displays them and
// the product in two different files.

#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

float calculate_product(float numbers[], int size) {
    // Calculate the product of the numbers
    float product = 1;
    for (int i = 0; i < size; i++)
        product *= numbers[i];

    return product;
}

int main() {
    // Create a list of random numbers and opens a file of them.
    const int size = 10;
    float numbers[size];
    for (int i = 0; i < size; i++) {
        numbers[i] = (float)rand() / RAND_MAX;
    }
    ofstream output_file("numbers.txt");
    output_file << "The numbers are: ";
    for (int i = 0; i < size; i++) {
        output_file << numbers[i] << " ";
    }
    output_file.close();

    // Calculate the product of the numbers
    float product = calculate_product(numbers, size);

    // Open the output file and write the product
    ofstream output_file2("product.txt");
    output_file2 << "The product is: " << product;
    output_file2.close();

    return 0;
}
