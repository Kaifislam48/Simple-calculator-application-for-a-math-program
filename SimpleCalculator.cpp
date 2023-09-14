/* Booma is developing a simple calculator application for a math tutoring program. The program requires input validation to ensure that only valid mathematical expressions are accepted. The program should be able to handle arithmetic expressions containing parentheses, addition, subtraction, multiplication, and division operations.


Write a function isValidMathExpression that takes a C-style string (const char* expression) as input and returns a boolean value indicating whether the expression is valid or not.


Note: The expression can contain the following elements:

The expression should be a single-digit operand

Digits: 0-9

Operators: +, -, *, /

Parentheses: (, )


You can assume that the input expression will not exceed a certain length, specified by the bufferSize = 1000 constant in the code.


Note: This is a sample question asked in an HCL interview.
Input format :

The input contains a mathematical expression.

The expression can contain digits (0–9), operators (+, -, *, /), parentheses ((), ), spaces, and tabs.
Output format :

The output displays a message indicating whether the input expression is valid or invalid.


Refer to the sample output for formatting specifications.
Code constraints :

length of the input expression <= 1000

The expression can contain a combination of digits, operators, parentheses, spaces, and tabs.
Sample test cases :
Input 1 :

(2 + 3) * 4

Output 1 :

Valid mathematical expression.

Input 2 :

{2 * 3 * 4}

Output 2 :

Invalid mathematical expression.

Input 3 :

(6+3)/4

Output 3 :

Valid mathematical expression.

Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.  */

#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

bool isValidMathExpression(const char* expression) {
    stack<char> parenthesesStack;

    for (int i = 0; i < strlen(expression); i++) {
        char c = expression[i];

        if (c == '(') {
            parenthesesStack.push(c);
        } else if (c == ')') {
            if (parenthesesStack.empty() || parenthesesStack.top() != '(') {
                return false; // Invalid: closing parenthesis without matching open parenthesis
            }
            parenthesesStack.pop();
        } else if (isdigit(c)) {
            // Digits are allowed, so we continue.
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // Operators are allowed, so we continue.
        } else if (c != ' ' && c != '\t') {
            return false; // Invalid: unexpected character
        }
    }

    return parenthesesStack.empty(); // All parentheses must be matched
}

int main() {
    const int bufferSize = 1000;
    char expression[bufferSize];

    // Read the input expression
    cin.getline(expression, bufferSize);

    if (isValidMathExpression(expression)) {
        cout << "Valid mathematical expression." << endl;
    } else {
        cout << "Invalid mathematical expression." << endl;
    }

    return 0;
}
