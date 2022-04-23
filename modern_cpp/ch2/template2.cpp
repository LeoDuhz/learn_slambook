//递归模板函数 

#include <iostream>

using namespace std;

template<typename T0>
void printf1(T0 value){
    cout << value << endl;
    cout << "hello" << endl;
}

template<typename T1, typename... Ts>
void printf1(T1 value, Ts... args){
    cout << value << endl;
    printf1(args...);
}

int main(){
    printf1(1,2,"123",1.1);
    printf1(0);
    return 0;
}
