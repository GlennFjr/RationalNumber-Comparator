#include "Assignment5_GlennFortunato/rationalsGF.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using namespace rationals_GlennFortunato;

int main() {
    bool running = true;
    bool valid_answer = true;
    int answer;
    using std::cout;
    do {
        do {
            cout << "       Rational Numbers Calculator" << endl;;

            cout << "\n   1. Continue\n   2. Quit" << endl;

            cin >> answer;

            if (cin.fail()) {
                // Handle the case where the input is not an integer
                cout << "Input invalid, please select 1 or 2." << endl;
                cin.clear(); 
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                valid_answer = false;
            }
            else {
                valid_answer = true;
                if (answer == 1) {
                    running = true;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    
                }
                else if (answer == 2) {
                    running = false;
                }
                else {
                    cout << "Integer must be either 1 or 2." << endl;
                    valid_answer = false;
                }
            }
        } while (!valid_answer);
        RationalNumber rational1, rational2;

        bool validInput = false;

        do {
            cout << "Enter a rational number in the form a/b: ";
            string input;
            getline(cin, input);

            istringstream stream(input);
            if (stream >> rational1) {
                validInput = true;
            }
            else {
                cout << "Invalid input, please enter the rational number in the form a/b." << endl;
            }
        } while (!validInput);

        validInput = false;

        do {
            cout << "Enter the second rational number in the form a/b: ";
            string input;
            getline(cin, input);

            istringstream stream(input);
            if (stream >> rational2) {
                validInput = true;
            }
            else {
                cout << "Invalid input, please enter the rational number in the form a/b." << endl;
            }
        } while (!validInput);

        // Output
        cout << endl << "Rational 1: " << rational1 << endl;
        cout << "Rational 2: " << rational2 << endl << endl;

        cout << "Equal? " << (rational1 == rational2 ? "Yes" : "No") << endl;
        cout << "Not Equal? " << (rational1 != rational2 ? "Yes" : "No") << endl;
        cout << "Less Than? " << (rational1 < rational2 ? "Yes" : "No") << endl;
        cout << "Less Than or Equal? " << (rational1 <= rational2 ? "Yes" : "No") << endl;
        cout << "Greater Than? " << (rational1 > rational2 ? "Yes" : "No") << endl;
        cout << "Greater Than or Equal? " << (rational1 >= rational2 ? "Yes" : "No") << endl;

        // algebra
        RationalNumber sum = rational1 + rational2;
        RationalNumber difference = rational1 - rational2;
        RationalNumber product = rational1 * rational2;
        RationalNumber quotient = 0;
        if (rational2.getNum() != 0) {
            quotient = rational1 / rational2;
        }
        RationalNumber negation1 = -rational1;
        RationalNumber negation2 = -rational2; 

        // algebra output
        cout << "Sum: " << sum << endl;
        cout << "Difference: " << difference << endl;
        cout << "Product: " << product << endl;
        if (rational2.getNum() == 0) {
            cout << "Quotient: N/A - division by 0" << endl;
        }
        else {
            cout << "Quotient: " << quotient << endl;
        }
        cout << "Negation: " << negation1 << endl;
        cout << "Negation: " << negation2 << endl;

        return 0;
    } while (running);

}
