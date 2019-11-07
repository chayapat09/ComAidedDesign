/*
---------This is Class file for Logging Object------------
- This Object can store Log of Root_eqn class
- This Class implemented for make sure that Logging Data are doing 
  Correctly
- Log are store in side this class one Log per One Logging Object
*/
#include <string>

#ifndef _CHAYAPAT_LOGGING_
#define _CHAYAPAT_LOGGING_
//! #pragma_once
class Logging{

    private:
        float calculated_values;
        std::string calculated_methods;
        float calculated_error;
        size_t no_iterations;

    public:
        void show_log(){
            // Show log print string
        } 

        float get_log_value(){
            return calculated_values;
        }

        std::string get_calculated_method(){
            return calculated_methods;
        }

        
};




#endif