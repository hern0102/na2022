#include <iostream>
#include <cmath>
#include <limits>
#include "EquationSolver.h"

#define M 1000000
#define delta 0.00000001
#define epsilon 0.00000001
using namespace std;

const double pi = acos(-1);

int main(){
    cout<<"TEST B1"<<endl;
    bisection b1;
    cout<<b1.solve('1', 0, pi/2)<<endl;
    cout<<"TEST B2"<<endl;
    bisection b2;
    cout<<b2.solve('2', 0, 1)<<endl;
    cout<<"TEST B3"<<endl;
    bisection b3;
    cout<<b3.solve('3', 1, 3)<<endl;
    cout<<"TEST B4"<<endl;
    bisection b4;
    cout<<b4.solve('4', 0, 4)<<endl;
    cout<<endl;
    cout<<"TEST C5"<<endl;
    newton c5_1;
    cout<<"The root near 4.5 is "<<c5_1.solve1('5',4.5)<<endl;
    newton c5_2;
    cout<<"The root near 7.7 is "<<c5_2.solve1('5',7.7)<<endl;
    cout<<endl;
    cout<<"TEST D6"<<endl;
    secant d6;
    cout<<d6.solve('6', 0, pi/2)<<endl;
    cout<<"TEST D7"<<endl;
    secant d7;
    cout<<d7.solve('7', 1, 1.4)<<endl;
    cout<<"TEST D8"<<endl;
    secant d8;
    cout<<d8.solve('8', 0, -0.5)<<endl;
    cout<<endl;
    bisection e1;
    newton e2;
    secant e3;
    cout<<"The depth of water is solved by bisection method ,newton's method and secant method respectively "<<endl;
    cout<<e1.solve('9',0,1)<<endl<<e2.solve2('9',0)<<endl<<e3.solve('9',0,1)<<endl;
    newton f1;
    secant f2;
    cout<<"F(a)Input l,b1,D,h and it will come out the approximate of the value of alpha "<< f1.solve3('F', 34)<<endl;
    cout<<"F(b)If D=30 in. then alpha = "<< f1.solve3('F', 33)<<endl;
    cout<<"F(c)Input l,b1,D,h and it will come out the approximate of the value of alpha "<< f2.solve('F', 20, 50)<<endl;
}
