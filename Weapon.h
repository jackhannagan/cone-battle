#include<stdlib.h>
#include<iostream>
#pragma once
using namespace std;

class Weapon{
    private:
        string name;
        int damage;
        int durability;
        int critBuffer; //each use will give a random number 1-10, and if the number is less than the buffer, there is a 20 point addition 
        
        int rNum(int min, int max);
        int critHit();

    public:
        Weapon();
        Weapon(const Weapon &oldWeapon);
        Weapon(string aName, int aDamage, int aDurability, int aCritBuffer);

        int use();

        string getName();
        void show();




};