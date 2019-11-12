#include <iostream>
#include <string>

#include "Root_eqn.h"

using namespace std;

int main(){
    COMAID::Find_root test1("e^(-x/4)*(2-x) - 1 = 0"); 
    // e ^ -x -> means e ^ -1 * x please use pherenthesis ()
    test1.set_error(0.001);
    test1.bi_section(0,20,20);

    COMAID::Find_root test2("-x+2 = 0");
    test2.bi_section(0,20,20);


    COMAID::Find_root test3("-3*(-2*x) + (-x) - 2 = 0");
    test3.bi_section(-10,10,20);

    COMAID::Find_root test4("-3*(-2*-x) + (-x) - 2 = 0");
    test4.set_error(0);
    test4.bi_section(-10,10,50);

    COMAID::Find_root test5("2  *  Si n ( si n H (cosh(cos   h(cos( 1*2*x*x^x^cosh(32.33)))))) = 1.33");
    test5.set_error(0);
    test5.bi_section(-1,2,50);
}