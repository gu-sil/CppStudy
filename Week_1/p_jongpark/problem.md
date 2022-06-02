# generous std::cin

## 문제
cin과 비슷하게 동작하지만 **잘못된 입력이 들어오면 에러 메세지를 출력**하고 **다시 입력을 받을 수 있는** cin을 구현하세요.
std::cin은 다음과 같이 동작합니다.
```c++
#include <iostream>

int main()
{
	int num, num2;
	std::cin >> num; // 고의적으로 문자를 입력하면 더이상 입력이 받아지지 않는다. 따로 에러메세지를 주지 않는다.
	std::cin >> num2; // 여기선 입력을 받을 수 없다.

	return 0;
}
```

이번 문제를 통해 구현해야 하는 gcin은 다음과 같이 동작해야 합니다.
```c++
#include <iostream>
#include "gcin"

int main()
{
	int num, num2;
	gcin >> num; // 이 때 에러 메세지를 출력하고 다시 입력을 받을 수 있어야 한다. 
	gcin >> num2; // cin과 달리 다시 입력값을 제대로 받아야 한다.

	std::cout << num2 << std::endl; // num에는 제대로 입력값이 들어가지 않았겠지만 num2는 잘 들어가 있어야 한다.
}
