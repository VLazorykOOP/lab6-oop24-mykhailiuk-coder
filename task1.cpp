#include <iostream>  
using namespace std;

//Без віртуального успадкування
class First
{
protected:
	int firstData;
public:
	First()
	{
		firstData = 10;
	}
	~First(){}
};

class Second
{
protected:
	int secondData;
public:
	Second()
	{
		secondData = 20;
	}
	~Second(){}
};

class Third : public First, public Second
{
protected:
	int thirdData;
public:
	Third()
	{
		thirdData = 30;
	}
	~Third(){}
};

class Fourth : public First
{
protected:
	int fourthData;
public:
	Fourth()
	{
		fourthData = 40;
	}
	~Fourth(){}
};

class Fifth : public Third
{
protected:
	int fifthData;
public:
	Fifth()
	{
		fifthData = 50;
	}
	~Fifth(){}
};

class Sixth : public Third, public Fourth, public Fifth
{
protected:
	int sixthData;
public:
	Sixth()
	{
		sixthData = 60;
	}
	~Sixth(){}
};

class Seventh : public Sixth, public Fifth
{
protected:
	int seventhData;
public:
	Seventh()
	{
		seventhData = 70;
	}
	~Seventh(){}
	void getSize()
	{
		cout << "Size of final class: " << sizeof(*this) << " bytes" << endl;
	}
};

//З віртуальним успадкуванням
class vFirst
{
protected:
	int vFirstData;
public:
	vFirst()
	{
		vFirstData = 10;
	}
	~vFirst() {}
};

class vSecond
{
protected:
	int vSecondData;
public:
	vSecond()
	{
		vSecondData = 20;
	}
	~vSecond() {}
};

class vThird : virtual public vFirst, virtual public vSecond
{
protected:
	int vThirdData;
public:
	vThird()
	{
		vThirdData = 30;
	}
	~vThird() {}
};

class vFourth : virtual public vFirst
{
protected:
	int vFourthData;
public:
	vFourth()
	{
		vFourthData = 40;
	}
	~vFourth() {}
};

class vFifth : virtual public vThird
{
protected:
	int vFifthData;
public:
	vFifth()
	{
		vFifthData = 50;
	}
	~vFifth() {}
};

class vSixth : virtual public vThird, virtual public vFourth, virtual public vFifth
{
protected:
	int vSixthData;
public:
	vSixth()
	{
		vSixthData = 60;
	}
	~vSixth() {}
};

class vSeventh : virtual public vSixth, virtual public vFifth
{
protected:
	int vSeventhData;
public:
	vSeventh()
	{
		vSeventhData = 70;
	}
	~vSeventh() {}
	void getVirtualSize()
	{
		cout << "Size of virtual class: " << sizeof(*this) << " bytes" << endl;
	}
};

int main()
{
	Seventh obj1;
	obj1.getSize();
	vSeventh obj2;
	obj2.getVirtualSize();
	return 0;
}