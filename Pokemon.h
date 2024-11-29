#ifndef POKEMON_H
#define POKEMON_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class Pokemon
{
private:
    int PokemonIndexNum;
    string PokemonName;
public:
    Pokemon(){
        this->PokemonName = "None";
        this->PokemonIndexNum = 0;
    }
    Pokemon(int, string){
        this->setID(PokemonIndexNum);
        this->setName(PokemonName);
    }
    string getName(string){
        return PokemonName;
    }
    int getID(int){
        return PokemonIndexNum;
    }
    void setName(string name){
        name = this->PokemonName;
    }
    void setID(int number){
        number = this->PokemonIndexNum;
    }
   friend ostream& operator<<(ostream& output, const Pokemon& pokemon){
        output << "Pokemon #:" << pokemon.PokemonIndexNum << endl << "Pokemon Name:" << pokemon.PokemonName << endl;
    }
    friend bool operator<(const Pokemon& poke1, const Pokemon& poke2){
        return poke1.PokemonIndexNum < poke2.PokemonIndexNum;
    }
    friend bool operator==(const Pokemon& comparePokemon, const Pokemon& contrastPokemon){
        return comparePokemon.PokemonIndexNum == contrastPokemon.PokemonIndexNum;
    }
};

#endif 