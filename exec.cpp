#include "header.h"
std::string exec(std::string cmd)
{
    char buffer[512];
    string result = "";
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) return cmd+" f=ailed!";
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}