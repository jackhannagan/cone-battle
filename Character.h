#include<stdlib.h>
#include<iostream>
#include"Weapon.h"
using namespace std;

class Character{
   
    private:
        string name;
        int health;
        Weapon weapon;

        void block(int damage);
        void kill(Character *deadOne);

    public:
        Character(string aName, int aHealth, Weapon aWeapon);
        
        bool attack(Character *defender);
        string getName();
        void show();
        
        


};