#include <string>
#include <stack>
#include <unordered_map>
#include <math.h>
#include <vector>
#include <iostream>
#include <sstream>

#include "Operator_Operand.h"


#ifndef _CHAYAPAT_EQUATION_
#define _CHAYAPAT_EQUATION_
//! #pragma once
namespace COMAID{

    class Equation{
        private:
            std::vector<Operator_Operand* > equation;
            std::vector<std::string> functions;

            void to_equation(std::vector<std::string> eqn){
                for(auto ops : eqn){
                    double e = 2.71828;
                    double pi = 3.14159;
                    Operator_Operand * tmp;
                    if      (ops == "asin") tmp = new asin();
                    else if (ops == "sinh") tmp = new sinh();
                    else if (ops == "sin" ) tmp = new sin();
                    else if (ops == "acos") tmp = new acos();
                    else if (ops == "cosh") tmp = new cosh();
                    else if (ops == "cos" ) tmp = new cos();
                    else if (ops == "atan") tmp = new atan();
                    else if (ops == "tanh") tmp = new tanh();
                    else if (ops == "tan" ) tmp = new tan();
                    else if (ops == "ln"  ) tmp = new ln();
                    else if (ops == "("   ) tmp = new open_parentheses();
                    else if (ops == ")"   ) tmp = new close_parentheses();
                    else if (ops == "+"   ) tmp = new plus();
                    else if (ops == "*"   ) tmp = new multipy();
                    else if (ops == "/"   ) tmp = new devide();
                    else if (ops == "-"   ) tmp = new minus();
                    else if (ops == "^"   ) tmp = new power();
                    else if (ops == "x"   ) tmp = new Operator_Operand("x"); // Varible fix to "x"
                    //else if (ops == "-x"  ) tmp = new Operator_Operand("-x");
                    else if (ops == "e"   ) tmp = new Operator_Operand(e);
                    else if (ops == "pi"  ) tmp = new Operator_Operand(pi);
                    else {
                        std::string errmsg = "Error:'" + ops + "' is not a valid variable";
                        if (!is_digit(ops)) throw errmsg;
                        tmp = new Operator_Operand( std::stod(ops) );
                    }

                    equation.push_back(tmp);
                }
            }
            

        public:
            Equation(){
                equation = std::vector<Operator_Operand* >();
                // Initialize function name that we can use
                functions.push_back("asin");
                functions.push_back("sinh");
                functions.push_back("sin" );
                functions.push_back("acos");
                functions.push_back("cosh");
                functions.push_back("cos" );
                functions.push_back("atan");
                functions.push_back("tanh");
                functions.push_back("tan" );
                functions.push_back("ln"  );

            }

            Equation(std::string s_eqn){
                // Initialize function name that we can use
                functions.push_back("asin");
                functions.push_back("sinh");
                functions.push_back("sin" );
                functions.push_back("acos");
                functions.push_back("cosh");
                functions.push_back("cos" );
                functions.push_back("atan");
                functions.push_back("tanh");
                functions.push_back("tan" );
                functions.push_back("ln"  );
                
                set_equation(s_eqn);
            }
            void set_equation(std::string eqn){
                // Clear old equations
                // Clean string
                // Seperate string
                //   - Fix negative case
                //   - Fix 2(3) , 2 sin(x) , (x)(y) , ()2
                // Convert Seperated string to Opea_operand obj 
                //  push_back(string)
                //      - make new object
                // Fix * operator
                

                clear();
                eqn = clean(eqn);
                std::vector<std::string> eqn_s = seperate_string(eqn);
                to_equation(eqn_s);

            }

            static std::string clean(std::string &eqn){
                //Delete and change charecter to charecter that can be calculated
                std::string out;

                for (char i : eqn){
                    if (i == ' ' ) continue  ; //Clean blank spaces 
                    else if ('A' <= i && i <= 'Z' ) out.push_back( 'a' + (i - 'A') ); //Change Upper cases to lower cases
                    else out.push_back(i);
                }

                return out;
            }

