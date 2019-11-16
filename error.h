#ifndef ERROR
#include "header.h"
class error{
    public:
        virtual void print() = 0;
};
class error_bad_option:public error{
    public:
        virtual void print(){
            cout<<"error:Bad Options!"<<endl;
            exit(0);
        }
};
class error_branch_not_found:public error{
    public:
        virtual void print(){
            cout<<"error:Branch is not true value!"<<endl;
            exit(0);
        }
};
class error_too_low_input:public error{
    public:
        virtual void print(){
            cout<<"error:your inputs are very short!"<<endl;
            exit(0);
        }
};
#define ERROR
#endif
