#include "Gcin.hpp"
#include <fstream>

int main()
{
	std::filebuf fb;
	fb.open("test.txt", std::ios::in);
	Gcin gcin(&fb);

	int num, num2;
	gcin >> num; // 이 때 에러 메세지를 출력하고 다시 입력을 받을 수 있어야 한다.
	gcin >> num2; // cin과 달리 다시 입력값을 제대로 받아야 한다.

	std::cout << num2 << std::endl; // num에는 제대로 입력값이 들어가지 않았겠지만 num2는 잘 들어가 있어야 한다.
}
