#include <iostream>
using namespace std;

void waterjug(int jug1, int jug2, int target) {
    int x = 0, y = 0;
    while (x != target && y != target) {
        if (x == 0) {
            x = jug1;
            cout << "Fill Jug1: " << x << endl;
        } 
        else if (y == jug2) {
            y = 0;
            cout << "Empty Jug2: " << y << endl;
        } 
        else {
            int transfer = min(x, jug2 - y);
            x -= transfer;
            y += transfer;
            cout << "Transfer from Jug1 to Jug2: Jug1 = " << x << ", Jug2 = " << y << endl;
        }
    }
    
    if (x == target) {
        cout << "Target achieved in Jug1: " << x << endl;
    } 
    else if (y == target) {
        cout << "Target achieved in Jug2: " << y << endl;
    }
}

int main() {
    int jug1, jug2, target;
    cout << "Enter the capacity of jug1: ";
    cin >> jug1;
    cout << "Enter the capacity of jug2: ";
    cin >> jug2;
    cout << "Enter the target amount: ";   
    cin >> target;

    if (target == jug1 || target == jug2) {
        cout << "Target amount is equal to one of the jug's capacity" << endl;
        return 0;
    }

    if (jug1 < jug2) swap(jug1, jug2);

    bool usedDrum = false;
    int drum = 0;
    int remaining = target;

    // Step 1: Fill drum directly if target > jug1
    if (target > jug1) {
        usedDrum = true;
        while (remaining > jug1) {
            drum += jug1;
            remaining -= jug1;
            cout << "Fill Jug1 and pour into Drum: Drum = " << drum << ", Remaining = " << remaining << endl;
        }
    }

    // Step 2: Use normal water jug algorithm for remaining part
    if (remaining > 0) {
        waterjug(jug1, jug2, remaining);
        if (usedDrum) drum += remaining;
    }

    // Only print final drum amount if drum was used
    if (usedDrum) {
        cout << "\nFinal Drum Amount: " << drum << endl;
    }

    return 0;
}
