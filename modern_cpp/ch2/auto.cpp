#include <initializer_list>
#include <vector>
#include <iostream>

using namespace std;

//auto can even be used for parameter passing
int add(auto x, auto y){
    return x+y;
}


int main(){
    vector<int> v{1,2,3};
    //before C++11
    for(vector<int>::const_iterator it= v.cbegin(); it != v.cend(); ++it){
        cout << *it << endl;
    }

    //using auto
    for(auto it= v.begin(); it != v.end(); ++it){
        cout << *it << endl;
    }

    auto i = 5; //int
    auto arr = new auto(10); //int*
    cout << add(1,2) << endl;

    // auto arr2[10] = {arr}; //error, cannot be used to auto array type
    int arr2[10] = {*arr};
    

}