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
        cout << "Reading Pokemon" << endl;
        convertedPokeNum = to_string(pokeNum); //converts the int into a string for reading
        while(getline(openPokedex,convertedPokeNum, '#')){ // gets the converted number
            openPokedex.ignore();
            getline(openPokedex,pokeName, '#');// gets the pokemon name
            Pokemon pokemon = Pokemon(pokeNum, pokeName); // creates the pokemon
            cout << pokemon.getName(pokeName) << pokemon.getID(pokeNum) << endl; // prints out test case
            BT.insertNode(pokemon); // inserts in BT
            if(pokemon.getID(pokeNum) < pokemon.getID(pokeNum)){ // if Pokemon's index number is the same as another
                cout << "Inserting Pokemon with index" << pokemon.getID(pokeNum) << "into the Pokedex." << endl;
            }else{// if the node isn't empty
                cout << "Oops!, This Pokemon with index" << pokemon.getID(pokeNum) << "is already in the Pokedex." << endl;
            }
            numToDisplay++; // adding up the pokemon added in
        }
        cout << numToDisplay << "Pokemon have been added to the Pokedex." << endl;       
        BT.displayInOrder(); // prints out Pokedex
        openPokedex.close(); // closes the file
    }
    return 0;
}

