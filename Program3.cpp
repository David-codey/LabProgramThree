#include "BinaryTree.h"
using namespace std;

int main(){
   BinaryTree<Pokemon> BT;
   ifstream openPokedex;
   int pokeNum, numToDisplay;
   string pokeName, convertedPokeNum;

   openPokedex.open("pokedex.txt");
   if(!openPokedex){
    return 1; // file not found
   }else{
        do{
            int numToCount = 0;
            convertedPokeNum = to_string(pokeNum);
            getline(openPokedex,convertedPokeNum, '#');
            getline(openPokedex,pokeName, '#');
            Pokemon pokemon = Pokemon(pokeNum, pokeName);
            BT.insertNode(pokemon);
            if(pokemon.getID(pokeNum) == pokemon.getID(pokeNum)){
                cout << "Oops!, This Pokemon with index" << pokemon.getID(pokeNum) << "is already in the Pokedex." << endl;
            }else{
                cout << "Inserting Pokemon with index" << pokemon.getID(pokeNum) << "into the Pokedex." << endl;
            }
            numToCount++;
            numToCount = numToDisplay;
            cout << numToCount << "Pokemon have been added to the Pokedex." << endl;
        } while (!openPokedex.eof());
        cout << numToDisplay << "Pokemon have been added to the Pokedex." << endl;
        openPokedex.close();
        BT.displayInOrder();
    }
    return 0;
}

