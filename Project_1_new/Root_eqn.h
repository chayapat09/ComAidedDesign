/*
---------This is Class file for Root finder Object------------
- This Object can store String of equations
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

#ifndef _CHAYAPAT_ROOT_FIND_
#define _CHAYAPAT_ROOT_FIND_
//! #pragma_once

class Find_root{
    private:
        // Private Data members
        std::string equation;
        float allowed_error;
        std::vector<float> calculated_values;
        std::vector<std::string> calculated_methods;
        std::vector<float> calculated_error; // 0.1 0.05 ...
        std::vector<size_t> no_iterations;
        size_t log_size;

    public:
        Find_root(std::string eqn){
            // Default Constructor && Initialize values
            equation = eqn;
            allowed_error = 0.01; //Default maximum error = 1%
            calculated_values = std::vector<float>();
            calculated_methods = std::vector<std::string>();
            calculated_error = std::vector<float>();
            no_iterations = std::vector<size_t>();
            log_size = 0;
        }

        Find_root(std::string eqn ,float error) {
            // Constructor with specified allowed_error
            allowed_error = error;
        }

        void change_error(float err){
            allowed_error = err;
        }

        void show_log(){
            
        }


};



#endif