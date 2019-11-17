#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
/*

This function Handles multipy two Expresstion (2*'x1' - 3.3*'x2') * ( 7*'x2' + 3'x3' ) vector< pair <set of string,value> >
that store in terms of unordered_map : { { set('x1') , } , {} , {} , {}  }
*/


int main(){
    set<int> s1;
    set<int> s2;
    s1.insert(1);s1.insert(13);s1.insert(2);s1.insert(4);s1.insert(100);s1.insert(0);
    s2.insert(1);s2.insert(2);
    s1.erase(13); s1.erase(4); s1.erase(100); s1.erase(0); 
    s1.insert(20);

    if (s1 == s2) cout << "YES";
    else cout << "NO";

}