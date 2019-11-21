#include "header.h"
#include "error.h"
#include "check.h"
#include "file.h"
#include "diff.h"
int main(int argc , char *argv[]){
    char options[26] = {'0'};
    vector<string> lines;
    int iter_arg = 0;
<<<<<<< HEAD
    string branch = "master";
    iter_arg = check_options(argv[1],options);
    if(options[(int)'b' - (int)'a'] == 1){
        check_branch(argv[1+iter_arg]);
        branch = argv[1 + iter_arg];
        iter_arg ++;
    }
    string omgh = argv[1 + iter_arg];
=======
    string omgh = ".";
    string branch = "master";
    iter_arg = check_options(argv[1],options);
    check_tedad_voroodi(options,argv,argc);
    if(options[(int)'b' - (int)'a'] == 1){
        check_branch(argv[1+iter_arg]);
        branch = argv[1 + iter_arg];
        iter_arg++;
    }
    omgh = argv[1 + iter_arg];
>>>>>>> 10fc428d95818a949df004cae598a820db0de774
    vector<string> faghat_taghire_omgh_lines;
    lines = read_from_file(".git/logs/refs/remotes/origin",branch);
    faghat_taghire_omgh_lines = faghat_taghire_omgh(lines,branch,omgh);
    //cout<<endl<<"****************"<<endl;   
    //for(int i = 0; i < faghat_taghire_omgh_lines.size(); i++)cout<<faghat_taghire_omgh_lines[i]<<endl;
    if(options[(int)'f' - (int)'a'] == 1)create_change_log_in_omgh(faghat_taghire_omgh_lines,branch,omgh,options);
    if(options[(int)'p' - (int)'a'] == 1)print_change(faghat_taghire_omgh_lines,options);
    //else cout<<"ssssssssssssssssssssss"<<endl;
    return 0;
}
