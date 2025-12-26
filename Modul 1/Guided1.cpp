#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    char op;
    float num1, num2;

    // it allows user to enter operator i.e. +, -, *,/
    cout<<"Enter operator (+, -, *, /): ";
    cin>>op;

    // it allows user to enter the operands
    cout<<"Enter two operands: ";
    cin>>num1>>num2;

    // switch statement begins
    switch (op){
        // if user enters +
        case '+':
            cout<<"Result: "<<num1 + num2;
            break;
        // if user enters -
        case '-':
            cout<<"Result: "<<num1 - num2;
            break;
        // if user enter *
        case '*':
            cout<<"Result: "<<num1 * num2;
            break;
        // if user enter /
        case '/':
            if (num2 != 0) {
                cout<<"Result: "<< fixed << setprecision(2)<< num1 / num2;

    } else {
        cout << "Error! Division by zero is not allowed.";
    }
    break;
    // if the operator is other than +, -, *, /'
    // error message will display
    default:
        cout<<"Error! Operator is not correct";
    } // switch statement ends

    return 0;
}