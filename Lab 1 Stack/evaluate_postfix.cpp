#include <iostream>
#include "stack.hpp"
#include <string>
#include <sstream>

using namespace std;

bool isOperator (char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/') ;
}

int evaluateOperation (int x, int y, char ch)
{
    switch (ch)
    {
    case '+': return x + y;
    case '-': return x - y;
    case '*': return x * y;
    case '/': return x / y;
    default:  return 0;
    }
}

int main()
{
    string postfix;
    cout<<"Enter comma-separated postfix expression: ";
    getline(cin, postfix);
    Stack stack(postfix.length());

    istringstream myParser(postfix); 
    string token; 

    while (getline(myParser, token, ',')) 
    {


        if(isdigit(token[0])){ 
            stack.push(token);
        }

        else if (isOperator(token[0]) && token.length() == 1) {
            int a = stoi(stack.pop());
            int b = stoi(stack.pop());
            int c = evaluateOperation(b, a, token[0]);
            stack.push(to_string(c));
        }

        else{
            cerr << "Invalid token: " << token << endl;
        }
    }

    cout<<"Result of evaluated expression is "<< stack.pop()<<endl;
    return 0;
}

