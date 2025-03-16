#include "ColaP/ColaP.hpp"

int main(){
    string command = " ";
    array P;
    ColaP S;
    int Cant;
    while(command != "TERMINATE"){
        cin >> command;
        if(command == "PUSHCOMMAND"){
            cin >> P.ID >> P.priority;
            getline(cin, P.Instruction);
            P.Instruction.erase(0,1);
            S.insertColaP(P);
            cout << S.sizeColaP() <<" PENDING\n";
        }
        if(command=="GET"){
            cin >> Cant;
            S.GET(Cant);
        }
    }
    cout<< S.total() - S.sizeColaP() << " SENT " << S.total() <<" CREATED\n"; 
    return 0;
}