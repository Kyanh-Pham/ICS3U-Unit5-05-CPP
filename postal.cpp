// Copyright (c) 2022 Kyanh Pham
//
// Created by: Kyanh Pham
// Created on: Nov 2022
//  This program formats a address

#include <algorithm>
#include <cstring>
#include <iostream>
#include <locale>
#include <stdexcept>
#include <string>

std::string address(std::string fullName,
                    std::string streetNumber,
                    std::string streetName,
                    std::string city,
                    std::string province,
                    std::string postalCode,
                    std::string apartmentNumber = "") {
    // this function returns the address properly formatted
    std::string formatted;

    formatted = fullName + "\n";
    formatted = formatted + streetNumber;
    if (apartmentNumber != "") {
        formatted = formatted + "-" + apartmentNumber;
    }
    formatted = formatted + " " + streetName + "\n";
    formatted = formatted + city + " ";
    formatted = formatted + province + "  ";
    formatted = formatted + postalCode;

    std::for_each(formatted.begin(),
                  formatted.end(), [](char& c) { c = ::toupper(c); });

    return formatted;
}

int main() {
    // gets a users name and prints out their formal name
    std::string fullName;
    std::string question;
    std::string streetNumber;
    std::string streetName;
    std::string city;
    std::string province;
    std::string postalCode;
    std::string properAddress;
    std::string apartmentNumber = "";

    // input
    std::cout << "Enter your full name: ";
    std::getline(std::cin, fullName);
    std::cout << "Do you live in an apartment? (y/n): ";
    std::getline(std::cin, question);
    if (question == "y") {
        std::cout << "Enter your apartment number: ";
        std::getline(std::cin, apartmentNumber);
    }
    std::cout << "Enter your street number: ";
    std::getline(std::cin, streetNumber);
    std::cout << "Enter your street name and type (Main St, Express Pkwy...): ";
    std::getline(std::cin, streetName);
    std::cout << "Enter your city: ";
    std::getline(std::cin, city);
    std::cout << "Enter your province (as an abbreviation, ex: ON, BC...): ";
    std::getline(std::cin, province);
    std::cout << "Enter your postal code (A1B 2C3): ";
    std::getline(std::cin, postalCode);
    std::cout << "" << std::endl;

    try {
        if (apartmentNumber != "") {
            apartmentNumber = stoi(apartmentNumber);
        }
        streetNumber = stoi(streetNumber);
        properAddress = address(fullName, streetNumber, streetName, city,
                                province, postalCode, apartmentNumber);
        std::cout << properAddress << std::endl;
    } catch (std::invalid_argument) {
        std::cout << "Invalid Input." << std::endl;
    }

    std::cout << "\nDone." << std::endl;
}
