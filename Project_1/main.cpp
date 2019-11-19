#include <iostream>
#include <vector>
#include <stdio.h>
#include "NumericalMethod/Find_root.h"
using namespace std;

COMAID::Find_root * new_equation_handle(){
    cout << "Please input equation (Ex . 2*x + 1 = 5 )\n" << ">> " ;
    string equation_string;
    getline(cin,equation_string);
    //cout << equation_string;
    try {
        auto eqn = new COMAID::Find_root(equation_string);
        return eqn;
    }
    catch (string e){
        cout << e << endl;
    }
    return NULL;
}


void list_function(){

}

void info(){
    cout << "-------------------------------INFO-------------------------------------------------------\n";
    cout << "Equation that can be solve is one varible equation varible that this program\n";
    cout << "recognize as unknown is 'x' Ex . '2*ln(x^2) = 10*x' \n";
    cout << "Every Equations that insert in to this program need to writing correctly in \n";
    cout << "form that computers can recognize and multipy operator are require Ex. '2(3) + 5 = x'\n";
    cout << "is not allowed the corrected one is '2*(3) + 5 = x' , '2sin(x) = 1/2' is wrong  \n";
    cout << "corrected one is '2*sin(x) = 1/2' \n";
    cout << "blank spaces in equation will be all deleted automaticaly you can type in spaces\n";
    cout << "as you want Ex . ' 2*x + s in (x  ^2)  = 1  0 ' will be recognize as '2*x+sin(x^2) = 10'\n";
    cout << "------------------------------------------------------------------------------------------\n";
}

void solve_handle(COMAID::Find_root * Equation , int maxiter , double allowed_error){
    cout << "[1] Bi-Section Method\n";
    cout << "[2] False Position Method\n";
    cout << "[3] One point iteration Method\n";
    cout << "[4] Back\n";
    cout << "Please select option :";
    string option,xL,xR;
    getline(cin,option);
    try{
    switch (stoi(option)){
        case 1:
            cout << "Bi-Section Method Require two Initial condition to solve for solution\n";
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
            cout << "False Position Method Require two Initial condition to solve for solution\n";
            cout << "Please set initial xL and xR thus xL have to be smaller than xR and root\n";
            cout << "must be within xL and xR\n";
            cout << "xL :";
            getline(cin,xL);
            cout << "xR :";
            getline(cin,xR);
            Equation->set_error(allowed_error);
            Equation->bi_section(stod(xL),stod(xR),maxiter,true);
            if(!Equation->false_position(stod(xL),stod(xR),maxiter,true).first){
                
            }
            break;
        case 3:
            cout << "One Point iteration Method Require one Initial condition to solve for solution\n";
            cout << "Please set initial guesses for solution :";
            getline(cin,xL);
            Equation->one_point_iteration(stod(xL),maxiter,true);
            break;
        case 4:
            break;
        default:
            cout << "Invalid input\n";
    }

    }
    catch (string errmsg) {
        cout << errmsg << endl;
    }
}

void help_handle(){
    
    cout << "[1] Infomation\n";
    cout << "[2] Help Bisection Method\n";
    cout << "[3] Help False Position Method\n";
    cout << "[4] Help One point iteration Method\n";
    cout << "Please select option :";
    string option;
    getline(cin,option);
    switch (stoi(option)){
        case 1:
            info();
            break;
        case 2:
            cout << "HELP BI\n";
            break;
        case 3:
            cout << "HELP Fales\n";
            break;
        case 4:
            cout << "HELP ONE\n";
            break;
        default:
            cout << "Invalid input\n";
    }
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
    cout << "-------------------WELCOME TO EQUATION SOLVER PROGRAM-----------------------\n";
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
        cout << "[3] Set error\n";
        cout << "[4] Set Max iterations loop(s)\n";
        cout << "[5] Help\n";
        cout << "[6] Exit\n";
        cout << "Please select option :";
        try{
            string option,inp;
            getline(cin,option);
            switch (stoi(option)){
                case 1:
                    if(Equation != NULL) delete Equation;
                    Equation = new_equation_handle();
                    break;
                case 2:
                    solve_handle(Equation,maxiter,allowed_error);
                    break;
                case 3:
                    cout << "Please input error in % (Ex. 1%) : ";
                    getline(cin,inp);
                    allowed_error = stod(inp)/100;
                    break;
                case 4:
                    cout << "Please input Max iteration loop(s) : ";
                    getline(cin,inp);
                    maxiter = stoi(inp);
                    break;
                case 5:
                    help_handle();
                    break;
                case 6:
                    mainloop = false;
                    break;
                default:
                    cout << "Invalid input\n";
                    break;
            }
        }
        catch (exception e) {
            cout << "Invalid input exec \n";
        }
        
        
    }

}


