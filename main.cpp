#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

uint64_t getTime() {
    return chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
}

double stack[65536] = {0};
unsigned int top = 0;
bool debug_enabled = true;

void push(double newNum) {
    stack[++top] = newNum;
}

void printDouble(double num) {
    string str = to_string(num);

    char integerPart[32];
    int intLength = 0;
    for (int i = 0; i < 32; i++) integerPart[i] = '\0';

    char decimalPart[32];
    int decimalLength = 0;
    for (int i = 0; i < 32; i++) decimalPart[i] = '\0';

    bool isWhole = true;
    int decimalPos = -1;

    for (int i = 0; i < str.length(); i++) {
        if (decimalPos == -1) {
            if (str[i] == '.') {
                decimalPos = i;
            } else {
                integerPart[intLength++] = str[i];
            }
        } else {
            if (str[i] != '0') isWhole = false;
            decimalPart[decimalLength++] = str[i];
        }
    }

    cout << integerPart;
    if (!isWhole) {

        for (int i = decimalLength - 1; i != 0; i--) {
            if (decimalPart[i] == '0') {
                decimalPart[i] = '\0';
                decimalLength--;
            } else {
                break;
            }
        }

        if (decimalLength != 0) cout << '.' << decimalPart;
    }
}

int ssl(string program) {
    cout << fixed;
    int programSize = program.length();
    uint64_t start = getTime();
    for (int i = 0; i < programSize; i++) {
        program[i] = toupper(program[i]);
    }

    for (int i = 0; i < programSize; i++) {
        switch (program[i]) {
            case 'A':
                push(0);
                break;
            case 'B':
                top--;
                break;

            case 'I':
                stack[top]++;
                break;
            case 'V':
                stack[top] += 5;
                break;
            case 'D':
                stack[top]--;
                break;
            case 'W':
                stack[top] -= 5;
                break;

            case 'L': {
                double temp = stack[top];
                stack[top] = stack[top - 1];
                stack[top - 1] = temp;
                break;
            }

            case 'G':
                push(stack[top] + stack[top - 1]);
                break;
            case 'M':
                push(stack[top] * stack[top - 1]);
                break;
            case 'C':
                push(stack[top] - stack[top - 1]);
                break;
            case 'P':
                push(stack[top] / stack[top - 1]);
                break;
            case 'E':
                push(fmod(stack[top], stack[top - 1]));
                break;

            case 'K':
                if (stack[top] == 0.0)
                    i++;
                break;

            case 'T': {
                if (stack[top] != 0.0)
                    break;
                // Jump to the corresponding u
                i++;
                for (int depth = 1; i < programSize && depth != 0; i++) {
                    if (program[i] == 'T')
                        depth++;
                    else if (program[i] == 'U')
                        depth--;
                }
                i--;
                break;
            }

            case 'U': {
                if (stack[top] == 0.0)
                    break;
                // Jump to the corresponding t
                i--;
                for (int depth = 1; i > 0 && depth != 0; i--) {
                    if (program[i] == 'U')
                        depth++;
                    else if (program[i] == 'T')
                        depth--;
                }
                i++;

                break;
            }

            case 'Q':
                push(stack[top]);
                break;

            case 'N':
                push((double)stack[top] == stack[top - 1]);
                break;

            case 'F':
                cout << (char)abs(trunc(stack[top]));
                break;
            case 'X':
                printDouble(stack[top]);
                break;

            case 'J': {
                char input;
                cin >> input;
                push(input);
                break;
            }

            case 'H': {
                string input;
                cin >> input;
                push(stod(input));
                break;
            }

            case 'R':
                push(top);
                break;

            case 'Y':
                top = 0;
                break;

            case 'Z':
                cout << "\n\n= [Execution Halted] =" << endl;
                return EXIT_SUCCESS;
        }
    }

    uint64_t diff = getTime() - start;
    cout << "\n\n-- Execution time: " << to_string(diff) << "ms --\n"
         << endl;
    return EXIT_SUCCESS;
}

int main(int argc, char **argv) {
    if (argc == 1) {
        string input;
        cout << "-- Activating REPL Mode --\n"
             << endl;
        while (true) {
            cin >> input;
            ssl(input);
        }
    } else if (argc == 2) {
        string program = "";
        string line;
        ifstream readfile(argv[1]);
        while (getline(readfile, line)) program += "\n" + line;
        readfile.close();
        return ssl(program);
    } else {
        printf("There are no currently supported flags!");
        return EXIT_FAILURE;
    }
}