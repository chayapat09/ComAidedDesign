#include <string>
#include <stack>
#include <unordered_map>
#include <math.h>
#include <vector>
#include <iostream>
#include <sstream>

#include "Operator_Operand.h"

namespace COMAID{

    class Equation{
        private:
            std::vector<Operator_Operand* > equation;
            size_t mSize;
            void push_back(std::string s,size_t idx){

            }

        public:
            Equation(){
                equation = std::vector<Operator_Operand* >();
                mSize = 0;
            }

            Equation(std::string s_eqn){
                // Clean string
                // Seperate string
                // Convert Seperated string to Opea_operand obj 
                //  push_back(string)
                //      - make new object
                // Fix * operator
                
            }

            static std::string clean(std::string &eqn){
                //Delete and change charecter to charecter that can be calculated
                std::string out;

                //Clean blank spaces 
                for (char i : eqn){
                    //if      (i == 'e' ) out += "2.71828"  ;
                    if (i != ' ' ) out.push_back(i)  ;
                }

                //Clean 

                return out;
            }

            static std::vector<std::string> seperate_string(std::string eqn){ // "2/sinh(s^2+(1))+cos(6)"
                eqn = " " + eqn + " ";
                std::string variable = "x"; //Only x are allowed for variable

                std::vector< std::pair< std::string,std::string > > ops ;
                    ops.push_back(std::make_pair("sinh(" ," sinh ( " ));
                    ops.push_back(std::make_pair("sin("  ," sin ( "   ));
                    ops.push_back(std::make_pair("cosh(" ," cosh ( "  ));
                    ops.push_back(std::make_pair("cos("  ," cos ( "   ));
                    ops.push_back(std::make_pair("("     ," ( "       ));
                    ops.push_back(std::make_pair(")"     ," ) "       ));
                    ops.push_back(std::make_pair("^"     ," ^ "       ));
                    ops.push_back(std::make_pair("+"     ," + "       ));
                    ops.push_back(std::make_pair("/"     ," / "       ));
                    ops.push_back(std::make_pair("*"     ," * "       ));
                    ops.push_back(std::make_pair(variable ," " + variable + " " ));

                // Seperate string by spaces " " ; Ex. "2cos(x)+5" -> " 2 cos ( x ) + 5 "
                for (auto i : ops){
                    size_t replace_idx = 0;
                    while ((replace_idx = eqn.find(i.first, replace_idx)) != std::string::npos) {
                        eqn.replace(replace_idx, i.first.length(), i.second);
                        replace_idx += i.second.length();
                    }
                    replace_idx = eqn.find(i.first);
                }
                
                // Append each splited by spaces(" ") string to Array (out) ; Ex. ["2" , "cos" , "(" , "x" , ")" , "+" , "5"]
                std::vector<std::string> out;
                std::stringstream eqn_stream(eqn);
                std::string tmp;
                while(eqn_stream >> tmp){
                    out.push_back(tmp);
                }

                return out;

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

            float calculate(std::vector<Operator_Operand *> &eqn){
                return calculated_postfix(infix2postfix(eqn)).value;
            }

    };

}