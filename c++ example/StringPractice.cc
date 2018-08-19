#include <iostream>
using namespace std;

int main()
{
    string myString;
    myString = "hello world!";
    

    cout << myString.capacity() << endl;
}

/*
값을 비교할 때 == 연산자를 이용해서 동일 여부를 알아낸다. 
문자열의 경우 == 연산자를 사용하면 원치 않는 결과를 가져올 수 있다.
값은 같을 지라도 메모리 주소가 다르기 때문이다. 
char 배열을 이용한 문자열의 경우 변수는 주소를 가리키므로 == 연산자를
사용하지 않고 strcmp() 함수를 사용한다. 하지만 c++에서는 string 문자열의 
경우 == 연산자를 사용할 수 있다. 이유는 연산자 오버로딩에 있다.

*/
