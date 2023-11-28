#ifndef CheckOnInt_h
#define CheckOnInt_h


class CheckInt:public MyException {
    
public:  
    
    CheckInt(int code,string message){
        this->code = code;
        msg = message;

    }
 
};



#endif /* CheckOnInt_h */
