#include "Header.h"

int main()
{
    cout << "OUTPUT DURATION:" << endl;

    Facade* facade = new Facade();

    facade->Duration();

    delete facade;
}

