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
#include "Logging.h"

#ifndef _CHAYAPAT_ROOT_FIND_
#define _CHAYAPAT_ROOT_FIND_
//! #pragma_once

class Find_root{
    private: ;
        // Private Data members
        std::string equation;
        float allowed_error;
        std::vector<Logging> logs;
        size_t log_size;

    public:
        Find_root(std::string eqn){
            // Default Constructor && Initialize values
            equation = eqn;// Clean string?
            allowed_error = 0.01; //Default maximum error = 1%
            log_size = 0;
        }

        Find_root(std::string eqn ,float error) {
            // Constructor with specified allowed_error
            allowed_error = error;
        }

        void change_error(float err){
            allowed_error = err;
        }


        // Numerical Method
        std::pair<bool,float> bi_section(float a , float b){
            //This method calculate root from bi_section method then logging answers
            //and return values in form of {boolean,answer value} boolean true stands
            //for convergece and false means divergence
            float mid,value_old,value_new,error = 1; // Set initial error to 100%
            while ( error > allowed_error ){
                mid = (a+b)/2;

            }

        }



        // Logging

        void show_log(){

        }
};



#endif