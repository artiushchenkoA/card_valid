#include <iostream>
#include <string>

bool isNumberString(std::string &s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    } return true;
}

int main() {
    std::cout << "This program uses the Luhn Algorigthm to validate a CC number." << std::endl;
    std::cout << "You can enter 'exit' anytime to quit." << std::endl;
    std::string ccNumber;

    while (true) {
        std::cout << "Enter CC Number: " << std::endl;
        std::cin >> ccNumber;

        if (ccNumber == "exit") {
            break;
        } else if (!isNumberString(ccNumber)) {
            std::cout << "Invalid CC Number." << std::endl;
            continue;
        }

        int len = ccNumber.length();
        int index = 0;

        // Step 1 is to double every second digit, starting from the right. If it
        // results in a two digit number, add both the digits to obtain a single
        // digit number. Finally, sum all the answers to obtain 'index'.

        for (int i = len - 2; i >= 0; i = i - 2) {
            int tmp = ((ccNumber[i] - 48) * 2);
            if (tmp > 9) {
                tmp = (tmp / 10) + (tmp % 10);
            }
            index += tmp;
        }
        // Step 2 is to add every odd placed digit from the right to the value
        // 'doubleEvenSum'.

        for (int i = len - 1; i >=0; i = i - 2) {
            index += (ccNumber[i] - 48);
        }

        // Step 3 is to check if the final 'doubleEvenSum' is a multiple of 10.
        // If yes, it is a valid CC number. Otherwise, not.

        if (index % 10 == 0) {
            std::cout << "Valid CC Number." << std::endl;
        } else {
            std::cout << "Invalid CC Number." << std::endl;
        }
    }
    return 0;
}


