#include <iostream>
#include "giaitoan.cpp"
using namespace std;
int main(int argv,char* argc[]){
    giaitoan objgaitoan;

    int tong=objgaitoan.tinhtong(3,4);
    cout<<"Tong"<<"="<<tong;
    return 0;
}