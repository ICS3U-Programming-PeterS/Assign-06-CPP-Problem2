// Copyright (c) 2022 Peter Sobowale All rights reserved.
//
// Created by: Peter Sobowale
// Created on: December 29, 2022
// This program gets 2 lists of numbers and combines them
#include <iostream>
#include <list>
#include <sstream>
#include <string>


// Function to get the alternating elements from the two lists
std::list<std::string> alternating_elements
(const std::list<std::string>& list1, const std::list<std::string>& list2) {
    // Create an empty result list
    std::list<std::string> result;

    // Zip together the two lists and iterate through them
    for (int i = 0; i < list1.size(); i++) {
        // Append the elements to the result list, alternating between them
        auto it = list1.begin();
        std::advance(it, i);
        result.push_back(*it);

        auto t = list2.begin();
        std::advance(t, i);
        result.push_back(*t);
    }

    return result;
}

int main() {
    // User interface
    std::cout << "This program asks the user to enter 2 "
              << "lists of different elements. It then displays "
              << "the new list with alternating elements.\n"
              << std::endl;

    // variables
    std::string list1_str, element, list2_str;
    std::list<std::string> list1, list2;

    // Prompt the user to enter the first list
    std::cout << "Enter a list of elements, separated by spaces: ";
    std::getline(std::cin, list1_str);

    // Split the string into a list of elements
    std::istringstream iss(list1_str);
    while (iss >> element) {
        list1.push_back(element);
    }

    // Prompt the user to enter the second list
    std::cout << "Enter a second list of elements, separated by spaces: ";
    std::getline(std::cin, list2_str);

    // Split the string into a list of elements
    iss.clear();
    iss.str(list2_str);
    while (iss >> element) {
        list2.push_back(element);
    }

    // Erroneous data
    if (list1.size() != list2.size()) {
        std::cout << "\nBoth lists must have the "
                  << "same number of elements." << std::endl;
    } else {
        // Call the alternating_elements function to get the final list
        std::list<std::string> result = alternating_elements(list1, list2);

        // Print the final list
        std::cout << "\nBoth lists combined: [";
        std::string z = result.back();
        result.pop_back();

        for (std::string x : result) {
            std::cout << "'" << x << "', ";
        }
        std::cout << "'" << z << "']" << std::endl;
    }
}
