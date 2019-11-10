
#include "file.h"
void create_change_log_in_omgh(vector<string> & lines,string &branch, string &omgh,char options[26]){
    string cmd = "echo \"\" > " + omgh + "/" + "changelog." + branch;
    //cout << cmd;
    exec(cmd);
    ofstream text(omgh + "/" + "changelog." + branch,ios::out | ios::in);
    for(int i = 0; i < lines.size(); i++){
        text << lines[i];
        text << endl;
    }
    text.close();
}
vector<string> read_from_file(string path,string branch){
    vector<string> lines;
    string line;
    string final_path = path + "/" +branch;
    //cout<<final_path <<endl;
    ifstream myfile(final_path ,ios::in);
    while(getline(myfile,line)){
        //cout<<line<<endl;
        lines.push_back(line);
        line = line;
    }
    return lines;
}