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
    Pokemon(int num, string name){
        setName(name);
        setID(num);
    }
    string getName()const {
        return PokemonName;
    }
    int getID()const {
        return PokemonIndexNum;
    }
    void setName(string name){
        this->PokemonName = name;
    }
    void setID(int number){
        this->PokemonIndexNum = number;
    }
    friend ostream& operator<<(ostream& output, const Pokemon &pokemon){
        output << "Pokemon #:" << pokemon.PokemonIndexNum << endl << "Pokemon Name:" << pokemon.PokemonName << endl;
        return output;
    };

    bool operator<(const Pokemon& poke1){
    return this->PokemonIndexNum < poke1.PokemonIndexNum;
    }
    bool operator==(const Pokemon& comparePokemon){
        return this->PokemonIndexNum == comparePokemon.PokemonIndexNum;
    }
};

#endif 