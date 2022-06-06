#include <iostream>
#include <fstream>
#include <sstream>

void PrintAllStatus(std::ios_base& iosb)
{

	if (iosb.good())
		std::cout << "good" << std::endl;
	if (iosb.bad())
		std::cout << "bad" << std::endl;
	if (iosb.fail())
		std::cout << "fail" << std::endl;
	if (iosb.eof())
		std::cout << "eof" << std::endl;
}

int main(void)
{
	{
		std::cout << "===== goodbit Test =====" << std::endl;
		std::ifstream ifout;

		ifout.open("testfile");
		PrintAllStatus(ifout);
	}

	std::cout << std::endl;
	{
		std::cout << "===== badbit Test =====" << std::endl;
		std::streambuf *psbuf, *backup;

		backup = std::cout.rdbuf(); // back up cout's streambuf
		std::cout.rdbuf(nullptr);	 // assign streambuf to cout
		printf("good: %d\n", std::cout.good());
		printf("bad: %d\n", std::cout.bad());
		printf("fail: %d\n", std::cout.fail());
		printf("eof: %d\n", std::cout.eof());
		std::cout.rdbuf(backup); // restore cout's original streambuf
	}

	std::cout << std::endl;
	{
		std::cout << "===== failbit Test =====" << std::endl;
		std::ifstream ifout;

		ifout.open("FileDoesntExist");
		PrintAllStatus(ifout);
	}
	
	std::cout << std::endl;
	{
		std::cout << "===== eofbit Test =====" << std::endl;
		std::ifstream ifout;
		std::string buff;

		ifout.open("testfile");
		while (getline(ifout, buff))
		{
		}
		
		// fail도 같이 올라가네?
		// https://modoocode.com/149
		// https://runebook.dev/ko/docs/cpp/io/ios_base/iostate
		PrintAllStatus(ifout); 
	}
	return 0;
}