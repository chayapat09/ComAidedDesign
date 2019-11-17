#include <iostream>
#include <string>

#include "Root_eqn.h"

using namespace std;

int main(){
    /*
    COMAID::Find_root test1("e ^ ( -x / 4 ) * ( 2 - x ) - 1 = 0"); 
    // e ^ -x -> means e ^ -1 * x please use pherenthesis ()
    test1.set_error(0.001);
    test1.bi_section(0,20,20,true);
    */

    /*
    COMAID::Find_root test2("-x+2 = 0");
    test2.bi_section(0,20,20,true);
    test2.false_position(0,20,20,true);
    */
    

    /*
    COMAID::Find_root test3("-3*(-2*x) + (-x) - 2 = 0");
    test3.bi_section(-10,10,20,true);
    */

    /*
    COMAID::Find_root test4("-3*(-2*-x) + (-x) - 2 = 0");
    test4.set_error(0);
    test4.bi_section(-10,10,50,true);
    */
    

    /*
    COMAID::Find_root test5("x^2 + 2 * x + 1 = 0");
    test5.set_error(0);
    test5.bi_section(-1,2,50,true);
    test5.false_position(-1,2,50,true);
    */
    
    /*
    COMAID::Find_root test6("x^2 + 2*x +1 = 0");
    test6.set_error(0.000001);
    std::cout << test6.bi_section(-10,20,1000,true).second;
    test6.false_position(-10,10,true);
    */

    /*
    COMAID::Find_root test7("( sin ( x ^ 4 - 2 * x + 5 ) )^7 = 2");
    test7.set_error(0);
    std::cout << test7.bi_section(-2,2,true).second;
    test7.false_position(-2,2,true);
    */

    /*
    COMAID::Find_root test8(" x = 2*sin(x) ");
    test8.set_error(0);
    test8.one_point_iteration(0.2);
    */

    
    /*
    string B = "( ( 42.471 + 309.068*x ) / ( 309.71*x - x^2 ) )";
    string eqn = "( ( 0.33+B*x )^2 +0.586^2 )  * 1.111^2/B^2 = 0.9995 * ( (0.33+x)^2 +0.586^2)";
    COMAID::Equation::replace_string(eqn , "B" , B);
    //cout << eqn << endl;
    COMAID::Find_root test_9(eqn);
    test_9.set_error(0);
    test_9.false_position(0.4,0.6,30,true); // Show f(a) and f(b) when ans not in range
    */

    /*
    COMAID::Find_root test_10("pi/4 = (atan(x))^1.2");
    test_10.set_error(0);
    test_10.false_position(0,1.3,30,true); // xl = -2 cause nan%
    // Error occur when value new = 0 or small value
    // Error occur when value_new = 0 that will cause error = Inf
    */

    /*
    COMAID::Find_root test11("-sin(x)  = 0");
    test11.set_error(0);
    test11.bi_section(-1,2,10,true); // Too precision
    */
    


    
}