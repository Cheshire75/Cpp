#include <iostream>

void print(int x){
    //인자의 자료형이 int형인 경우
    std::cout << "int   : " << x << std::endl;
}

void print(char x){
    //인자의 자료형이 char형인 경우
    std::cout << "char  : " << x << std::endl;
}

int main(){
    int a = 1;
    char b = 'k';

    print(a);
    print(b);
    //동일한 이름의 함수가 호출되었지만 전달하는 인자의 자료형에 따라
    //실행되는 함수가 달라진다.

    return 0;
}