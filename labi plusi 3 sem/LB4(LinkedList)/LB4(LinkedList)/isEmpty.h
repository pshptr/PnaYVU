#ifndef isEmpty_h
#define isEmpty_h
#include "Exception.h"


class isEmpty:public MyException{

public:
    isEmpty(int code,string message){
        this->code = code;
        msg = message;
    }

};


#endif /* isEmpty_h */
