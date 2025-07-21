#include <iostream>
#include "Vetor.h"

using namespace std;

int main()
{
    Vetor<int> vet;

    vet.add(0, 10);
    vet.add(1, 10);

    cout << vet.size() << endl;

    return 0;
}
