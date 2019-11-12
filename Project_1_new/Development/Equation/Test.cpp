#include <iostream>
#include <vector>
#include "Equation.h"
#include <string>
#include <sstream>

using namespace COMAID;

int main(){
    std::string s = "2 * ( Sin ( 2 + cos ( 20 ^ 2 + x )    ) ) * ln ( x )   ";// { "2" , "*" ,"(" }
    std::string ss("2*Sin(sinH(cosh(cosh(cos(2*x*x^x^cosh(32.33))))))");
    Equation e(s);
    for (auto i : e.seperate_string(e.clean(ss))) std::cout << i << std::endl;
    
    std::cout << e.calculate(2) << std::endl;


    // 2 * ( sin ( 2 + cos ( 20^2 ) ) ) * ln( 2 )
 

    

}