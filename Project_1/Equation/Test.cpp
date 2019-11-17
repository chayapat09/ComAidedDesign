#include <iostream>
#include <vector>
#include "Equation.h"
#include <string>
#include <sstream>

using namespace COMAID;

int main(){
    /*
    //std::string s = "2 * ( Sin ( 2 + cos ( 20 ^ 2 + x )    ) ) * ln ( x )   ";// { "2" , "*" ,"(" }
    std::string ss("2*Sin(sinH(cosh(cosh(cos(1*2*x*x^x^cosh(32.33))))))");
    Equation e(ss);
    //for (auto i : e.seperate_string(e.clean(ss))) std::cout << i << std::endl;
    
    std::cout << e.calculate(0.6) << std::endl;


    // 2 * ( sin ( 2 + cos ( 20^2 ) ) ) * ln( 2 )
    Equation e2("2+x-2*x+x^2");
    std::cout << e2.calculate(2) << std::endl;

    Equation e3("0.993");
    std::cout << e3.calculate(2) << std::endl;

    */

    Equation e4("e^(-x/4)*(2-x) -1");

    std::cout << e4.calculate(5) << std::endl;


 
    Equation e5("-3*(-2*-x) + (-x) - 2");

    std::cout << e5.calculate(2) << std::endl;

    Equation e6("x^2 +2*x +1");

    std::cout << e6.calculate(0) << std::endl;

    Equation e7 ("-(-(-(-(-(-x)+1)+2)+3)+4)");
    std::cout << e7.calculate(-10) << std::endl;
  

    Equation e8("(-x^8)");
    std::cout << e8.calculate(2) << std::endl;




    

}