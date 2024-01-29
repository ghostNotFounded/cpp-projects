#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
    // Check if a value has been provided as a command-line argument
    if (argc < 2) {
        cerr << "Please provide a value as a command-line argument." << endl;
        return 1;
    }

    char* value_char = argv[1];

    int value;
    try {
        // Convert the command-line argument to an integer
        sscanf(value_char, "%d", &value);

        int multiplier = 0;

        unordered_map <char, int>  multipliers;

        multipliers['D'] = 1;
        multipliers['h'] = 2;
        multipliers['k'] = 3;
        multipliers['M'] = 6;
        multipliers['G'] = 9;
        multipliers['T'] = 12;
        multipliers['P'] = 15;
        multipliers['E'] = 18;

        char c = value_char[sizeof(value_char) / sizeof(char) - 1];

        if (isalpha(c) && multipliers.count(c)) {
            multiplier = multipliers.at(c);
        }

        // Round the value down to the nearest multiple of 10
        value = value * int(pow(10, multiplier)) ;
    }
    catch (const std::exception& e) {
        cerr << e.what() << '\n';
        return 1;
    }

    // Create a map of colors to their corresponding resistance values
    string map[10] = {"Black", "Brown", "Red", "Orange", "Yellow", "Green", "Blue", "Violet", "Grey", "White"};

    string result;

    // Calculate the first resistance band value
    int digit = value % 10;
    // If there are any trailing zeros, increment the value until there are no more to calculate multiplier
    while (value % 10 == 0 && value >= 100) {
        digit++;
        value /= 10;
    }

    // Check if the resistance value is too large
    if (digit <= 9) {
        result = map[digit];
    } else {
        cout << "Resistance is too large" << endl;
        return 1;
    }

    // Calculate the other two resistance band values
    while (value > 0) {
        digit = value % 10;
        result = map[digit] + " " + result;
        value /= 10;
    }

    cout << result << endl;

    return 0;
}