#include "infixToPostfix.h"

int main(){
    InfixToPostfix itp("(A + B) * (C-D)");

    itp.showInfix();

    itp.showPostfix();
}
