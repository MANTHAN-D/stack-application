#include "infixToPostfix.h"
#include <iostream>
#include <string>

using namespace std;

InfixToPostfix::InfixToPostfix(string infix)
{
	infixExp = infix;
	convertToPostfix();
}

void InfixToPostfix::convertToPostfix()
{
	stackArrayTPT<char>  stack(50);
	char stackOpr;

	//stack.initializeStack();
	postfixExp = "";

	int len = infixExp.length();

	for (int i = 0; i < len; i++)
		if (infixExp[i] >= 'A' && infixExp[i] <= 'Z')
			postfixExp = postfixExp + infixExp[i];
		else
		{
			switch (infixExp[i])
			{
			case '(':
                stack.push(infixExp[i]);
				break;

			case ')':
                stackOpr = stack.pop();

                while (stackOpr != '(')
                {
                    postfixExp = postfixExp + stackOpr;

                    if (!stack.isEmptyStack())
                    {
                        stackOpr = stack.pop();
                    }
			        else
                        break;
                }
                break;

			case ';':
			case ' ':
                break;

			default:
                if (stack.isEmptyStack())
                    stack.push(infixExp[i]);
                else
                {
                    stackOpr = stack.pop();

                    while (precedence(stackOpr,infixExp[i]))
                    {
                        postfixExp = postfixExp + stackOpr;
                        if (!stack.isEmptyStack())
                        {
                            stackOpr = stack.pop();
                        }
                        else
                            break;
                    }

                    if (!precedence(stackOpr,infixExp[i]))
                        stack.push(stackOpr);

                    stack.push(infixExp[i]);
                }

			}//end switch
		}//end else

	while (!stack.isEmptyStack())
	{
		postfixExp += stack.pop();
	}

}//end convertToPostfix


bool InfixToPostfix::precedence(char opr1, char opr2)
{
	int prec1, prec2;

	if (opr1 == '*' || opr1 =='/')
		prec1 = 2;
	else if(opr1 == '+' || opr1 == '-')
        prec1 = 1;
    else if(opr1 ='(')
        prec1 = 0;

    if (opr2 == '*' || opr2 == '/')
        prec2 = 2;
	else if(opr2 =='+' || opr2 == '-')
        prec2 = 1;

    return(prec1 >= prec2);
}//end precedence

void InfixToPostfix::getInfix(string data)
{
    infixExp = data;
    convertToPostfix();
}

void InfixToPostfix::showInfix()
{
	cout << "Infix: " << infixExp << endl;
}


void InfixToPostfix::showPostfix()
{
	cout << "Postfix: " << postfixExp << endl;
}
