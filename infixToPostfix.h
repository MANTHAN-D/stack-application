#include "stackArrayTPT.cpp"
#include <string>

using namespace std;

class InfixToPostfix
{
private:
	string  infixExp;
	string  postfixExp;
public:
    InfixToPostfix(string = "");

	void convertToPostfix();
	bool precedence(char, char);
	void getInfix(string);
	void showInfix();
	void showPostfix();
};

