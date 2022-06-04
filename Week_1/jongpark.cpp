#include <iostream>

class gcin
{
};

std::istream& operator>> (gcin& gc, int& dest)
{
	std::cin >> dest;
	if (std::cin.fail() || std::cin.bad())
	{
		std::cerr << "제대로 된 입력이 아닙니다.\n" << std::endl;
		std::cin.clear();
		std::cin.ignore((1 << 30) - 1, '\n');
	}
	return std::cin;
}

int main()
{
	int num, num2;
	gcin gc;
	gc >> num;  
	gc >> num2; 

	std::cout << num2 << std::endl; // num에는 제대로 입력값이 들어가지 않았겠지만 num2는 잘 들어가 있어야 한다.
}
