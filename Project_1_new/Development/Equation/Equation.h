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
namespace COMAID{

    class Equation{
        private:
            std::vector<Operator_Operand* > equation;
            //size_t mSize;

            void to_equation(std::vector<std::string> eqn){
                for(auto ops : eqn){
                    Operator_Operand * tmp;
                    if      (ops == "sinh") tmp = new sinh();
                    else if (ops == "sin" ) tmp = new sin();
                    else if (ops == "cosh") tmp = new cosh();
                    else if (ops == "cos" ) tmp = new cos();
                    else if (ops == "tanh") tmp = new tanh();
                    else if (ops == "tan" ) tmp = new tan();
                    else if (ops == "ln"  ) tmp = new ln();
                    else if (ops == "("   ) tmp = new open_parentheses();
                    else if (ops == ")"   ) tmp = new close_parentheses();
                    else if (ops == "+"   ) tmp = new plus();
                    else if (ops == "-"   ) tmp = new minus();
                    else if (ops == "*"   ) tmp = new multipy();
                    else if (ops == "/"   ) tmp = new devide();
                    else if (ops == "^"   ) tmp = new power();
                    else if (ops == "x"   ) tmp = new Operator_Operand("x"); // Varible fix to "x"
                    else {
                        // Check double dot operator errors here "1.22.33" "xsine" ...
                        tmp = new Operator_Operand( std::stof(ops) );
                    }

                    equation.push_back(tmp);
                }
            }

        public:
            Equation(){
                equation = std::vector<Operator_Operand* >();
                //mSize = 0;
            }

            Equation(std::string s_eqn){
                set_equation(s_eqn);
            }
            void set_equation(std::string eqn){
                // Clear old equations
                // Clean string
                // Seperate string
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
                    //if      (i == 'e' ) out += "2.71828"  ;
                    if (i == ' ' ) continue  ; //Clean blank spaces 
                    else if ('A' <= i && i <= 'Z' ) out.push_back( 'a' + (i - 'A') ); //Change Upper cases to lower cases
                    else out.push_back(i);
                }

                //Clean Upper case letters

                return out;
            }

            static std::vector<std::string> seperate_string(std::string eqn){ // Ex. eqn = "2/sinh(x^2+(1))+cos(6)" -> ["2" ,"/" ,"sinh" ,"(" ,"x" ,"^ " , ... ]
                eqn = " " + eqn + " ";
                std::string variable = "x"; //Only x are allowed for variable

                std::vector< std::pair< std::string,std::string > > ops ; // All operators need to be replace
                    ops.push_back(std::make_pair("sinh(" ," sinh ( "  ));
                    ops.push_back(std::make_pair("sin("  ," sin ( "   ));
                    ops.push_back(std::make_pair("cosh(" ," cosh ( "  ));
                    ops.push_back(std::make_pair("cos("  ," cos ( "   ));
                    ops.push_back(std::make_pair("tanh(" ," tanh ( "  ));
                    ops.push_back(std::make_pair("tan("  ," tan ( "   ));
                    ops.push_back(std::make_pair("ln("   ," ln ( "    ));
                    ops.push_back(std::make_pair("("     ," ( "       ));
                    ops.push_back(std::make_pair(")"     ," ) "       ));
                    ops.push_back(std::make_pair("+"     ," + "       ));
                    ops.push_back(std::make_pair("-"     ," - "       ));
                    ops.push_back(std::make_pair("*"     ," * "       ));
                    ops.push_back(std::make_pair("/"     ," / "       ));
                    ops.push_back(std::make_pair("^"     ," ^ "       ));
                    ops.push_back(std::make_pair(variable ," " + variable + " " ));

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

                return out;

            }

            static void replace_string(std::string & eqn , std::string s_old , std::string s_new ){
                size_t replace_idx = 0;
                while ((replace_idx = eqn.find(s_old, replace_idx)) != std::string::npos) {
                    eqn.replace(replace_idx, s_old.length(), s_new);
                    replace_idx += s_new.length();
                    }
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

            float calculate(float x){
                if (equation.empty()) return 0;
                std::vector<Operator_Operand *> tmp_new_x;
                std::vector<Operator_Operand *> to_calculate_eqn;
                for (auto i : equation){
                    if (i->str == "x"){
                        Operator_Operand * substituded_x = new Operator_Operand(x);
                        tmp_new_x.push_back(substituded_x);
                        to_calculate_eqn.push_back(substituded_x);
                    }
                    else{
                        to_calculate_eqn.push_back(i);
                    }
                }

                float ans = calculated_postfix(infix2postfix(to_calculate_eqn)).value;
                //to_calculate_eqn.clear();
                for (auto i : tmp_new_x) delete i; // Delete new create objects
                return ans;
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