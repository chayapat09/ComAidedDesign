#include <iostream>
#include <vector>
#include "P2I.h"

using namespace COMAID; // Don't change namespace

int main(){
    /*
    Operator_Operand(Number) -> Number (float)

    Operator :

        Two Operands Operators Ex. A + B , A / B ;Operator is between Operands
            plus()    -> +
            minus()   -> -
            multipy() -> *
            devide()  -> /
            power()   -> ^

        One Operands Operators Ex. sin(A) , ln(A) ; Some need to have namespace COMAID because std:: 
            COMAID::sin()                           also has method / class name sin() ,cos() ...
            COMAID::cos()
            COMAID::tan()
            COMAID::sinh()
            COMAID::cosh()
            COMAID::tanh()
            ln()

    */

    // 2 * ( sin ( 2 + cos ( 20^2 ) ) ) * ln( 2 )
    std::vector<Operator_Operand *> equation;     //Vector for store

    equation.push_back(new Operator_Operand(2));  // Number   2
    equation.push_back(new multipy());            // Operator * 
    equation.push_back(new open_parentheses());   // Operator (
    equation.push_back(new COMAID::sin());        // Operator sin
    equation.push_back(new open_parentheses());   // Operator (
    equation.push_back(new Operator_Operand(2));  // Number   2
    equation.push_back(new plus());               // Operator +
    equation.push_back(new COMAID::cos());        // Operator cos
    equation.push_back(new open_parentheses());   // Operator (
    equation.push_back(new Operator_Operand(20)); // Number   20
    equation.push_back(new power());              // Operator ^
    equation.push_back(new Operator_Operand(2));  // Number   2
    equation.push_back(new close_parentheses());  // Operator )
    equation.push_back(new close_parentheses());  // Operator )
    equation.push_back(new close_parentheses());  // Operator )
    equation.push_back(new multipy());            // Operator *
    equation.push_back(new ln());                 // Operator ln
    equation.push_back(new open_parentheses());   // Operator (
    equation.push_back(new Operator_Operand(2));  // Number   2
    equation.push_back(new close_parentheses());  // Operator )

    std::cout << calculate(equation) << std::endl; // Calculate && Print


    //sin( 20 )
    std::vector<Operator_Operand *> equation2;

    equation2.push_back(new COMAID::sin());
    equation2.push_back(new open_parentheses());
    equation2.push_back(new Operator_Operand(20));
    equation2.push_back(new close_parentheses());
    std::cout << calculate(equation2) << std::endl; // Calculate && Print

    //sin( cos( tan( 54.12 ) ) )
    std::vector<Operator_Operand *> equation3;

    equation3.push_back(new COMAID::sin());
    equation3.push_back(new open_parentheses());
    equation3.push_back(new COMAID::cos());
    equation3.push_back(new open_parentheses());
    equation3.push_back(new COMAID::tan());    
    equation3.push_back(new open_parentheses());
    float a = 54.12;
    equation3.push_back(new Operator_Operand(a));
    equation3.push_back(new close_parentheses());
    equation3.push_back(new close_parentheses());
    equation3.push_back(new close_parentheses());
    std::cout << calculate(equation3) << std::endl; // Calculate && Print
}