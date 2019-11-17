#include <set>
#include <vector>
#include <string>
#include <map>
#ifndef _EXPRESSION_CHAYAPAT_
#define _EXPRESSION_CHAYAPAT_
//!Pragma once
template <typename T>
class Expression{
/*
    Data structure for Expression that store with Vector and Pair
    Abstract for this data structure is to compare two set of symbolic vairables
    that are equal or not this data structure also store multiple values of 
    set of symbolic vairables pair with its float constant using Vector
    This kind of data structure can be faster using N^N Arrays N = number of All vairbles in expression
    or hashing of avalible sorted(vairables) but it much more complex and use more time to implemented
*/  
    template <typename X> class Variable{
        private:
            std::map<X,int> Data;
            size_t var_size;

        public:

            Variable() {
                Data = std::map<X,int>();
                var_size = 0;
            }

            Variable(std::vector<X> var){
                for (auto i:var){
                    Data[i] += val;
                }
            }



    };

    private:
        int mSize;
        std::vector< Variable<T> > mData; 
        // std::set<T> unique_keys; // If used


        int find_index(Expression exp){
            
        }

        void convert(std::string s_express){ // Recieve single expression string

        }
    public:
    //Constructor
        Expression(){
            mSize = 0;
            mData = std::vector< std::pair<std::vector<T> ,float > > ();
        }
        Expression( Expression & other){
            mData = other.mData;
            mSize = other.mSize;
        }

    //Modifier
    void insert(std::string s_express){
        
    }
    void add(Expression &other){

    }

    void minus(Expression &other){

    }
    void multipy(const Expression &other){

    }


};

#endif //End class Expression




/*
    (2x+3)(3x+y) + 2y^2 + z*z = 6
    2(x+y) + 4(x+z) = 6 -> 6x + 2y + 4z = 6



*/