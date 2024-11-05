#ifndef POKEMON_H
#define POKEMON_H
#include <string>
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
    
};

#endif 