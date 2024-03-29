#include "check.h"
#include "header.h"
#include "error.h"
int check_options(string arg1,char options[]){
    try{
        if(arg1[0] != '-')return 0;
        for(int i = 1;i < arg1.size(); i++){
            if(arg1[i] != 'f' && arg1[i] != 'p' && arg1[i] != 'b')throw error_bad_option();
            options[arg1[i] - 'a'] = 1;
        }
    }
    catch(error_bad_option err){
        err.print();
    }
    return 1;
}
void check_branch(string branch){
    //cout << branch<<endl;
    stringstream temp(ios::in | ios::out);
    int flag = 0;
    string ls = exec("ls .git/logs/refs/heads");
    string file = "";
    temp <<ls;
    try{
        while(temp>>file){
            if(file ==branch)flag = 1;
        }
        if(flag == 0)throw error_branch_not_found();
    }
    catch(error_branch_not_found err){
        err.print();
    }
}
void check_tedad_voroodi(char options[],char* arg[],int &argc){
    int flag = 1;
    try{
        if(options[(int)'b' - (int)'a'] == 1)flag++;
        //cout<<argc<<endl<<flag<<endl;
        if(argc - 1<= flag){
            throw error_too_low_input();
        }
    }
    catch(error_too_low_input err){
        err.print();
    }
}