            std::vector<std::string> seperate_string(std::string eqn){ // Ex. eqn = "2/sinh(x^2+(1))+cos(6)" -> ["2" ,"/" ,"sinh" ,"(" ,"x" ,"^ " , ... ]
                // STATIC FUNCTION NEED TO CHANGE function to static 
                eqn = " " + eqn + " ";
                std::string variable = "x"; //Only x are allowed for variable

                std::vector< std::pair< std::string,std::string > > ops ; // All operators need to be replace
                    for (auto i : functions){
                        ops.push_back(std::make_pair( i + "(" , " " + i + " ( " ) );
                    }
                    ops.push_back(std::make_pair("("     ," ( "       ));
                    ops.push_back(std::make_pair(")"     ," ) "       ));
                    ops.push_back(std::make_pair("+"     ," + "       ));
                    ops.push_back(std::make_pair("-"     ," - "       ));
                    ops.push_back(std::make_pair("*"     ," * "       ));
                    ops.push_back(std::make_pair("/"     ," / "       ));
                    ops.push_back(std::make_pair("^"     ," ^ "       ));
                    //ops.push_back(std::make_pair(variable ," " + variable + " " ));

                // Seperate string by spaces " " ; Ex. "2cos(x)+5" -> " 2 cos ( x ) + 5 "
                for (auto i : ops){
                    replace_string(eqn,i.first,i.second);
                }
                
                // Append each splited by spaces(" ") string to Array (out) ; Ex. " 2 cos ( x ) + 5 " -> ["2" , "cos" , "(" , "x" , ")" , "+" , "5"]
                std::vector<std::string> out;
                std::stringstream eqn_stream(eqn);
                std::string tmp;
                while(eqn_stream >> tmp){
                    out.push_back(tmp);
                }

                // Handle negative number cases
                // Check for cases [ "-" , "-x" , "-2" , "x-2" , "2-x" , () - 1 -> ")"  , "-1"]
                // -(x+y) -> "-" "(" .. , 4*-2 -> "4" "*" "-2" , 2*(-x+3) -> "2" "*" "(" "-x" / "-2" "+"
                // 1-x > "1-x" ( ")" "-1" 
                // -(...) + ..  , ( -(..) + 3) , -sin(x) + 3

                std::vector<std::string> out_fix_neg;
                for (int i = 0 ; i < out.size() ; i++){
                    if (out[i] == "-"){
                        // negative operator

                        // CASE 1 - ( x + y ) First in Expression -> -1 * ( x + y )
                        if (i == 0){
                            out_fix_neg.push_back("-1");
                            out_fix_neg.push_back("*");
                        }

                        // CASE 2   3 * - x    ->   3 * -1 * x
                        else if (out[i-1] == "+" || out[i-1] == "-" || out[i-1] == "*" || out[i-1] == "/" || out[i-1] == "^" ){
                            out_fix_neg.push_back("-1");
                            out_fix_neg.push_back("*");   
                        }

                        // CASE 3   2 * ( - x + y ) ->  2 * ( -1 * x + y )
                        else if (is_function(out[i-1]) ) {
                            out_fix_neg.push_back("-1");
                            out_fix_neg.push_back("*");                            
                        }

                        // minus operator
                        else{
                            out_fix_neg.push_back(out[i]);
                        }
                    }

                    else{
                        out_fix_neg.push_back(out[i]);
                    }

                }

                //Fix multiply operator
                std::vector<std::string> out_fix_mul;
                for (int i = 0 ; i < out_fix_neg.size() ; i++){
                    //CASE 1 digit()
                    if (i != 0 && is_digit(out_fix_neg[i-1]) && out_fix_neg[i-1] != "-" && is_function(out_fix_neg[i]) ){
                        out_fix_mul.push_back("*");
                        out_fix_mul.push_back(out_fix_neg[i]);
                    }

                    //CASE 2 ()()
                    else if (i != 0 && out_fix_neg[i-1] == ")" && is_function( out_fix_neg[i] )){
                        out_fix_mul.push_back("*");
                        out_fix_mul.push_back(out_fix_neg[i]);
                    }

                    //CASE 3 ()digit
                    else if (i != 0 && out_fix_neg[i-1] == ")" && is_digit(out_fix_neg[i]) && out_fix_neg[i] != "-"){
                        out_fix_mul.push_back("*");
                        out_fix_mul.push_back(out_fix_neg[i]);
                    }

                    //CASE 4 '2.332x'
                    /*
                    else if (int pos = out_fix_neg[i].find('x') != std::string::npos && out_fix_neg[i].length() != 1){
                        out_fix_mul.push_back(out_fix_neg[i].substr(0,pos)) ;
                        out_fix_mul.push_back("*");
                        out_fix_mul.push_back(out_fix_neg[i].substr(pos)) ; 
                    }
                    */

                    else if ( *(out_fix_neg[i].end()-1) == 'x' && is_digit(out_fix_neg[i].substr(0,out_fix_neg[i].length()-1) ) ){
                        out_fix_mul.push_back( out_fix_neg[i].substr(0,out_fix_neg[i].length()-1) );
                        out_fix_mul.push_back("*");
                        out_fix_mul.push_back("x");
                    }

                    else{
                        out_fix_mul.push_back(out_fix_neg[i]);
                    }
                }
                return out_fix_mul;

            }

