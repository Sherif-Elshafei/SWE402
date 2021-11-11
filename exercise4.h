#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Observer;

class Subject {
    public:
    Subject(){};
    virtual ~Subject(){};

    vector<Observer*> pobservers;
    virtual void attach(Observer*)=0;
    virtual void detach(Observer*)=0;
    virtual void notify()=0;
};

class Observer {
    public:
    Observer(){};
    ~Observer(){};
    virtual void update(Subject* theChangeSubject) = 0;
};

class WeatherStation: public Subject {
    float temp, humidity, pressure;
    float charts[1000][3];
    public:
    WeatherStation(){}
    ~WeatherStation(){}

    void setTemp(float t){this->temp = t;}
    void setHumidity(float h){this->humidity = h;}
    void setPressure(float p){this->pressure = p;}
    
    float getTemp() {return this->temp;}
    float getHumidity() {return this->humidity;}
    float getPressure() {return this->pressure;}

    void attach(Observer* o){
        this->pobservers.push_back(o);
    }

    void detach(Observer* o){
        int count = pobservers.size();
        int i;
        for (i = 0; i < count; i++) {
            if(pobservers[i] == o)
                break;
            }
            if(i < count)
                pobservers.erase(pobservers.begin() + i);
    }

    void notify() {
        int count = pobservers.size();
        for (int i = 0; i < count; i++)
            (pobservers[i])->update(this);
    }
};

class MetroNews:public Observer {
    private:
    WeatherStation* psubject;

    public:
    MetroNews(WeatherStation* ps){
        this->psubject=ps;
        this->psubject->attach(this);
    }

    void display(float t, float h, float p){
        cout<<"Welcome to Metro News, the temprature now is "<<t<<endl;
        cout<<"Welcome to Metro News, the humidity now is "<<h<<endl;
        cout<<"Welcome to Metro News, the Pressure now is "<<p<<endl;
    }
    void update(Subject *theChangedSubject){
        if(theChangedSubject == psubject)
            display(psubject->getTemp(), psubject->getHumidity(), psubject->getPressure());
    }
};