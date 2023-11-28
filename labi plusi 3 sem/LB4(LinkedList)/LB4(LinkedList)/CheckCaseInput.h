#ifndef CheckCaseInput_h
#define CheckCaseInput_h
#include "Exception.h"

class CheckCaseInput:public MyException{
    
public:
    CheckCaseInput(int code,string message){
        this->code = code;
        msg = message;
    }
    
};


#endif /* CheckCaseInput_h */
