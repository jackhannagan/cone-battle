#include<stdlib.h>
#include<iostream>

#include"Weapon.h"
#include"Character.h"

using namespace std;

int main(){
    Weapon w1("deez nuts", 5, 2, 4);
    Character c1("Lillian Pulaski", 50, w1);

    Weapon w2("jojo siwa", 30, 5, 1);
    Character c2("Jack", 100, w2);
    
    while(1){
        string attacker, defender;
        cout<<"Input your attacker please:"<<endl;
        cin>>attacker;
        if (attacker == "quit" ){break;}



        bool continueFight;
        if (attacker == c1.getName()){
            continueFight = c1.attack(&c2);
        }
        else if (attacker == c2.getName()){
            continueFight = c2.attack(&c1);
        }
        else{
            cout<<"Uh oh, attacker is not recognized!"<<endl;
        }
            
        if (!continueFight){
            cout<<"Fight ended"<<endl;
            break;
        }

    }
    
}