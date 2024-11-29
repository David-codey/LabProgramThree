#include "BinaryTree.h"
using namespace std;

int main(){
   BinaryTree<Pokemon> BT;
   ifstream openPokedex;
   int pokeNum, numToDisplay = 0;
   string pokeName, convertedPokeNum;
    cout << "Opening Pokedex" << endl;
   openPokedex.open("pokedex.txt");
   if(!openPokedex){
    return 1; // file not found
   }else{
        cout << "Reading Pokemon" << endl;
        convertedPokeNum = to_string(pokeNum);
        while(getline(openPokedex,convertedPokeNum, '#')){
            openPokedex.ignore();
            convertedPokeNum = to_string(pokeNum);
            getline(openPokedex,convertedPokeNum, '#');
            getline(openPokedex,pokeName, '#');
            Pokemon pokemon = Pokemon(pokeNum, pokeName);
            cout << pokemon.getID(pokeNum) << pokemon.getName(pokeName) << endl;
            BT.insertNode(pokemon);
            if(pokemon.getID(pokeNum) == pokemon.getID(pokeNum)){
                cout << "Oops!, This Pokemon with index" << pokemon.getID(pokeNum) << "is already in the Pokedex." << endl;
            }else{
                cout << "Inserting Pokemon with index" << pokemon.getID(pokeNum) << "into the Pokedex." << endl;
            }
            numToDisplay++;
            cout << numToDisplay << "Pokemon have been added to the Pokedex." << endl;
        }
        openPokedex.close();
        //BT.displayInOrder();
    }
    return 0;
}

