//初始化列表构造函数

#include <iostream>
#include <initializer_list>
#include <vector>

class foo{
public:
    std::vector<int> vec;
    foo(std::initializer_list<int> list){
        for(std::initializer_list<int>::iterator it = list.begin();
            it != list.end();
            ++it){
            vec.push_back(*it);
        }
    }
    void func(std::initializer_list<int> list){
        for(std::initializer_list<int>::iterator it = list.begin();
            it != list.end();
            ++it){
            vec.push_back(*it);
        }
    }
};

int main(){
    foo magicFoo = {1,2,3,4,5};
    std::cout << "magicFoo: " << std::endl;
    for(std::vector<int>::iterator it=magicFoo.vec.begin();it!=magicFoo.vec.end();++it){
        std::cout << *it << std::endl;
    }
    magicFoo.func({6,7,8,9,10});

    std::cout << "magicFoo: " << std::endl;
    for(std::vector<int>::iterator it=magicFoo.vec.begin();it!=magicFoo.vec.end();++it){
        std::cout << *it << std::endl;
    }

    foo magicFoo2 {22,33,44};
    std::cout << "magicFoo2: " << std::endl;
    for(std::vector<int>::iterator it=magicFoo2.vec.begin();it!=magicFoo2.vec.end();++it){
        std::cout << *it << std::endl;
    }
}