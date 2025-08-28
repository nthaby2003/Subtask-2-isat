#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Function 1: Decimal to Binary (manual)
string decimalToBinary(int num) {
    if (num == 0) return "0";
    string binary = "";
    while (num > 0) {
        binary = char((num % 2) + '0') + binary;
        num /= 2;
    }
    return binary;
}

// Function 2: Binary to Decimal (manual)
int binaryToDecimal(string binary) {
    int decimal = 0;
    for (char bit : binary) {
        if (bit != '0' && bit != '1') {
            cout << "Invalid binary digit: " << bit << endl;
            return -1; // Indicate error
        }
        decimal = decimal * 2 + (bit - '0');
    }
    return decimal;
}

// Function 3: Decimal to Hexadecimal (using stringstream)
string decimalToHex(int num) {
    stringstream ss;
    ss << hex << uppercase << num; // Uppercase for standard hex letters
    return ss.str();
}

// Function 4: Hexadecimal to Decimal
int hexToDecimal(string hexStr) {
    int num;
    stringstream ss;
    ss << std::hex << hexStr;
    ss >> num;
    return num;
}

// Demo function: generate random number 0-99 and convert to binary
void demo() {
    srand(static_cast<unsigned>(time(0)));
    int num = rand() % 100;
    cout << "Random number: " << num << endl;
    cout << "Binary: " << decimalToBinary(num) << endl;
}

int main() {
    int choice;
    do {
        cout << "\n=== Conversion Menu ===" << endl;
        cout << "1. Convert Decimal to Binary" << endl;
        cout << "2. Convert Binary to Decimal" << endl;
        cout << "3. Convert Decimal to Hexadecimal" << endl;
        cout << "4. Convert Hexadecimal to Decimal" << endl;
        cout << "5. Demo (Random Decimal to Binary)" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int num;
            cout << "Enter Decimal: ";
            cin >> num;
            cout << "Binary: " << decimalToBinary(num) << endl;
        }
        else if (choice == 2) {
            string binary;
            cout << "Enter Binary: ";
            cin >> binary;
            int result = binaryToDecimal(binary);
            if (result != -1)
                cout << "Decimal: " << result << endl;
        }
        else if (choice == 3) {
            int num;
            cout << "Enter Decimal: ";
            cin >> num;
            cout << "Hexadecimal: " << decimalToHex(num) << endl;
        }
        else if (choice == 4) {
            string hexStr;
            cout << "Enter Hexadecimal: ";
            cin >> hexStr;
            // Convert to uppercase to support both cases
            transform(hexStr.begin(), hexStr.end(), hexStr.begin(), ::toupper);
            cout << "Decimal: " << hexToDecimal(hexStr) << endl;
        }
        else if (choice == 5) {
            demo();
        }
        else if (choice == 6) {
            cout << "Exiting program..." << endl;
        }
        else {
            cout << "Invalid choice, try again!" << endl;
        }
    } while (choice != 6);

    return 0;
}

