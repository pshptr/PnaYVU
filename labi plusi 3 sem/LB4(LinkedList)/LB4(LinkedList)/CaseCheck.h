#ifndef CaseCheck_h
#define CaseCheck_h
#include "Exception.h"

class CheckCase:public MyException{
 
    
    
public:
    
    CheckCase(int code,string message){
        this->code = code;
        msg = message;

    }
    
    
    
};


#endif /* CaseCheck_h */
