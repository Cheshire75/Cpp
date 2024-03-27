#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::ifstream in("test.txt");
    std::string s;
    // 파일스트림을 in에 할당하고 파일 내용을 저장할 s를 선언

    if (in.is_open())
    // in에 파일스트림이 성공적으로 생성되었을 경우
    {
        std::getline(in, s);
        // in에서 불러온 파일 내부의 텍스트를 s에 저장
        std::cout << "intered string: " << s << std::endl;
    }
    else
    // in에 파일스트림을 생성하는데 실패했을 경우
    {
        std::cout << "no file!" << std::endl;
    }
    return 0;
}