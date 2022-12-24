#include "Entity.hpp"
using namespace std;


// Constructor
Entity::Entity(int health) : the_health(health) 
{
    rand_attack();
    rand_defense();
}

// Destructor
//Entity::~Entity() {}

// Getters
int Entity::get_health() const { return the_health; }
int Entity::get_attack() const { return the_attack; }
int Entity::get_defense() const { return the_defense; }

// Setters
void Entity::set_health(int health) { the_health = health; }

// Function for generating a random attack value
void Entity::rand_attack() 
{
  the_attack = 1 + rand() % 3;
}

// Function for generating a random defense value
void Entity::rand_defense() 
{
  the_defense = 1 + rand() % 2;
}

