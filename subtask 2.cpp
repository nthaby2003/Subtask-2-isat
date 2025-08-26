#include <iostream>
#include <string>
// for rand and srand
#include <cstdlib>  
// for time
#include <ctime>    

using namespace std;

// Function to convert decimal to binary
string decimalToBinary(int number) {
    string binary = "";
    if (number == 0) return "0"; 

    while (number > 0) {
        // get remainder and add to binary string
        binary = to_string(number % 2) + binary; 
        number = number / 2;
    }
    return binary;
}

// Function to convert binary to decimal
int binaryToDecimal(string binary) {
    int decimal = 0;
    int base = 1; // starts at 2^0

    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
         // multiply base by 2 for next digit
        base *= 2;
    }
    return decimal;
}

// Function to convert decimal to hexadecimal
string decimalToHex(int number) {
    string hex = "";
    char hexDigits[] = "0123456789ABCDEF";

    if (number == 0) return "0"; 

    while (nu
        }
