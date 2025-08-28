#include <iostream>
#include <string>
#include <bitstring>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function 1: Decimal to Binary
string decimalToBinary(int num) {
    return bitstring<32>(num).to_string().erase(0, bistring<32>(num).to_string().find('1'));
}

// Function 2: Binary to Decimal
int binaryToDecimal(string binary) {
    return stoi(binary, 0, 2);
}

// Function 3: Decimal to Hexadecimal
string decimalToHex(int num) {
    stringstream ss;
    ss << hex << num;
    return ss.str();
}

// Function 4: Hexadecimal to Decimal
int hexToDecimal(string hexStr) {
    return stoi(hexStr, 0, 16);
}

// Demo function: generate random number 0-99 and convert to binary
void demo() {
    srand(time(0));
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
            cout << "Decimal: " << binaryToDecimal(binary) << endl;
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
