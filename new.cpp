#include <iostream>

int main(){
    int* p = new int;
    //new를 이용해 동적할당된 p
    *p = 10;

    std::cout << *p << std::endl;

    delete p;

    int arr_size;
    std::cout << "array size: ";
    std::cin >> arr_size;
    //동적할당할 배열의 크기를 입력받아 저장한다.

    int *arr = new int[arr_size];
    for (int i = 0; i < arr_size; i++){
        std::cin >> arr[i];
    }
    //할당한 배열에 숫자를 입력받아 저장한다.

    for (int i = 0; i < arr_size; i++){
        std::cout << "array[" << i << "]: " << arr[i] << std::endl;
    }
    //배열을 순서대로 출력한다.

    delete[] arr;
    //프로그램을 종료하기 전 동적할당한 배열을 해제한다.
    
    return 0;
}