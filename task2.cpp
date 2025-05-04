#include <iostream>
using namespace std;

class Shape 
{
public:
   Shape() {};
   virtual void getVolume() const {}
   virtual ~Shape() {} 
};

class Parallelepiped : public Shape 
{
private:
   int a, b, c;
public:
   Parallelepiped(int a, int b, int c) : a(a), b(b), c(c) {}

   void getVolume() const override 
   {
       cout << "Volume of parallelepiped: " << a * b * c << endl;
   }
};

class Pyramid : public Shape 
{
private:
    int a, b, h;
public:
    Pyramid(int a, int b, int h) : a(a), b(b), h(h) {}

    void getVolume() const override 
    {
        cout << "Volume of pyramid: " << (a*b*h)/3 << endl;
    }
};

class Tetraedr : public Shape
{
private:
    float side;
    float pi = 3.141592;
public:
    Tetraedr(int s) : side(s) {}

    void getVolume() const override
    {
        cout << "Volume of tetraedr: " << pow(side, 3) / (6 * sqrt(2)) << endl;
    }
};

class Sphere : public Shape
{
private:
    float r;
	float pi = 3.141592;
public:
    Sphere(int r) : r(r) {}

    void getVolume() const override
    {
		cout << "Volume of sphere: " << (4.0 / 3.0) * pi * pow(r, 3) << endl;
    }
};

int main() {
   Shape* shapes[4];
   shapes[0] = new Parallelepiped(3, 4, 5);
   shapes[1] = new Pyramid(3, 4, 5);
   shapes[2] = new Tetraedr(3);
   shapes[3] = new Sphere(3);

   for (int i = 0; i < 4; i++) {
	   shapes[i]->getVolume();
	   delete shapes[i];
   }

   cout << endl;

   return 0;
}