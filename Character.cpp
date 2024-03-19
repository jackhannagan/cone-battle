#include<stdlib.h>
#include<iostream>
#include<random>

#include"Character.h"

/*Character::Character(){
    name = nullptr;
    health = 1;
    weapon = n;

}*/

Character::Character(string aName, int aHealth, Weapon aWeapon){
    name = aName;
    health = aHealth;
    weapon = aWeapon;

    show();

    if (name=="Lilly" || name =="Lillian" || name=="Lillian Pulaski"){
        health = 40;
    }

}


bool Character::attack(Character *defender){
    int currDamage = weapon.use();
    if (currDamage == -1){
        block(currDamage);
        cout<<"Uh Oh! -1 damage dealt towards self!"<<endl;
    }
    else{
        cout<<name<<" attacks with "<<weapon.getName()<< " and deals "<<currDamage<< " damage on "<< defender->name<<endl;
        defender->block(currDamage);
        if (defender->health == 0){
            kill(defender);
            return false;
        }  
    }
    show();
    defender->show();
    return true;
}

void Character::block(int damage){
    health -= damage;
    if (health<=0){ 
        health = 0;
    }
    //cout<<name<<" blocks with " << weapon.getName()<<endl;
}

void Character::kill(Character *deadOne){
    cout<<deadOne->name<<" just got killed by "<< name<<endl;
}

string Character::getName(){
    return name;
}
void Character::show(){
    cout<<name<<" has "<< weapon.getName()<<" and has "<< health<< " HP left"<<endl;
}
