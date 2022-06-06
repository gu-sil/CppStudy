#include <iostream>

class gcin
{
public:
	std::istream& operator>>(int& n)
	{
		std::cin >> n;
		if (std::cin.bad() || std::cin.fail())
		{
			std::cerr << "잘못된 값을 입력하였습니다." << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		return std::cin;
	}

private:
};

int main(void)
{
	gcin cin;
	int num1;
	int num2;

	cin >> num1;
	cin >> num2;

	std::cout << "num1: " << num1 << std::endl;
	std::cout << "num2: " << num2 << std::endl;
	return 0;
}