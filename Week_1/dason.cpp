#include <iostream>
#include <fstream>

void print_all_flags(std::istream& is)
{
	std::cout << "good\tbad\tfail\teof\n";
	std::cout << is.good() << "\t" << is.bad() << "\t" << is.fail() << "\t" << is.eof() << "\n";
}

int main(void)
{
	print_all_flags(std::cin);
	std::istream is(nullptr);
	print_all_flags(is);
	std::filebuf fb;
	fb.open("empty.txt", std::ios::in);
	std::istream is_two(&fb);
	is_two.get();
	print_all_flags(is_two);
}
