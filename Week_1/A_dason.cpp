#include <iostream>

void	PrintIostate(const std::ios_base& object)
{
	std::cout << "badbit :: " << object.bad() << std::endl;
	std::cout << "failbit :: " << object.fail() << std::endl;
	std::cout << "eofbit :: " << object.eof() << std::endl;
	std::cout << "goodbit :: " << object.good() << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	std::cout.setf(std::ios_base::boolalpha);

	//badbit
	std::cout << static_cast<std::streambuf *>(nullptr);
	printf("%d\n", std::cout.bad());
	std::cout.clear();
	
	// failbit and eofbit
	for (int i = 0; i < 2; i++)
	{
		int	num;
		std::cin >> num;
		PrintIostate(std::cin);
		::fflush(stdin);
		std::cin.clear();
	}
	return (0);
}