/*****************************************************************************************************************************************

Stack_Postfix_Evaluation.cpp
Created on: 28-Feb-2021
Author: Malkeet Mehra

The Postfix notation is used to represent algebraic expressions.
The expressions written in postfix form are evaluated faster compared to infix notation as parenthesis are not required in postfix.

Following is algorithm for evaluation postfix expressions.
1) Create a stack to store operands (or values).
2) Scan the given expression and do following for every scanned element.
…..a) If the element is a number, push it into the stack
…..b) If the element is a operator, pop operands for the operator from stack. Evaluate the operator and push the result back to the stack
3) When the expression is ended, the number in the stack is the final answer

******************************************************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int postfix_evaluation(string postfix)
{
    stack <int> s;
    int i = 0;
    int value;
    while(postfix[i])
    {
        if(postfix[i] >= '0' && postfix[i] <='9')
            s.push(postfix[i]-'0');
        else
        {
            int val1 = s.top();
            s.pop();
            int val2 = s.top();
            s.pop();
            if(postfix[i] == '^')
                s.push(val2^val1);
            else if(postfix[i] == '/')
                s.push(val2/val1);
            else if(postfix[i] == '*')
                s.push(val2*val1);
            else if(postfix[i] == '+')
                s.push(val2+val1);
            else if(postfix[i] == '-')
                s.push(val2-val1);
            else if(postfix[i] == '%')
                s.push(val2%val1);
        }
        i++;
    }
    value = s.top();
    s.pop();
    return value;
}

int main()
{
    string postfix;
    getline(cin, postfix);
    cout << postfix_evaluation(postfix);
    return 0;
}
