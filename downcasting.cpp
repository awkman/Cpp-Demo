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

int main(int argc, char *argv[])
{
    base *b1 = new base();
    base *b2 = new derived();

	b1->show();
	b2->show();

	try{
		derived *bd1 = dynamic_cast<derived *>( b1 );
		derived *bd2 = dynamic_cast<derived *>( b2 );

		if( bd1 ){
			cout << "bd1 downcasted into its derived class object" << endl;
			bd1->show();
		}
		else{
			cout << "b1 can't be downcasting to its derived class object" << endl;
		}

		if( bd2 ){
			cout << "bd2 downcasted into its derived class object" << endl;
			bd2->show();
		}
		else{
			cout << "b2 can't be downcasting to its derived class object" << endl;
		}
	}
	catch(bad_cast){
		cout << "downcasting failed" << endl;
	}

    return 0;
}

