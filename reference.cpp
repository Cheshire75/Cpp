#include <iostream>

int change_val(int &p){
    //p를 참조자로 입력받아 값을 3으로 변경한다.
    p=3; // number = 3
    return 0;
}

int main(){
    int number = 5;
    std::cout << number << std::endl;
    //5를 출력

    change_val(number);
    //참조자를 이용해 number의 주소값을 전달

    std::cout << number << std::endl;
    //number의 값이 3으로 변경

    return 0;
}