#include <iostream>

class test
{
public:
	test();
	test(int);
	test(const test&);
	~test();
	test& operator++(int);
	int GetNum() const;
private:
	int mNum;
};

test::test()
{
	mNum = 0;
	std::cout << "default constructor called.\n";
}

test::test(int num)
{
	mNum = num;
	std::cout << "int constructor called.\n";
}

test::test(const test& other)
{
	mNum = other.GetNum();
	std::cout << "copy constructor called.\n";
}

int test::GetNum() const
{
	return mNum;
}

test& test::operator++(int)
{
	(this->mNum)++;
	return *this;
}

test::~test()
{
	std::cout << "destructor called.\n";
}

// param: temp
test&	ReturnTemporaryObject(test a)
{
	return (a);
}

test&	CreateClass(test& a)
{
	return a;
}

int	main(void)
{
	test&	a = ReturnTemporaryObject(test(10));
	test&	b = CreateClass(a);
	
	(a++)++;
	std::cout << a.GetNum() << std::endl;
	(void)b;
	return (0);
}