            static void replace_string(std::string & eqn , std::string s_old , std::string s_new ){
                size_t replace_idx = 0;
                while ((replace_idx = eqn.find(s_old, replace_idx)) != std::string::npos) {
                    eqn.replace(replace_idx, s_old.length(), s_new);
                    replace_idx += s_new.length();
                    }
            }

            
            static bool is_digit(std::string  number){
                if (number.length() == 0 ) return false;
                for (auto i :number){
                    if ( !( ( '0' <= i && i <= '9') || (i == '.')  || (i == '-') || (i == 'x'))) return false;
                }
                return true;

            }
            

            bool is_function(std::string & func){
                // STATIC FUNCTION NEED TO CHANGE function to static 
                for (auto i : functions){
                    if (func == i || func == "(") return true;
                }
                return false;
            }

            std::vector<Operator_Operand *> infix2postfix(std::vector<Operator_Operand *> &infix){ // Don't change value of Operator_operand Object
                int n = infix.size();
                std::vector<Operator_Operand *> postfix;
                std::stack<Operator_Operand *> s;

                for (int i=0 ; i < n ; i++ ) {
                    Operator_Operand * token_ptr = infix[i];
                    if (! (token_ptr->isOperator)) {
                        postfix.push_back(token_ptr);
                    }
                    else {
                        int p = token_ptr->outPriority;
                        while( !s.empty() && s.top()->inPriority >= p ) {
                            postfix.push_back(s.top()); s.pop();
                        }
                        if (token_ptr->str == ")") {
                            s.pop(); 
                            if (!s.empty() && s.top()->Required_operand == 1){
                                postfix.push_back(s.top()); s.pop();
                            }
                        }
                        else s.push(token_ptr);
                    }
                }
                while(!s.empty()) { postfix.push_back(s.top()); s.pop();}
                
                return postfix; // Make sure to delete all infix object that can cause MemoryLeak
            }


            Operator_Operand calculated_postfix(std::vector<Operator_Operand *> postfix){
                std::stack<Operator_Operand *> s;
                std::vector<Operator_Operand *> tmp_created_object;
                for (int i = 0 ; i < postfix.size() ; i++){
                    if ( !(postfix[i]->isOperator) ) s.push(postfix[i]);
                    else {
                        Operator_Operand tmp;
                        if (postfix[i]->Required_operand == 1){
                            Operator_Operand * a = s.top(); s.pop();
                            tmp = postfix[i]->calculated(*a);
                            
                        }
                        else if (postfix[i]->Required_operand == 2){
                            Operator_Operand * b = s.top(); s.pop();
                            Operator_Operand * a = s.top(); s.pop();
                            tmp = postfix[i]->calculated(*a,*b);
                        }
                        Operator_Operand * new_obj_ptr = new Operator_Operand(tmp.value);
                        tmp_created_object.push_back(new_obj_ptr);
                        s.push(new_obj_ptr);
                    }
                }
                //Delete tmp
                Operator_Operand out = *s.top();
                for (auto i:tmp_created_object){
                    delete i;
                }
                return out;

            }

            double calculate(double x){
                if (equation.empty()) return 0;
                std::vector<Operator_Operand *> tmp_new_x;
                std::vector<Operator_Operand *> to_calculate_eqn;
                for (auto i : equation){
                    if (i->str == "x"){
                        Operator_Operand * substituded_x = new Operator_Operand(x);
                        tmp_new_x.push_back(substituded_x);
                        to_calculate_eqn.push_back(substituded_x);
                    }
                    /*
                    else if (i->str == "-x"){
                        Operator_Operand * substituded_x = new Operator_Operand(-x);
                        tmp_new_x.push_back(substituded_x);
                        to_calculate_eqn.push_back(substituded_x);                       
                    }
                    */
                    else{
                        to_calculate_eqn.push_back(i);
                    }
                }

                double ans = calculated_postfix(infix2postfix(to_calculate_eqn)).value;
                //to_calculate_eqn.clear();
                for (auto i : tmp_new_x) delete i; // Delete new create objects
                return ans;
            }

        std::vector<std::string> get_equation_string(){
            std::vector<std::string> out;
            for (auto i:equation){
                if (i->isOperator || i->str == "x" || i->str =="-x") out.push_back(i->str);
                else out.push_back(std::to_string(i->value));
            }
            return out;
        }


            void clear(){
                for (auto i: equation){
                    delete i;
                }
                equation.clear();
            }

            ~Equation(){
                clear();
            }


            

    };

}
#endif