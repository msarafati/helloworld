#ifndef ERROR
#include "header.h"
class error{
    public:
        virtual void print() = 0;
};
class error_bad_option:public error{
    public:
        virtual void print(){
            cout<<"Bad Options!"<<endl;
            exit(0);
        }
};
class error_branch_not_found:public error{
    public:
        virtual void print(){
            cout<<"Branch is not true value!"<<endl;
            exit(0);
        }
};
#define ERROR
#endif
