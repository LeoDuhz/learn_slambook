//Remember:模板是用来产生类型的

#include <iostream>
#include <vector>
#include <map>

using namespace std;

template<typename... Ts>class Magic{};

template<typename... Args> void printf(const string &str, Args... args);

template<typename... Args> void magic(Args... args){
    cout << sizeof...(args) << endl;
}

int main(){
    class Magic<> nothing;
    class Magic<int, double, map<int, vector<int>>> darkMagic;

    magic();
    magic(1.0);
    magic("str",2);

    
}