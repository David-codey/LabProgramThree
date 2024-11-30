#include "BinaryTree.h"
using namespace std;

int main(){
   BinaryTree<Pokemon> BT;
   ifstream openPokedex;
   int pokeNum, numToDisplay = 0;
   string pokeName, convertedPokeNum;

    cout << "Opening Pokedex" << endl; // test case
   openPokedex.open("pokedex.txt");
   if(!openPokedex){ // file not found
    return 1; 
   }else{ // file found
    while(getline(openPokedex,convertedPokeNum, '#')){ // gets the converted number
        getline(openPokedex,pokeName, '#');// gets the pokemon name
        pokeNum = stoi(convertedPokeNum);
        Pokemon pokemon = Pokemon(pokeNum, pokeName); // creates the pokemon
            if(BT.searchNode(pokemon)){ // if Pokemon's index number is the same as another
                //BT.searchNode(pokemon); // searches the binary tree for similar nodes
                cout << "Inserting Pokemon with index " << pokemon.getID(pokeNum) << " into the Pokedex." << endl;
                BT.insertNode(pokemon);
            }else{// if the node isn't empty
                BT.searchNode(pokemon);
                cout << "Oops!, This Pokemon with index " << pokemon.getID(pokeNum) << " is already in the Pokedex." << endl;
                //BT.insertNode(pokemon); // inserts in BT
            }
            numToDisplay++; // adding up the pokemon added in
        }
        cout << numToDisplay << "Pokemon have been added to the Pokedex." << endl;       
        BT.displayInOrder(); // prints out Pokedex
        openPokedex.close(); // closes the file
    }
    return 0;
}

