//decltype designed for the reason that auto can only used for variable infering

#include <iostream>

using namespace std;

int main(){
    auto x = 1;
    auto y = 2;
    decltype(x+y) z;

    if(std::is_same<decltype(x), int>::value){
        cout << "type of x is int." << endl;
    }
    if(std::is_same<decltype(x),decltype(z)>::value){
        cout << "type of x equals to type of z." << endl;
    }
}