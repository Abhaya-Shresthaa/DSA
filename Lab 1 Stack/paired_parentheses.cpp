#include<iostream>
#include "stack.hpp"
#include <string>

using namespace std;

int main()
{
    string expression;

    cout<<"Enter: ";
    getline(cin, expression);
    Stack stack(expression.length());

    for (char ch : expression)
    {
        if (ch=='(') stack.push("(");
        if(ch==')')
        {
            if (stack.isEmpty()){
                cout << "Invalid Expression.\n";
                return 1;
            }
            else stack.pop();
        }
    }
    if(!stack.isEmpty()) cout << "Invalid Expression.\n";
    else cout <<"The given expression is valid.";
    return 0;
}