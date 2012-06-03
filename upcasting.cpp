#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class base{
    public:
        virtual void show() { cout << "I am base class object" << endl; }
};

class derived: public base{
    public:
        void show() { cout << "I am dervied class object" << endl; }
};

void passByValue(base);
void passByReference(base &);
void passByAddress(base *);

int main(int argc, char *argv[])
{
    base b;
    derived d;
    base *bd = &d;

	// bd is upcasting from derived class to base class
	bd->show();

	// pass by value
	passByValue( d );

	// pass by reference
	passByReference( d );

	// pass by address
	passByAddress( &d );

    return 0;
}

void passByValue(base b)
{
	cout << "This in pass by value function" << endl;
	b.show();
}

void passByReference(base &b)
{
	cout << "This in pass by reference function" << endl;
	b.show();
}

void passByAddress(base *b)
{
	cout << "This in pass by address function" << endl;
	b->show();
}
