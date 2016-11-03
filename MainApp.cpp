#include "stackArrayTPT.cpp"
#include<iostream>
using namespace std;

int main1(){
    stackArrayTPT<int> stack(10);

    for(int i=0;i<10;i++){
        stack.push(i+1);
    }

    cout<<"Push done"<<endl;

    for(int i=0;i<10;i++){
        cout << stack.pop() << endl;
    }
    return 0;
}
