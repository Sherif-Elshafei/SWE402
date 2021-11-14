#include "components1.h"

int main() {
    //cout << "hello world" << endl;
    Beverage *pbeverage1;
    
    pbeverage1 = new HouseBlend();
    pbeverage1 = new Milk(pbeverage1);
    pbeverage1 = new Milk(pbeverage1);
    pbeverage1 = new Milk(pbeverage1);

    cout << pbeverage1->getDescription();
    cout << pbeverage1->getCost() << endl;

    return 0;
}