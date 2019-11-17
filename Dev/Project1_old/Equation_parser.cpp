#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <string>
using namespace std;

vector< pair<int,int> > find_pairs_of_parentheses(string s_eqn){
    stack< pair<int,int> > parentheses_chk; // Stack that collect type of bracket '('-> 0 or ')' -> 1
    vector< pair<int,int> > parentheses_idx; // Vector that store pair of idx's {open_idx,end_idx}
    for (int i = 0 ; i < s_eqn.size() ; i++ ){
        if (s_eqn[i] == '('){
            parentheses_chk.push( make_pair(0,i) );
        }
        else if (s_eqn[i] == ')'){
            if (parentheses_chk.empty()) {
                throw "Close parentheses are more than Open ones!";
            }
            if (parentheses_chk.top().first == 0){
                parentheses_idx.push_back( make_pair(parentheses_chk.top().second , i) ); // push_back {open_idx,end_idx}
                parentheses_chk.pop();
            }
            else {
                throw "Incorrected parentheses pair!";
            }
        }
    }
    if (!parentheses_chk.empty()){
        throw "Open parentheses are more than Close ones!";
    }
    sort(parentheses_idx.begin(),parentheses_idx.end());
    return parentheses_idx;

}
int main(){
    try{
        auto x = find_pairs_of_parentheses("()()()()((())) ");
        for (auto i : x ){
            cout << i.first << " " << i.second << endl;
        }
    }
    catch (const char* msg) {
        cout << msg << endl;
    }

}

