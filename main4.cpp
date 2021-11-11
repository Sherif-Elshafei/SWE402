#include "exercise4.h"

int main() {
    WeatherStation* pws;
    MetroNews* po;

    pws = new WeatherStation();
    po = new MetroNews(pws);


    pws->setTemp(25);
    pws->setHumidity(35);
    pws->setPressure(1);
    
    pws->notify();

    return 0;
}