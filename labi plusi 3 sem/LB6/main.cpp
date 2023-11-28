#include <iostream>
#include "FileBin.h"
#include "FileTxt.h"
#include "Example.h"
#include "MyContainer.h"

using namespace std;

int main() {

    List<Person> person;

    Person p("Piotr",18,"Sharai");
    Person x("Pavel",34,"Sharai");
    Person y("Yury",58,"Sharai");

    person.push(p);
    person.push(x);
    person.push(y);

    FileBin bin;

    cout << endl << endl << "BINARY" << endl << endl;

    bin.WriteToBinFile(person);
    bin.ShowBinFile();

    cout << endl << endl << "BINARY";

    FileTxt txt;

    cout << endl << endl << "TXT" << endl << endl;

    txt.WriteToTxtFile(person);
    txt.ShowTxtFile();

    cout  << endl << endl<< "TXT";

    return 0;
}
