#ifndef CheckString_h
#define CheckString_h


class CheckString:public MyException {
    
public:
    
     CheckString(int code,string message){
         this->code = code;
         msg = message;

    }
 
};

#endif /* CheckString_h */
