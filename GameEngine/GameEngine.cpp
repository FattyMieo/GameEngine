// GameEngine.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

class Com
{
public:
	int a;
	
	Com()
	{
		a = 100;
		cout << "Com constructed" << endl;
	}
	
	virtual ~Com()
	{
		cout << "Com destructed" << endl;
	}
};

class Pen : public Com
{
private:
	int* num;

public:
	Pen()
	{
		num = new int;
		cout << "Pen constructed" << endl;
	}
	
	virtual ~Pen() //<!> virtual helps inherited class to call parent's destructor <!>
	{
		delete num;
		cout << "Pen destructed" << endl;
	}
};

void TestConstructor()
{
	//while(true)
	{
		//Com a;
		//Com b;
		
		//Com* com3 = new Com(); //Dynamic Allocation - Memory Leaking
		//delete com3; //Manual Release Allocaion

		//Pen pen;

		//Pen* pen = new Pen();
		//delete pen;

		//Com* pen = new Pen(); //Memory Leak - Add virtual to both desturctors
		//delete pen;
		//^ Result ^
		//Com constructor
		//Pen constructor
		//Com destructor

		
		
		
	}
	
	
	
	system("PAUSE");
}
/*
class Character
{
public:
	virtual void Fly();
};

class EnemyA : public Character
{
};

class EnemyB : public Character
{
};

Character* CreateCharacter(int a)
{
	//custom logic
	//...
	
	if(a < 100)
		return new EnemyA();
	else
		return new EnemyB();
}

int main()
{
	Character* ch = CreateCharacter(rand());
	
	delete ch;
}
*/
void TestPtr()
{
	int num1 = 5;
	int num2 = 3;
	int num3 = 2;
	int* num4 = &num1;
	int& num5 = num2;
	int* num6 = num4;
	

	//test 1
	cout << num1 << ", " << num4 << endl;
	//cout << &num1 << endl;
	
	//test 2
	num1 = 10;
	cout << num1 << ", " << *num4 << endl; //The Reference of num4 == num1
	//cout << num4 << endl;
	
	//test 3
	*num4 = 100;
	cout << num1 << ", " << *num4 << endl;

	//test 4a
	cout << num1 << ", " << num5 << endl;

	//test 4b
	num5 = 99;
	cout << num1 << ", " << num5 << ", " << num2 << endl;

	//test 5
	*num6 = 200;
	cout << *num6 << ", " << *num4 << ", " << num1 << endl;

	//200, 200, 200
	
	//test 6
	int** num7 = &num4;
	cout << num7 << ", " << num4 << ", " << *num7 << endl;
	
	//<Address of num4>, <Address of num1>, <Address of num1>

	system("PAUSE");
}

/*
int main()
{
	//TestPtr();
	TestConstructor();
    return 0;
}
*/

