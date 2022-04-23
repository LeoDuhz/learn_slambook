#include <iostream>

using namespace std;

template<typename... T>
auto sum(T... t){
    return (t+...);
}

int main(){
    cout << sum(1,2,3,4,5) << endl;
}