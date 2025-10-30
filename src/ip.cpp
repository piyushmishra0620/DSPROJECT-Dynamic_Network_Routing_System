#include <iostream>
#include <cstdio>
#include <memory>
#include <array>
#include <string>
using namespace std;

string getLocalIPv4() {
    array<char, 128> buffer;
    string result;

    const char* command = 
        "powershell -Command \"(Get-NetIPAddress -AddressFamily IPv4 | "
        "Where-Object {$.IPAddress -notlike '169.*' -and $.IPAddress -ne '127.0.0.1'} | "
        "Select-Object -ExpandProperty IPAddress | Select-Object -First 1)\"";


    unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(command, "r"), _pclose);
    if (!pipe) {
        throw runtime_error("Failed to run PowerShell command");
    }

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    while (!result.empty() && (result.back() == '\n' || result.back() == '\r' || result.back() == ' '))
        result.pop_back();

    return result;
}
