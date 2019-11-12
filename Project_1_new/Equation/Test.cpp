#include <iostream>
#include <vector>
#include "Equation.h"
#include <string>
#include <sstream>

using namespace COMAID;

int main(){
    Equation e;
    std::string s = "2 * ( sin ( 2 + cos ( 20 ^ 2 + e )    ) ) * ln ( 2 )   ";// { "2" , "*" ,"(" }
    std::cout << e.clean(s) << std::endl;
    std::string ss("2sin(sinh(cosh(cosh(cos(2^x^x^x^cosh(32.33))))))");
    for (auto i : e.seperate_string(ss)){
        std::cout << i << std::endl;
    }

    

}