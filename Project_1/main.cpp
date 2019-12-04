#include <iostream>
#include <vector>
#include <stdio.h>
#include "src/NumericalMethod/Find_root.h"
using namespace std;

void wait(){
    do 
    {
        cout << '\n' << "Press a enter key to continue...";
    } while (cin.get() != '\n');
}

COMAID::Find_root * new_equation_handle(COMAID::Find_root * Equation){
    cout << "Please input equation (Ex . 2*x + 1 = 5 )\n" << ">> " ;
    string equation_string;
    getline(cin,equation_string);
    //cout << equation_string;
    auto tmp = Equation;
    try {
        Equation =  new COMAID::Find_root(equation_string);
        delete tmp;
        return Equation;
    }
    catch (string e){
        cout << '\n' << e << endl;
        wait();
        
    }
    return tmp;
}

void list_operator(){
    cout << "\nAvaliable Operators:\n";
    cout << "1.Plus '+'\n";
    cout << "2.Minus '-'\n";
    cout << "3.Multipy '*'\n";
    cout << "4.Devide '/'\n";
    cout << "5.Power '^'\n";
}

void list_function(){
    cout << "\nAvaliable Mathematical Functions:\n";
    cout << "1.sin function    : sin(...) \n";
    cout << "2.cosine function : cos(...) \n";
    cout << "3.tan function    : tan(...) \n";
    cout << "4.arcsin function : asin(...) \n";
    cout << "5.arccos function : acos(...) \n";
    cout << "6.arctan function : atan(...) \n";
    cout << "7.hyperbolic sine function    : sinh(...) \n";
    cout << "8.hyperbolic cossine function : cosh(...) \n";
    cout << "9.hyperbolic tan function     : tanh(...) \n";
    cout << "10.Natural logarithm function : ln(...) \n";
    cout << "11.Square root function       : sqrt(...) \n\n";

    cout << "NOTE: All Trigonometric function angle are in radians\n";
}

void info(){
    cout << "\n-------------------------------------INFO-------------------------------------------------\n";
    cout << "Equation that can be solve is one varible equation.Varible that this program\n";
    cout << "recognize as unknown is 'x' Ex . '2*ln(x^2) = 10*x' \n\n";
    cout << "Every Equations that insert in to this program need to writing correctly in \n";
    cout << "form that computers can recognize. \n";
    //cout << "is not allowed the corrected one is '2*(3) + 5 = x' , '2sin(x) = 1/2' is wrong  \n";
    //cout << "corrected one is '2*sin(x) = 1/2' \n";
    cout << "blank spaces in equation will be all deleted automaticaly you can type in spaces\n";
    cout << "as you want Ex . ' 2*x + s in (x  ^2)  = 1  0 ' will be recognize as '2*x+sin(x^2) = 10'\n\n";
    cout << "Pharenthesis of function are always require as usual. For convenient some multipy operator * \n";
    cout << "can be neglect in these condition : \n";
    cout << "1.Numeric and varible '2*x' -> '2x' \n";
    cout << "2.Between numeric and functions or (...) '2.75 * sin(x)' -> '2.75sin(x)' or '3 * (2)' -> '3(2)' \n";
    cout << "3.Between two () () '(3-6*5) * (7^2)' -> (3-6*5)(7^2) \n\n";
    cout << "Examples Allowed Equation : -x(x^2+1)(x+2) - 2sinh(-cos(x)) = ln(-3-x)\n";
    cout << "------------------------------------------------------------------------------------------\n";
}

