#include <string>
#include <stack>
#include <unordered_map>
#include <math.h>
#include <vector>

#ifndef _CHAYAPAT_OPS_
#define _CHAYAPAT_OPS_
//! #pragma once
namespace COMAID{

    class Operator_Operand{
        public:
            bool isOperator;
            std::string str;
            int Required_operand;
            int outPriority;
            int inPriority;
            double value;

        Operator_Operand(){
            //Default Constructor
            this->isOperator = false;
            this->str = "";
            this->Required_operand = 0;
            this->outPriority = 0;
            this->inPriority = 0;
            this->value = double();

        }

        Operator_Operand(double value){
            //Operand Handle constructor
            this->isOperator = false;
            this->str = "";
            this->Required_operand = 0;
            this->outPriority = 0;
            this->inPriority = 0;
            this->value = value;
        }

        Operator_Operand(int value){
            this->isOperator = false;
            this->str = "";
            this->Required_operand = 0;
            this->outPriority = 0;
            this->inPriority = 0;
            this->value = (double) value;
        }
        Operator_Operand(std::string var){
            this->isOperator = false;
            this->str = var;
            this->Required_operand = 0;
            this->outPriority = 0;
            this->inPriority = 0;
            this->value = (double) value;
        }

        Operator_Operand virtual calculated(Operator_Operand a , Operator_Operand b){
            return 0;
        }

        Operator_Operand virtual calculated(Operator_Operand a){
            return 0;
        }
    };

    class plus : public Operator_Operand{
        public:
            plus(){
                this->isOperator = true;
                this->str = "+";
                this->Required_operand = 2;
                this->outPriority = 2;
                this->inPriority = 3;
                this->value = 0;
            }
            Operator_Operand calculated(Operator_Operand a , Operator_Operand b) override {
                return Operator_Operand(a.value+b.value);
            }
    };

    class minus : public Operator_Operand{
        public:
            minus(){
                this->isOperator = true;
                this->str = "-";
                this->Required_operand = 2;
                this->outPriority = 2;
                this->inPriority = 3;
                this->value = 0;
            }
            Operator_Operand calculated(Operator_Operand a , Operator_Operand b) override {
                return Operator_Operand(a.value-b.value);
            }
    };

    class multipy : public Operator_Operand{
        public:
            multipy(){
                this->isOperator = true;
                this->str = "*";
                this->Required_operand = 2;
                this->outPriority = 4;
                this->inPriority = 5;
                this->value = 0;
            }

            Operator_Operand calculated(Operator_Operand a , Operator_Operand b) override {
                return Operator_Operand(a.value*b.value);
            }
    };

    class devide : public Operator_Operand{
        public:
            devide(){
                this->isOperator = true;
                this->str = "/";
                this->Required_operand = 2;
                this->outPriority = 4;
                this->inPriority = 5;
                this->value = 0;
            }

            Operator_Operand calculated(Operator_Operand a , Operator_Operand b) override {
                return Operator_Operand(a.value/b.value);
            }
    };

    class power : public Operator_Operand{
        public:
            power(){
                this->isOperator = true;
                this->str = "^";
                this->Required_operand = 2;
                this->outPriority = 8;
                this->inPriority = 7;
                this->value = 0;
            }

            Operator_Operand calculated(Operator_Operand a , Operator_Operand b) override {
                return Operator_Operand(pow(a.value,b.value));
            }
    };

    class open_parentheses : public Operator_Operand{
        public:
            open_parentheses(){
                this->isOperator = true;
                this->str = "(";
                this->Required_operand = 0;
                this->outPriority = 9;
                this->inPriority = 0;
                this->value = 0;
            }
    };

    class close_parentheses : public Operator_Operand{
        public:
            close_parentheses(){
                this->isOperator = true;
                this->str = ")";
                this->Required_operand = 0;
                this->outPriority = 1;
                this->inPriority = 0;
                this->value = 0;
            }

    };

    class sin : public Operator_Operand{
        public:
            sin(){
                this->isOperator = true;
                this->str = "sin";
                this->Required_operand = 1;
                this->outPriority = 9;
                this->inPriority = 0;
                this->value = 0;
            }
            Operator_Operand calculated(Operator_Operand a ) override {
                return Operator_Operand( std::sin(a.value) );
            }
    };

    class cos : public Operator_Operand{
        public:
            cos(){
                this->isOperator = true;
                this->str = "cos";
                this->Required_operand = 1;
                this->outPriority = 9;
                this->inPriority = 0;
                this->value = 0;
            }
            Operator_Operand calculated(Operator_Operand a ) override {
                return Operator_Operand(std::cos(a.value));
            }
    };

    class tan : public Operator_Operand{
        public:
            tan(){
                this->isOperator = true;
                this->str = "tan";
                this->Required_operand = 1;
                this->outPriority = 9;
                this->inPriority = 0;
                this->value = 0;
            }
            Operator_Operand calculated(Operator_Operand a ) override {
                return Operator_Operand(std::tan(a.value));
            }
    };

    class sinh : public Operator_Operand{
        public:
            sinh(){
                this->isOperator = true;
                this->str = "sinh";
                this->Required_operand = 1;
                this->outPriority = 9;
                this->inPriority = 0;
                this->value = 0;
            }
            Operator_Operand calculated(Operator_Operand a ) override {
                return Operator_Operand(std::sinh(a.value));
            }
    };

    class cosh : public Operator_Operand{
        public:
            cosh(){
                this->isOperator = true;
                this->str = "cosh";
                this->Required_operand = 1;
                this->outPriority = 9;
                this->inPriority = 0;
                this->value = 0;
            }
            Operator_Operand calculated(Operator_Operand a ) override {
                return Operator_Operand(std::cosh(a.value));
            }
    };

    class tanh : public Operator_Operand{
        public:
            tanh(){
                this->isOperator = true;
                this->str = "tanh";
                this->Required_operand = 1;
                this->outPriority = 9;
                this->inPriority = 0;
                this->value = 0;
            }
            Operator_Operand calculated(Operator_Operand a ) override {
                return Operator_Operand(std::tanh(a.value));
            }

    };

    class ln : public Operator_Operand{
        public:
            ln(){
                this->isOperator = true;
                this->str = "ln";
                this->Required_operand = 1;
                this->outPriority = 9;
                this->inPriority = 0;
                this->value = 0;
            }
            Operator_Operand calculated(Operator_Operand a ) override {
                return Operator_Operand(std::log(a.value));
            }
    };

    class asin : public Operator_Operand{
        public:
            asin(){
                this->isOperator = true;
                this->str = "asin";
                this->Required_operand = 1;
                this->outPriority = 9;
                this->inPriority = 0;
                this->value = 0;
            }
            Operator_Operand calculated(Operator_Operand a ) override{
                return Operator_Operand(std::asin(a.value));
            }
    };

    class acos : public Operator_Operand{
        public:
            acos(){
                this->isOperator = true;
                this->str = "acos";
                this->Required_operand = 1;
                this->outPriority = 9;
                this->inPriority = 0;
                this->value = 0;
            }
            Operator_Operand calculated(Operator_Operand a ) override{
                return Operator_Operand(std::acos(a.value));
            }
    };

    class atan : public Operator_Operand{
        public:
            atan(){
                this->isOperator = true;
                this->str = "atan";
                this->Required_operand = 1;
                this->outPriority = 9;
                this->inPriority = 0;
                this->value = 0;
            }
            Operator_Operand calculated(Operator_Operand a ) override{
                return Operator_Operand(std::atan(a.value));
            }
    };


}
#endif