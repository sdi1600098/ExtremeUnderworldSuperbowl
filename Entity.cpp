#include "Entity.hpp"
#include <iostream>
using namespace std;


// Constructor
Entity::Entity(int health) : the_health(health) 
{
    rand_Attack();
    rand_Defense();
}

// Destructor
//Entity::~Entity() {}

// Getters
int Entity::getHealth() const { return the_health; }
int Entity::getAttack() const { return the_attack; }
int Entity::getDefense() const { return the_defense; }

// Setters
void Entity::setHealth(int health) { the_health = health; }

// Function for generating a random attack value
void Entity::rand_Attack() 
{
  the_attack = 1 + rand() % 3;
}

// Function for generating a random defense value
void Entity::rand_Defense() 
{
  the_defense = 1 + rand() % 2;
}

// Virtual functions
//void Entity::defend(int damage) = 0;
//void Entity::attack(Entity& target) = 0;
//void Entity::move(Grid& grid) = 0;

int the_health, the_attack, the_defense; // Entity's stats
