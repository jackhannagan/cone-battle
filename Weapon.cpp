#include<stdlib.h>
#include<iostream>
#include<random>

#include"Weapon.h"

//default
Weapon::Weapon(){
    name = "stick";
    damage = 5;
    durability = 15;
    critBuffer = 0;
}

//copy constructor
Weapon::Weapon(const Weapon &oldWeapon){
    name = oldWeapon.name;
    damage = oldWeapon.damage;
    durability = oldWeapon.durability;
    critBuffer = oldWeapon.critBuffer;

}

//regular constructor
Weapon::Weapon(string aName, int aDamage = 10, int aDurability = 5, int aCritBuffer = 2){
    name = aName;
    damage = aDamage%50; //max damage is 50
    durability = aDurability%10; //max durability is 10
    critBuffer = aCritBuffer;

    show();
}

int Weapon::rNum(int min, int max){
    random_device device;
    mt19937 generator(device());
    uniform_int_distribution<int> dist(min, max);
    return dist(generator);
}

int Weapon::critHit(){
    int random = rNum(1,10);
    //cout<<random<<endl;
    if (random<=critBuffer){
        return 20;
    }
    else return 0;
}

int Weapon::use(){
    if (durability ==0){
        cout<<name<<" just broke!"<<endl;
        return -1;
    }
    durability--;
    return damage + critHit();
}

string Weapon::getName(){
    return name;
}

void Weapon::show(){
    cout<<name<<" can deal "<< damage<< " damage and has "<< durability<< " uses remaining"<<endl;
}