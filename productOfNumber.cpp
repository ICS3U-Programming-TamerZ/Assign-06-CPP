// Copyright (c) 2022 Tamer Zreg All rights reserved.
// .
// Created by: Tamer Zreg
// Date: Dec 23rd, 2022
// This program gets user input as a list of floats
// Then it displays the product of the list rounded to two decimals.
#include <cmath>
#include <iostream>
#include <list>
#include <stdexcept>

using namespace std;

// Calculates the product of all elements in a list of floats
float product_of_list(list<float> list_of_floats) {
    // Initialize product to 1
    float product = 1;

    // Return -1 if the length of the input list is 1
    if (list_of_floats.size() == 1) {
        return -1;
    }

    // Calculate product of all elements in list using a for loop
    else {
        for (list<float>::iterator it = list_of_floats.begin(); it != list_of_floats.end(); it++) {
            product = (*it) * product;
        }

        // Round product to 2 decimal places
        product = round(product * 100) / 100;

        // Return -1 if product is equal to 1
        if (product == 1) {
            return -1;
        }

        // Return rounded product otherwise
        else {
            return product;
        }
    }
}

int main() {
    // Initialize empty list to store user input
    list<float> list_of_nums;

    // Initialize variable to store user input
    float number;

    // Print program description
    cout << "This program multiplies the PRODUCT of all the numbers inside a list." << endl;

    // Get user input until they enter -1
    while (true) {
        cout << "Please enter a number ranging from -10000 to 10000(-1 to Stop): ";

        try {
            // Get user input and convert to float
            cin >> number;
            if (cin.fail()) {
                throw invalid_argument("Please enter a valid number.");
            }

            // Add input to list if it is not -1 and less than 10000
            if (number != -1 && number < 10000 && number > -10000) {
                list_of_nums.push_back(number);
            }

            // Print error message if user input is greater than or equal to 10000
            else if (number >= 10000 or number <= -10000) {
                cout << "Please enter a number ranging from -10000 to 10000." << endl;
            }

            // Calculate product of input list if user input is -1
            else if (number == -1) {
                float product = product_of_list(list_of_nums);

                // Print error message if list has less than 2 elements
                if (product == -1) {
                    cout << "Please enter at least two numbers." << endl;
                }

                // Print product of input list otherwise
                else {
                    cout << "Your product amongst {";
                    for (list<float>::iterator it = list_of_nums.begin(); it != list_of_nums.end(); it++) {
                        cout << *it;
                        if (next(it) != list_of_nums.end()) {
                            cout << ", ";
                        }
                    }
                    cout << "} is " << product << endl;
                }

                break;
            }
        } catch (invalid_argument& e) {
            cerr << e.what() << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    return 0;
}
