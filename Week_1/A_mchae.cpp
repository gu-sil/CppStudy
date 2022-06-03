#include <iostream>
#include <string>

class test
{
private:
public:
	int num;
	test(void);
	test(int n);
	test(const test& copy);
	test&	operator=(const test& copy);
	~test();
};

test::test(void) : num(0)
{
	std::cout << "Class has been created!" << std::endl;
}

test::test(int n) : num(n)
{
	std::cout << "Class has been created!" << std::endl;
}

test::test(const test& copy) : num(copy.num)
{
	std::cout << "Class copied using copy constructor!" << std::endl;
}

test& test::operator=(const test& copy)
{
	std::cout << "Class copied using assignation operator!" << std::endl;
	this->num = copy.num;
	return *this;
}

std::ostream&	operator<<(std::ostream& out, const test& ref)
{
	out << ref.num;
	return out;
}

test::~test() {}

const test&	CreateClass(const test& a)
{
	return a;
}

const test&	ReturnTemperaryObject(const test& a)
{
	return (a);
}

int	main(void)
{
	const test&	a = ReturnTemperaryObject(test(10));
	const test&	b = CreateClass(a);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	return (0);
}