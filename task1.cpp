#include <iostream>
using namespace std;

//Без віртуального успадкування  
class Seventh
{
protected:
    int seventhData;
public:
    Seventh()
    {
        seventhData = 70;
    }
    ~Seventh() {}
    void getSize()
    {
        cout << "Size of non-virtual class(7): " << sizeof(*this) << " bytes" << endl;
    }
};

class Sixth : public Seventh
{
protected:
    int sixthData;
public:
    Sixth()
    {
        sixthData = 60;
    }
    ~Sixth() {}
    void getSize()
    {
        cout << "Size of non-virtual class(6): " << sizeof(*this) << " bytes" << endl;
    }
};

class Fifth : public Sixth, public Seventh
{
protected:
    int fifthData;
public:
    Fifth()
    {
        fifthData = 50;
    }
    ~Fifth() {}
    void getSize()
    {
        cout << "Size of non-virtual class(5): " << sizeof(*this) << " bytes" << endl;
    }
};

class Fourth : public Sixth
{
protected:
    int fourthData;
public:
    Fourth()
    {
        fourthData = 40;
    }
    ~Fourth() {}
    void getSize()
    {
        cout << "Size of non-virtual class(4): " << sizeof(*this) << " bytes" << endl;
    }
};

class Third : public Fifth, public Sixth
{
protected:
    int thirdData;
public:
    Third()
    {
        thirdData = 30;
    }
    ~Third() {}
    void getSize()
    {
        cout << "Size of non-virtual class(3): " << sizeof(*this) << " bytes" << endl;
    }
};

class Second : public Third
{
protected:
    int secondData;
public:
    Second()
    {
        secondData = 20;
    }
    ~Second() {}
    void getSize()
    {
        cout << "Size of non-virtual class(2): " << sizeof(*this) << " bytes" << endl;
    }
};

class First : public Third, public Fourth
{
protected:
    int firstData;
public:
    First()
    {
        firstData = 10;
    }
    ~First() {}
    void getSize()
    {
        cout << "Size of non-virtual class(1): " << sizeof(*this) << " bytes" << endl;
    }
};

//З віртуальним успадкуванням  
class vSeventh
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
       cout << "Size of virtual class(7): " << sizeof(*this) << " bytes" << endl;
   }
};

class vSixth : virtual public vSeventh
{
protected:
   int vSixthData;
public:
   vSixth()
   {
       vSixthData = 60;
   }
   ~vSixth() {}
   void getVirtualSize()
   {
       cout << "Size of virtual class(6): " << sizeof(*this) << " bytes" << endl;
   }
};

class vFifth : virtual public vSixth, virtual public vSeventh
{
protected:
   int vFifthData;
public:
   vFifth()
   {
       vFifthData = 50;
   }
   ~vFifth() {}
   void getVirtualSize()
   {
       cout << "Size of virtual class(5): " << sizeof(*this) << " bytes" << endl;
   }
};

class vFourth : virtual public vSixth
{
protected:
   int vFourthData;
public:
   vFourth()
   {
       vFourthData = 40;
   }
   ~vFourth() {}
   void getVirtualSize()
   {
       cout << "Size of virtual class(4): " << sizeof(*this) << " bytes" << endl;
   }
};

class vThird : virtual public vFifth, virtual public vSixth
{
protected:
   int vThirdData;
public:
   vThird()
   {
       vThirdData = 30;
   }
   ~vThird() {}
   void getVirtualSize()
   {
       cout << "Size of virtual class(3): " << sizeof(*this) << " bytes" << endl;
   }
};

class vSecond : virtual public vThird
{
protected:
   int vSecondData;
public:
   vSecond()
   {
       vSecondData = 20;
   }
   ~vSecond() {}
   void getVirtualSize()
   {
       cout << "Size of virtual class(2): " << sizeof(*this) << " bytes" << endl;
   }
};

class vFirst : virtual public vThird, virtual public vFourth
{
protected:
   int vFirstData;
public:
   vFirst()
   {
       vFirstData = 10;
   }
   ~vFirst() {}
   void getVirtualSize()
   {
       cout << "Size of virtual class(1): " << sizeof(*this) << " bytes" << endl;
   }
};

int main()
{
   //Без віртуального успадкування  
   Seventh obj1;
   obj1.getSize();

   Sixth obj2;
   obj2.getSize();

   Fifth obj3;
   obj3.getSize();

   Fourth obj4;
   obj4.getSize();

   Third obj5;
   obj5.getSize();

   Second obj6;
   obj6.getSize();

   First obj7;
   obj7.getSize();

   cout << endl;

   //З віртуальним успадкуванням  
   vSeventh vObj1;
   vObj1.getVirtualSize();

   vSixth vObj2;
   vObj2.getVirtualSize();

   vFifth vObj3;
   vObj3.getVirtualSize();

   vFourth vObj4;
   vObj4.getVirtualSize();

   vThird vObj5;
   vObj5.getVirtualSize();

   vSecond vObj6;
   vObj6.getVirtualSize();

   vFirst vObj7;
   vObj7.getVirtualSize();

   return 0;
}
