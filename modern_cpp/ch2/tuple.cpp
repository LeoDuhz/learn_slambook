#include <iostream>
#include <tuple>

std::tuple<int,double,std::string> f(){
    return std::make_tuple(1,2.3,"hahaha");
}

int main(){
    auto [x,y,z] = f();
    std::cout << x << " " << y << " " << z << std::endl;
}