#include <iostream>
using namespace std;

void servers();
void users();

int main(){
    cout<<endl;
    cout<<"Which type of user do you want to be :"<<endl;
    cout<<"(A)Server."<<endl;
    cout<<"(B)Normal user searching for websites."<<endl;
    char choice;
    cin>>choice;
    if(choice=='a' || choice=='A'){
        servers();
    }else if(choice=='b' || choice=='B'){
        users();
    }
    return 0;
}