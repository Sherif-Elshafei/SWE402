#include "exercise2.h"

int main() {
    Salary *psalary1;
    psalary1 = new FTRate("Ahmed","CSC302", 3000);
    TutorRate *pTR;

    psalary1=(TutorRate*) psalary1;

    //psalary1 = pTR->createMaxTwoInstances(psalary1,"MAT102");
    pTR->printcount();
    
    //psalary1 = psalary1->createMaxTwoInstances(psalary1,"MAT333");
    
    //Ptu = psalary1->createMaxTwoInstances(psalary1,"MAT444");
    //Ptu = Ptu->createMaxTwoInstances(psalary1,"MAT444");


    cout << psalary1->getEmployee() << endl;
    cout << psalary1->getCourse() << endl;
    cout << psalary1->getAmount() << endl;

    return 0;
}


