//变参模板展开 supported in C++17

#include <iostream>
#include <initializer_list>

using namespace std;

template<typename T0, typename... T>
void printf2(T0 t0, T... t){
    cout << t0 << endl;
    if constexpr (sizeof...(t) > 0){
        printf2(t...);
    }
}

template<typename... T>
void printf3(T... t){
    cout << "haha" << endl;
}

//remains to be figured out
template<typename T, typename... Ts>
void printf4(T value, Ts... args){
    cout << value << endl;
    (void) initializer_list<T>{([&args]{cout << args << endl;}(), value)...};
}

int main(){
    printf2(1,2,"str");
    printf3();
    printf4(1,2,"str");
}   