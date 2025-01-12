#include "boxType.h"

int main() {
    cout << "Default Box: " << endl;
    boxType defaultbox;
    defaultbox.print();

    cout << "\nParameterized Box:" << endl;
    // Parameterized constructor
    boxType paramBox(2.5, 3.5, 4.0);
    paramBox.print();

    cout << "\nSetting New Dimensions:" << endl;
    // Using setDimension
    paramBox.setDimension(5.0, 3.0, 4.5);
    paramBox.print();

    return 0;
}
