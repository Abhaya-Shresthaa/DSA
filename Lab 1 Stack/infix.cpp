#include <iostream>
#include <string>
#include "stack.hpp"
#include <algorithm> // for std::reverse on any iterator
using namespace std;

int precedence(string op) {
    if (op == "*" || op == "/") return 2;
    if (op == "+" || op == "-") return 1;
    return 0;
} 

string convertExpression (string infix, bool toPostfix)
{
    Stack stack(static_cast<int>(infix.length())); //length gives size_t
    string expression;

    for (char ch : infix) {
        string sh = string(1, ch); //string that repeats ch once
        if(ch==' ')
            {continue;}
        else if (isalnum(ch)) {
            expression += ch;
        }
        else if (ch == '(') {
            stack.push(sh);
        }
        else if (ch == ')') {
            while (!stack.isEmpty() && stack.peek() != "(") {
                expression += stack.pop();
            }
            stack.pop();
        }
        else
        {  
            while(
                !stack.isEmpty() && 
                stack.peek()!="(" &&
                ( toPostfix 
                    ? precedence(sh) <= precedence(stack.peek()) 
                    : precedence(sh) < precedence(stack.peek())
                ) // Parentheses force the && (short-circuit) checks to run before the ?: operator avoiding peek on an empty stack
                )
            {
                expression += stack.pop();
            }

            stack.push(sh);
                                
        }
    }

    while (!stack.isEmpty()) {
        if(stack.peek() == "(") stack.pop();
        else expression += stack.pop();
    }
    
    return expression;

}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    cout << "Postfix Expression: " <<   convertExpression(infix, true) << endl;
    string rev_infix = infix ; 
    reverse(rev_infix.begin(), rev_infix.end());

    for (int i = 0; i < rev_infix.size(); ++i) 
    {
        if (rev_infix[i] == '(')       rev_infix[i] = ')';
        else if (rev_infix[i] == ')')  rev_infix[i] = '(';
    }

    string prefix = convertExpression (rev_infix, false);
    reverse(prefix.begin(), prefix.end());
    cout<<"Prefix Expression: " << prefix <<endl;
    
    return 0;
}
