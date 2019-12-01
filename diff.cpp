#include "diff.h"
vector<string> get_diff(string &hash1,string &hash2){
    string cmd = "git diff --name-only " + hash1 + " " + hash2;
    vector<string> ret;
    string javab = exec(cmd);
    //cout<<javab<<endl;
    string temp = "";
    stringstream kol_e_javab(ios::in | ios::out);
    kol_e_javab << javab;
    while(kol_e_javab >> temp){
        //cout<<temp<<endl;
        ret.push_back(temp);
    }
    return ret;
}
vector<string> faghat_taghire_omgh(vector<string> &lines,string &branch,string &omgh){
    string part1 = "",part2 = "";
    stringstream temp(ios::in | ios::out);
    vector<string> files_changes;
    vector<string> lines_javab;
    int size_omgh = omgh.size();
    int flag = 0; 
    //for(int i = 0; i < lines.size(); i++)cout<<lines[i]<<endl;
    //cout<<"------------"<<endl;
    //cout<<omgh<<endl;
    for(int j = 1; j < lines.size(); j++){
        temp.str("");
        temp<<lines[j];
        temp>>part1;
        temp>>part2;
        //cout<<"+++++++++++++++++"<<endl<<part1<<endl<<part2<<endl<<"++++++++++++++++++++++++++++"<<endl;
        files_changes = get_diff(part1,part2);
        //for(int i = 0; i < files_changes.size(); i++)cout<<files_changes[i]<<endl;
        //cout<<"sssssss"<<endl;
        for(int i = 0; i < files_changes.size(); i++){
            if(files_changes[i].size() > size_omgh){
                //cout<<files_changes[i]<<endl;
                flag = 0;
                for(int j = 0; j < size_omgh; j++){
                    if(files_changes[i][j] != omgh[j]){
                        j = size_omgh;
                        flag = 1;
                    }
                }
                if(flag == 0){
                    //cout<<files_changes[i]<<endl;
                    lines_javab.push_back(lines[j]);
                }
            }
        }
    }
    return lines_javab;
}
void print_change(vector<string> & lines,char options[26]){
    for(int i = 0; i < lines.size(); i++){
        cout<<lines[i]<<endl;
    }
}