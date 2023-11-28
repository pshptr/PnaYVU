#ifndef notThisIndex_h
#define notThisIndex_h
#include "Exception.h"

class notThisIndex : public MyException{

public:
    notThisIndex(int code,string message){
        this->code = code;
        msg = message;

    }

};

#endif /* notThisIndex_h */
