1. 참조자를 이용해서 후위 증감 연산자(직접만든 클래스++)++ 혹은 (직접만든 클래스--)--를 완성하세요.
    - 기존 C++의 다른 자료형의 후위 증감연산자와 동일하게 작동 되어야 합니다.(작동 안되어야 함.)
    - ex) (int++)++;
2. 다음과 같은 코드에서 복사 생성자를 최대한 없애보세요
    
    ```
    int	main(void)
    {
    	test	a = ReturnTempeoraryObject(test(10));
    	test	b = CreateClass(a);
    
    	std::cout << a << std::endl;
    	std::cout << b << std::endl;
    	return (0);
    }
    
    ```
    
    ReturnTemporaryObject는 생성된 임시 객체를 받아서 그대로 리턴해줍니다.
    
    ```
    test	ReturnTemporaryObject(test a)
    {
    	return (a);
    }
    
    ```
    
    CreateClass는 매개변수로 받은 클래스를 그대로 리턴합니다.
    
    ```
    test	CreateClass(test a)
    {
    	return a;
    }
    
    ```
    
    이 과정에서 발생하는 모든 복사 생성자를 없애보세요