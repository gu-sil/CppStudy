#include <iostream>

class test
{
public:
	test()
	{
		std::cout << "기본 생성자 호출" << std::endl;
	}
	
	test(int n)
	{
		std::cout << "생성자(int) 호출" << std::endl;
		mn = n;
	}

	test(const test& test)
	{
		std::cout << "복사 생성자 호출" << std::endl;
		mn = test.GetN();
	}

	test& operator=(const test& test)
	{
		std::cout << "할당 연산자 호출" << std::endl;
		mn = test.GetN();
		return *this;
	}

	~test()
	{
		std::cout << "소멸자 호출" << std::endl;
	}

	test& operator++()
	{
		this->mn++;
		return *this;
	}

	test operator++(int)
	{
		test temp = *this;
		++*this;
		return temp;
	}

	test &operator--()
	{
		this->mn--;
		return *this;
	}

	test operator--(int)
	{
		test temp = *this;
		--*this;
		return temp;
	}

	int GetN() const
	{
		return (mn);
	}

private:
	int mn;
};

std::ostream& operator<<(std::ostream& os, const test& test)
{
	os << test.GetN();
	return os;
}

const test& ReturnTempeoraryObject(const test& test)
{
	return test;
}

const test& CreateClass(const test& test)
{
	return test;
}

int	main(void)
{
	{
		std::cout << "===== q1 Test =====" << std::endl;
		test c = test(5);
		test d = test(10);
		c++;
		std::cout << c << std::endl;
		(d++)++;
		std::cout << d << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "===== q2 =====" << std::endl;
		const test &a = ReturnTempeoraryObject(test(10));
		const test &b = CreateClass(a);

		std::cout << a << std::endl;
		std::cout << b << std::endl;

		std::cout << std::endl;
	}
	return 0;
}