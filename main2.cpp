#include "exercise2.h"

int main() {
    Salary *psalary1;

    psalary1 = new FTRate("Ahmed","CSC302", 3000);
    psalary1 = new TutorRate(psalary1,"MAT102");
    psalary1 = new TutorRate(psalary1,"MAT333");

    cout << psalary1->getEmployee() << endl;
    cout << psalary1->getCourse() << endl;
    cout << psalary1->getAmount() << endl;

    return 0;
}


