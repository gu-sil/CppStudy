#ifndef GCIN_HPP
# define GCIN_HPP

# include <iostream>
class Gcin : public std::istream
{
public:
	explicit Gcin (std::streambuf* sb);
	class HandleError : public std::istream::failure
	{
		virtual const char* what() const throw() {
			return "에러! 에러!"; }
	};
	Gcin& operator>>(int& num);
	~Gcin();
};

Gcin&	Gcin::operator>>(int& num)
{
	try
	{
		this->exceptions(std::istream::badbit | std::istream::failbit);
		std::istream::operator>>(num);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		this->clear();
		this->ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return *this;
}
Gcin::Gcin(std::streambuf* sb) : std::istream(sb) {}
Gcin::~Gcin() {}

#endif