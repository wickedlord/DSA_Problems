#include <iostream>
using namespace std;

class Hero {
    private:
    // initialise the properties
    //private cannot be accessed directly
    int health;
    char level;

    public:

    //used to get health and level from private
    int getHealth () {
        return health;
    }
    char getlevel () {
        return level;
    }

    //used to set health and level from private
    void sethealth (int h) {
        health = h;
    }
    void setlevel (char c) {
        level = c;
    }
    
    //deafult constructor is automatically created
    /*
    creating own constructor
    Hero () {
        cout << "Hello";
        //only this will happen on creating ramesh
    }

    creating parametrised constructor
    Hero (int health, char level) {
        this->health = health;
        this->level = level;
        //this keyword copies the passed value to the nearest object.
    }

    copy constructor:
    used to copy an object's value to another
    e.g. 
    Hero R(44,'A');
    Hero S(R);
    //hence we have copied r to s
    
    we can also create our own constructor
    Hero R(&S) //remember to use ampercent.

    shallow copy is done by default copy constructor where same memory
    is accessed by two different names
    deep copy which is done by creating a constructor of our own craetes
    a copy of the object


    //destructor deallocates the memory from an object
    manually
    ~Hero () {
        cout << destructor called
    }
    it only works for static allocation, for dynamic allocation, you
    need to call the destructor manually.


    another keyword is static
    static is used access a variable from a class even when the object is not initialised
    static int herohealth;

    static fucntion are also there which can only access static members
    e.g. static int func () {
        return herohealth;
    }
    */

};

//int Hero::herohealth = 5;
//now it be accessed directly in main fuction without creating an object.
int main () {
    Hero ramesh;
    // can also be created dynamically
    //Hero *a = new Hero;

    cout << "Before setting :" << endl;
    //we will get only garbage values
    cout << "Health is : " << ramesh.getHealth() << endl;
    // also can be (*a)->getHealth()
    cout << "Level is : " << ramesh.getlevel() << endl;

    cout << "After setting : " << endl;
    ramesh.sethealth(70);
    cout << "Health is : " << ramesh.getHealth() << endl;
    ramesh.setlevel('A');
    cout << "Level is : " << ramesh.getlevel() << endl;

}