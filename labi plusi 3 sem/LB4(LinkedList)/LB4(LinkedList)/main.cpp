#include <iostream>
#include "LinkedList.h"
#include "CaseCheck.h"
#include "CheckCaseInput.h"

int main()
{
    
    int a;

    cout << "int - 1 , str - 2: " ;

    while(1){
        try{
            if(!(cin >> a))
                throw CheckCase(3,"Введено не число!");

            if(a < 1 || a > 2)
                throw CheckCaseInput(0,"Ввели не 1 и не 2!");
            break;
        }

        catch(CheckCase ex){
            ex.show();
            rewind(stdin);
            cin.clear();
        }

        catch(CheckCaseInput ex){
            ex.show();
            rewind(stdin);
            cin.clear();
        }

    }
    cout << endl << endl;

        switch (a) {
            case 1:{
                CreateListOfInts();
                break;
            }

            case 2:{
                CreateListOfStrings();
                break;
            }

            default:
                break;
            }
    MyList<MyNode<int>> list;

  return 0;
}
