#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*

This function Handles multipy two Expresstion (2*'x1' - 3.3*'x2') * ( 7*'x2' + 3'x3' ) vector< pair <set of string,value> >
that store in terms of unordered_map : { { set('x1') , } , {} , {} , {}  }
*/

unordered_map<string,float> multipy_two_expression(unordered_map<string,float> left, unordered_map<string,float> right ){
    unordered_map<string,float> merged_expression;
    for (auto itr_left = left.begin() ; itr_left != left.end() ; ++itr_left){
        for (auto itr_right = right.begin() ; itr_right != right.end() ; ++itr_right){

        }
    }
}
int main(){

}