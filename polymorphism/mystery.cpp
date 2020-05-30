#include<iostream>
using namespace std;

class Snow {
public:
    virtual void method2() 
    {
        cout << "Snow 2" << endl;
    }
    virtual void method3()
    {
        cout << "Snow 3" << endl;
    }
};

class Rain : public Snow {
public:
    virtual void method1() 
    {
        cout << "Rain 1" << endl;
    }
    virtual void method2()
    {  
        cout << "Rain 2" << endl;
    }
};

class Sleet : public Snow {
public:
    virtual void method2() 
    {
        cout << "Sleet 2" << endl;
        Snow::method2();
    }
    virtual void method3() 
    {
        cout << "Sleet 3" << endl;
    }
};

class Fog : public Sleet {
public:
    virtual void method1() 
    {
        cout << "Fog 1" << endl;
    }
    virtual void method3()
    {
        cout << "Fog 3" << endl;
    }
};

int main()
{
    //q1
    // Snow *var=new Sleet();
    // var->method2();
    //ans : Sleet 2 Snow 2

    //q2
    // Snow* var=new Rain();
    // var->method1();
    //ans:compiler error

    //q3
    // Snow* var3 = new Rain();
    // var3->method2();
    //ans Rain 2
    
    //q4
    // Snow* var4 = new Rain();
    // ((Rain*) var4)->method1();
    //ans:Rain 1

    //q5
    // Snow* var5 = new Fog();
    // ((Sleet*) var5)->method1();
    //ans:compiler error

    Snow* var6 = new Sleet();
    ((Rain*) var6)->method1();
    //op:crash

}