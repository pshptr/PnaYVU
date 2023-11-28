#ifndef Exception_h
#define Exception_h
#include <iostream>
#include <exception>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

class MyException{
   

protected:
    int code;
    string msg;
    
public:

     
    MyException()
        {
            msg = "Global Exception";
        }

        MyException(int code ,string message)
        {
            this->code = code;
           msg = message;
        }

        void show()
        {
            cout << "Ошибка: " << msg << "\nКод ошибки: " << code << endl;
        }
  
};



#endif

