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
            double allowed_error;

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
                if (cnt != 1) throw "Please check for '=' in equation!\n";
                lhs.set_equation(l_eqn);
                rhs.set_equation(r_eqn);
            }


        public:
            Find_root(std::string eqn){
                // Default Constructor && Initialize values
                insert(eqn);
                allowed_error = 0; // Default error = 0%
            }

            Find_root(std::string eqn ,double error) {
                // Constructor with specified allowed_error
                insert(eqn);
                allowed_error = error;
            }

            void set_error(double err){
                allowed_error = err;
            }

            double calculate(double x){
                return lhs.calculate(x) - rhs.calculate(x);
            }

            // Numerical Method
            std::pair<bool,double> bi_section(double a , double b , int max_iterations = 20, bool display = false){
                //        This method calculate root from bi_section method 
                //and return values in form of {boolean,answer value} boolean true stands for
                //root is between a and b , false stands for root is outside [a,b]
                double f_left , f_right ,f_mid , x_mid , value_old , value_new , error = 1; // Set initial error to 100%
                int no_iterations = 0;
                f_left = calculate(a); f_right = calculate(b);
                std::cout << f_left << " " << f_right << std::endl;
                if (f_left * f_right > 0) {
                    if (display) std::cout << "answer is not stays between 'a' and 'b' or difference between 'a' and 'b' is too large .Please select new initial conditions" << std::endl;
                    
                    return std::make_pair(false,0);
                }
                while ( error > allowed_error && no_iterations < max_iterations){
                    x_mid = (a+b)/2;
                    f_mid = calculate(x_mid);
                    // Found exact solution
                    if (f_mid == 0 ) {
                        if (display)
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
                    if (display)
                        std::cout << "Iterations NO:" << no_iterations << " X_new =  " << value_new << " Error: " <<  error * 100 << "%" << std::endl;
                    

                }

                return std::make_pair(true,value_new);

            }

            std::pair<bool,double> false_position(double a , double b , int max_iterations = 20, bool display = false){
                //        This method calculate root from false_position method 
                //and return values in form of {boolean,answer value} boolean true stands for
                //root is between a and b , false stands for root is outside [a,b]
                double f_left , f_right ,f_new , x_new , value_old , value_new , error = 1; // Set initial error to 100%
                int no_iterations = 0;
                f_left = calculate(a); f_right = calculate(b);
                //std::cout << f_left << " " << f_right << std::endl;
                if (f_left * f_right > 0) {
                    if (display)
                        std::cout << "answer is not stays between a and b. Please select new initial conditions" << std::endl;
                    
                    return std::make_pair(false,0);
                }
                while ( error > allowed_error && no_iterations < max_iterations){
                    x_new = (a*f_right-b*f_left)/(f_right-f_left);
                    f_new = calculate(x_new);
                    // Found exact solution
                    if (f_new == 0 ) {
                        if (display)
                            std::cout << "Iterations NO:" << no_iterations << " Found Exact Solution with x = " << x_new << std::endl;
                        return std::make_pair(true,x_new);
                    }
                    // CASE 1 f_new && f_left are at same side
                    if (f_new * f_left > 0){
                        value_old = a;
                        a = x_new;
                        f_left = f_new;
                        value_new = a;
                    }

                    // CASE 2 f_new && f_right are at same side
                    else{
                        value_old = b;
                        b = x_new;
                        f_right = f_new;
                        value_new = b;
                    }
                    error = abs((value_new - value_old)/value_new);
                    no_iterations++;
                    if (display)
                        std::cout << "Iterations NO:" << no_iterations << " X_new =  " << value_new << " Error: " <<  error * 100 << "%" << std::endl;
                    

                }

                return std::make_pair(true,value_new);

            }


            std::pair<bool,double> one_point_iteration(double a , int max_iterations = 20 , bool display = false){ // Need to constrain user to type in form x = ... 
                std::vector<std::string> str_lhs = lhs.get_equation_string();
                //std::vector<std::string> str_rhs = rhs.get_equation_string();
                if (! (str_lhs.size() == 1 && (str_lhs[0] == "x" ) ) ){
                    throw "Please Rearrange Equation in form of x = ... to solve in one point iteration method\n" ;
                }
                int no_iterations = 1;
                double last_value = a, new_value,error = 1;// Set initial error to 100%;
                while (error > allowed_error && no_iterations < max_iterations){
                    new_value = rhs.calculate(last_value);
                    error = abs((new_value - last_value)/new_value);
                    last_value = new_value;
                    std::cout << "Iterations NO:" << no_iterations << " X_new =  " << new_value << " Error: " <<  error * 100 << "%" << std::endl;
                    no_iterations++;
                }
                
            }

    };
}



#endif