void solve_handle(COMAID::Find_root * Equation , int maxiter , double allowed_error){
    if (Equation == NULL) {
        cout << "\nPlease set Equation first!\n";
        wait();
        return;
    }
    cout << "\n[1] Bi-Section Method\n";
    cout << "[2] False Position Method\n";
    cout << "[3] One point iteration Method\n";
    cout << "[4] Back\n";
    cout << "Please select option :";
    string option,xL,xR;
    getline(cin,option);
    try{
    switch (stoi(option)){
        case 1:
            cout << "\nBi-Section Method Require two Initial condition to solve for solution\n";
            cout << "Please set initial xL and xR thus xL have to be smaller than xR and root\n";
            cout << "must be within xL and xR\n";
            cout << "xL :";
            getline(cin,xL);
            cout << "xR :";
            getline(cin,xR);
            Equation->set_error(allowed_error);
            Equation->bi_section(stod(xL),stod(xR),maxiter,true);
            break;
        case 2:
            cout << "\nFalse Position Method Require two Initial condition to solve for solution\n";
            cout << "Please set initial xL and xR thus xL have to be smaller than xR and root\n";
            cout << "must be within xL and xR\n";
            cout << "xL :";
            getline(cin,xL);
            cout << "xR :";
            getline(cin,xR);
            Equation->set_error(allowed_error);
            Equation->false_position(stod(xL),stod(xR),maxiter,true);
            break;
        case 3:
            cout << "\nOne Point iteration Method Require one Initial condition to solve for solution\n";
            cout << "Please set initial guesses for solution :";
            getline(cin,xL);
            Equation->one_point_iteration(stod(xL),maxiter,true);
            break;
        case 4:
            break;
        default:
            cout << "\nInvalid input\n";
    }

    }
    catch (string errmsg) {
        cout << errmsg << endl;
    }
    wait();
}

void help_handle(){
    
    cout << "\n[1] Infomation\n";
    cout << "[2] Avaliable Operators\n" ;
    cout << "[3] Avaliable functions\n" ;
    /*
    cout << "[4] Help Bisection Method\n";
    cout << "[5] Help False Position Method\n";
    cout << "[6] Help One point iteration Method\n";
    */
    cout << "Please select option :";
    string option;
    getline(cin,option);
    switch (stoi(option)){
        case 1:
            info();
            break;
        case 2:
            list_operator();
            break;
        case 3:
            list_function();
            break;
        /*
        case 4:
            cout << "HELP BI\n";
            break;
        case 5:
            cout << "HELP Fales\n";
            break;
        case 6:
            cout << "HELP ONE\n";
            break;
        */
        default:
            cout << "\nInvalid input\n";
    }
    wait();

}
void help_bisection(){

}

void help_false_position(){
    
}

void help_one_point_iteration(){

}

int main(){
    bool mainloop = true;
    COMAID::Find_root * Equation = NULL;
    int maxiter = 20;
    double allowed_error = 0.01;
    cout << "\n-------------------WELCOME TO EQUATION SOLVER PROGRAM-----------------------\n";
    cout << "This program is example for implementing program by use of Find_root Library\n";
    cout << "this program can calculate root of equation by inserting string of equation \n";
    cout << "----------------------------------------------------------------------------\n";
    while (mainloop){
        cout << "\nEquation : ";
        if (Equation == NULL) {
            cout << "<Please Set Equation to calculate>\n";
        }
        else{
            cout << Equation->get_equation() << '\n';
        }
        cout << "Max iteration : " + to_string(maxiter) + " loop(s)\n" ;
        cout << "Allowed Error : " + to_string(allowed_error* 100)  + " %\n\n";
        cout << "[1] Set Equation\n";
        cout << "[2] Solve Equation\n";
        cout << "[3] Help\n";
        cout << "[4] Set error\n";
        cout << "[5] Set Max iterations loop(s)\n";
        cout << "[6] Exit\n";
        cout << "Please select option :";
        try{
            string option,inp;
            getline(cin,option);
            switch (stoi(option)){
                case 1:
                    Equation = new_equation_handle(Equation);
                    break;
                case 2:
                    solve_handle(Equation,maxiter,allowed_error);
                    break;
                case 3:
                    help_handle();
                    break;
                case 4:
                    cout << "Please input error in % (Ex. 1%) : ";
                    getline(cin,inp);
                    allowed_error = stod(inp)/100;
                    break;
                case 5:
                    cout << "Please input Max iteration loop(s) : ";
                    getline(cin,inp);
                    maxiter = stoi(inp);
                    break;

                case 6:
                    mainloop = false;
                    break;
                default:
                    cout << "\nInvalid input\n";
                    wait();
                    break;
            }
        }
        catch (exception e) {
            cout << "\nInvalid input\n";
            wait();
        }
        
        
    }

}


