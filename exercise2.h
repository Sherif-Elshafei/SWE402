#include <string>
#include <iostream>
using namespace std;

class TutorRate;

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
    ~FTRate(){};
    FTRate(){}
    FTRate(string employee, string course, float amount) {
        this->employee = employee;
        this->course = course;
        this->amount = amount;
    }
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
    private:
    string course;
    float amount = 1000.00;
    Salary *ps;
    TutorRate *pTR = NULL;
    static int count;

    TutorRate(Salary *ps, string course) {
        this->ps = ps;
        this->course = course;
        count++;
    }

    public:
    TutorRate(){}
    TutorRate* createMaxTwoInstances(Salary *ps, string course) {
        if (pTR==NULL){
            pTR = new TutorRate(ps, course);
        }

        else {
            if (count<=2) {
                pTR = new TutorRate(ps, course);
            }
            else {
                cout<<"can't tutor more than two courses"<<endl;
            }
        }
        return pTR;
    }

    string getEmployee(){return ps->getEmployee();}
    string getCourse(){return ps->getCourse() + course;}
    float getAmount(){return this->amount + ps->getAmount();}
};

int TutorRate::count=0;