/*
---------This is Class file for Root finder Object------------
- This Object can store String of equations
- One Find_root Object per equation
- Calculate value from evaluating value in to string
  by replacing varlable to numeric value then process it
  by using Stack and post_fix numberic calculation
- Can find single root of equation by varies of numerical methods
- Logging calculated values
*/

//include require files
#include <string>
#include <stack>
#include <vector>
#include <exception>
#include <unordered_map>
#include <stdlib.h>

#include "Equation/Equation.h"

#ifndef _CHAYAPAT_ROOT_FIND_
#define _CHAYAPAT_ROOT_FIND_
//! #pragma_once
namespace COMAID{


    class Find_root{
        private: ;
            //Data members linked to Equation class
            Equation lhs;
            Equation rhs;
            float allowed_error;

            void insert(std::string &eqn){
                std::string l_eqn,r_eqn;
                int cnt = 0;// for counting =
                for (auto i : eqn){
                    if (i == '=') cnt++;
                    else {
                        if (cnt == 0){
                            l_eqn += i;
                        }
                        else{
                            r_eqn += i;
                        }
                    }
                }
                if (cnt != 1) throw "Please check for '=' in equation!";
                lhs.set_equation(l_eqn);
                rhs.set_equation(r_eqn);
            }


        public:
            Find_root(std::string eqn){
                // Default Constructor && Initialize values
                insert(eqn);
                allowed_error = 0.01; // Default error = 1%
            }

            Find_root(std::string eqn ,float error) {
                // Constructor with specified allowed_error
                insert(eqn);
                allowed_error = error;
            }

            void set_error(float err){
                allowed_error = err;
            }

            float calculate(float x){
                return lhs.calculate(x) - rhs.calculate(x);
            }

            // Numerical Method
            std::pair<bool,float> bi_section(float a , float b , int max_iterations = 20){
                //        This method calculate root from bi_section method 
                //and return values in form of {boolean,answer value} boolean true stands for
                //root is between a and b , false stands for root is outside [a,b]
                float f_left , f_right ,f_mid , x_mid , value_old , value_new , error = 1; // Set initial error to 100%
                int no_iterations = 0;
                f_left = calculate(a); f_right = calculate(b);
                if (f_left * f_right > 0) {
                    std::cout << "answer is not stays between a and b .Please select new initial conditions" << std::endl;
                    return std::make_pair(false,0);
                }
                while ( error > allowed_error && no_iterations < max_iterations){
                    x_mid = (a+b)/2;
                    f_mid = calculate(x_mid);
                    // Found exact solution
                    if (f_mid == 0 ) {
                        std::cout << "Iterations NO:" << no_iterations << " Found Exact Solution with x = " << x_mid << std::endl;
                        return std::make_pair(true,x_mid);
                    }
                    // CASE 1 f_mid && f_left are at same side
                    if (f_mid * f_left > 0){
                        value_old = a;
                        a = x_mid;
                        value_new = a;
                    }

                    // CASE 2 f_mid && f_right are at same side
                    else{
                        value_old = b;
                        b = x_mid;
                        value_new = b;
                    }
                    error = abs((value_new - value_old)/value_new);
                    no_iterations++;
                    std::cout << "Iterations NO:" << no_iterations << " X_new =  " << value_new << " Error: " <<  error * 100 << "%" << std::endl;
                    

                }

                return std::make_pair(true,value_new);

            }


    };
}



#endif