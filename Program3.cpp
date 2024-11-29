#include "Pokemon.h"
#include "BinaryTree.h"
#include <ostream>
#include <string>
#include <iostream>
using namespace std;

int main(){
   BinaryTree<Pokemon> BT;
   ifstream openPokedex;
   int pokeNum;
   string pokeName, convertedPokeNum;

   openPokedex.open("pokedex.txt");
   if(!openPokedex){
    return 1; // file not found
   }else{
        do{
            convertedPokeNum = to_string(pokeNum);
            getline(openPokedex,convertedPokeNum, '#');
            getline(openPokedex,pokeName, '#');
            Pokemon pokemon = Pokemon(pokeNum, pokeName);
            if(pokemon.getID(pokeNum) == pokemon.getID(pokeNum)){
                cout << "Oops!, This Pokemon with index" << pokemon.getID(pokeNum) << "is already in the Pokedex." << endl;
            }else{
                cout << "Inserting Pokemon with index" << pokemon.getID(pokeNum) << "into the Pokedex." << endl;
                insertNode(pokemon);
            }

        } while (!openPokedex.eof());
        openPokedex.close();
    }
    return 0;
}
