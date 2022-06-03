#include <iostream>

void	PrintIostate(const std::ios_base& object)
{
	std::cout << "badbit :: " << object.bad() << std::endl;
	std::cout << "failbit :: " << object.fail() << std::endl;
	std::cout << "eofbit :: " << object.eof() << std::endl;
	std::cout << "goodbit :: " << object.good() << std::endl;
	std::cout << std::endl;
}

int main()
{
	int num, num2;
	std::cin >> num; // 고의적으로 문자를 입력하면 더이상 입력이 받아지지 않는다. 따로 에러메세지를 주지 않는다.
	// eof아닐 때
	std::cin.exceptions(std::ios_base::badbit | std::ios_base::failbit);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	// eof일 때 둘 중 하나(clearerr가 rewind를 호출.)
	// clearerr(stdin);
	// rewind(stdin);
	std::cin.clear();
	PrintIostate(std::cin);
	std::cin >> num2; // 여기선 입력을 받을 수 없다.

	return 0;
}
