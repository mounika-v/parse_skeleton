#include "get_contour.h"
#include "makeoff.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    char sketchsource[100];
    // cin.ignore(1000, '\n');
    cin.get(sketchsource,100);
    cout<<"Location given: "<<sketchsource<<endl;
    getcontour(sketchsource);
    makeofffile();
    return 0;
}
