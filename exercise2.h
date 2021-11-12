#include <string>
#include <iostream>
using namespace std;

class Salary {
    string employee, course;
    float amount;
    
    public:
    Salary(){}
    virtual string getEmployee()=0;
    virtual string getCourse()=0;
    virtual float getAmount()=0;
};

class FTRate : public Salary {
    public:
    string employee;
    string course;
    float amount;

    public:
    FTRate(){}
    FTRate(string employee, string course, float amount) {
        this->employee = employee;
        this->course = course;
        this->amount = amount;
    }
    ~FTRate(){};
    string getEmployee() {return this->employee;}
    string getCourse() {return this->course;}
    float getAmount() {return this->amount;}
};

class PTRate : public Salary {
    public:
    string employee, course;
    float amount;

    public:
    PTRate(string employee, string course, float amount) {
        this->employee = employee;
        this->course = course;
        this->amount = amount;
    }
};

class TutorRate : public Salary {
    string course;
    float amount = 1000.00;
    Salary *ps;

    public:
    TutorRate(Salary *ps, string course) {
        this->ps = ps;
        this->course = course;
    }
    string getEmployee(){return ps->getEmployee();}
    string getCourse(){return ps->getCourse() + course;}
    float getAmount(){return this->amount + ps->getAmount();}
};