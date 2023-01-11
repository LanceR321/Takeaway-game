//Lance Reyes (ID:5550001857)
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>

#include "main.h"

int main(int argc, char* argv[]) {
bool computer = false;
int pile_input;             // Temporary variable that holds the input of piles when -p is called.
int newPiles = 6;           // The amount of heaps in the game. Changed when -p is called and if pile_input is range.
int stone_input;            // Temporary variable that holds the input of stones when -s is called.
int stone_count = 0;        // Stores the input of the amount of stones when -s is called and if stone_input is in range. Otherwise stones will be randomized.

for (int l = 1; l <argc; ++l){

      if (strcmp(argv[l], "-h") == 0){
        std::cerr << help(*argv);
        break;
      } else if (strcmp(argv[l], "-c") == 0){
        
        computer = true;
      }

      else if (strcmp(argv[l], "-p") == 0) { 
        ++l;
               if( l < argc) {
                 
                  pile_input = std::atoi(argv[l]);

                  if (pile_input >= 1 && pile_input <= 10) {
                      newPiles = pile_input;
                    }

                  else{
                   std::cerr << "Input is invalid. The number of piles will be set at the default 6.\n";
                  }      
               }
            
         }
  
      else if (strcmp(argv[l], "-s") == 0) {  
        ++l;
                                              
          if (l < argc) {
      
              stone_input = std::atoi(argv[l]);

              if (stone_input >= 1 && stone_input <= 50) {
                 stone_count = stone_input;
                }

              else {
              std::cerr << "Input is invalid. The number of stones will be randomized. \n"; 
              } 
          }

   }

}// end of for loop for command lines

  std::cout << "Welcome to Take-away! \n";
  std::string player1;
  std::string player2;

  std::cout << "Name of player 1 \n";
  std::cin >> player1;


 if (computer == false) { 
  std::cout << "Name of player 2 \n";
  std::cin>> player2;

 }


  std::vector<int> piles(newPiles); 
  srand(time(0));                      // seeds a random number and uses ctime,was also used from thenewboston on youtube

int rematch = 1;

while (rematch == 1) {


// code below randomly sets the elements within the vector to below 30
// used a video by thenewboston to help randomly generate my number's 
//https://www.youtube.com/watch?v=naXUIEAIt4U&t=105s
// at 8:30- 9:00 I used the code on line 9 and line 12, it was also used for my computer player.

  int size = piles.size();
  for (int i  = 0; i < size; i++) {
    
    if (stone_count == 0) {

        piles[i] = rand() % 30; 

         if (piles[i] == 0) {     
        piles[i] = rand() % 30;
        }          
    }

    else{
      piles[i] = stone_count; 
    }

 }// end of for loop

  full_display(piles);


  bool winner1 = false;
  bool winner2 = false;
   
  while( winner1 != true || winner2 != true) { 


  bool valid1 = false; // checks if player 1 inputs are valid

  std::cout << player1 << "'s turn \n";
  int heap_identifier1;
  int subtract1;

        while ( valid1 != true) {

            std::cout<< "Enter a valid heap. \n";
            while (!(std::cin >> heap_identifier1)) {
                std::cerr << "Input not in range. Enter a valid heap. \n ";   // while loops to check inputs are not characters
                std::cin.clear();                                             // used a video by profgustin on youtube, timestamp 6:00, lines 12-16 of her code, used 4 times
                std::cin.ignore(100, '\n');                                   //https://www.youtube.com/watch?v=YIX7UhIKEIk 
                }

            std::cout<< "How many stones. \n";
            while (!(std::cin >> subtract1)) {
                std::cerr << "Input not in range. How many stones?  \n";
                std::cin.clear();
                std::cin.ignore(100, '\n');   
                }

           bool valid1  = error_check(subtract1,heap_identifier1, piles);

              if (valid1 == true) {
              break;
              }
           }



    winner1 = vector_check(piles); 
    if (winner1 == true) {
    std::cout << "Player 1 wins! \n";
    break;
    }
    
    std::cout << "\n";
    full_display(piles);




      if (computer == false) { 
      
        bool valid2 = false; // checks if player 2 inputs are valid
        std::cout << player2 << "'s turn \n";
        int heap_identifier2;
        int subtract2;
  
        
        while (valid2 != true) {
      
            std::cout<< "Enter a valid Heap \n";
            while (!(std::cin >> heap_identifier2)) {
                  std::cerr << "Input not in range. Enter a valid heap. \n";
                  std::cin.clear();
                  std::cin.ignore(100, '\n');   
                  }

            std::cout<< "How many stones. \n";
            while (!(std::cin >> subtract2)) {
                  std::cerr << "Input not in range. How many Stones?  \n";
                  std::cin.clear();
                  std::cin.ignore(100, '\n');   
                  }

            bool valid2 = error_check (subtract2, heap_identifier2, piles);

                if (valid2  == true) {
                break;
                }
            }
       } 


      if (computer == true) {
          int  computer_pile;   // computer selection for a heap
          int  computer_stones; // computer selection for stones
  
          std::cout << "Computer's turn. \n"; 

          computer_pile = rand() % 6; 
          while (piles[computer_pile] == 0) {
                computer_pile =  rand() % 6;
            }

          computer_stones = 1 + rand() % piles[computer_pile];
          std::cout << "The computer selects " << computer_stones << " stone(s) from heap " << computer_pile <<".\n";

          piles[computer_pile] = piles[computer_pile] - computer_stones;

      }




    winner2 = vector_check(piles); 
    if (winner2 == true) {
        
        if ( computer == false) {
        std::cout << "Player 2 wins! \n";
        }


        if (computer == true) {
        std::cout << "Computer  wins! \n";
        }

        break;
        }

    std::cout << "\n";
    full_display(piles);


              
} // end of while loop for player turns
  
    std::cout << "Rematch?" << " " << "If yes enter 1, if not enter any key. \n";
    std::cin >> rematch;
      } // end of while (rematch == 1)

std::cout << "Take-away has ended, Thanks for playing! \n";


return 0; 

}// end of main()










void full_display(std::vector<int> piles_vector) { // gives the full display of stones available
int size = piles_vector.size();
for (int i = 0; i < size; ++i) {

        if (piles_vector[i] != 0) {
              std::cout << "Heap " << i << " " << "[" << piles_vector[i] << "]" << ": "; 
              display_stones(piles_vector[i]);
              std::cout << std::endl;
              }
      }

 }


void display_stones(int stone_number) {   //function that only outputs the number in the element in stones
     for (int x = 0; x < stone_number; x++) {
      std::cout << "*";
     }         
}



int subtract(int userInput,int updated_element, std::vector<int>& heap) { //user input is the amount of stones they wish to take.
  heap[updated_element] = heap[updated_element] - userInput;              // updated_element is which heap, a player wants to take from.
  return heap[updated_element];
}


bool error_check(int input, int element, std::vector<int> &vector) { // only error checks for valid numbers.
int size = vector.size();                                            // element variable is which  heap.
                                                                    // input variable is the amount of stones a player wishes to take.

 if (element >=  0 && element <= size)  {     

          if (input >= 1 && input <= vector[element]) {
       
              vector[element] = subtract(input,element,vector);
              return true;
            }

          else { 
              std::cerr << "Number of stones requested is not in range! \n";
              return false;
            }        
        }

  else {
        std::cerr << "Heap is invalid or stones requested is invalid! \n";
        return false;
      }

} 




bool vector_check(std::vector<int> &vector) {
int size = vector.size();
int empty = 0;
    for (int i = 0; i < size; i++) {

           if ( vector[i] == 0) {
                 empty = empty + 1;              
               }
    }

  if ( empty == size) {
    return true;
    }

  else{
    return false;
  }

 } 


std::string usage(const char* name) {
  std::string output = "Usage: ";
  return output.append(name).append(" [-h] [-c] [-p # piles] [-s # stones] \n");
}


std::string help(const char* name) {
  auto output = usage(name);
    constexpr auto text = R"help_text(
      Options:
        -h   Show this text
        -c   Set player 2 as a computer.  Default = false.
        -p   Manually set the starting number of piles in the game.
        -s   Manually set the starting number of stones in the game.

        Max number of piles is 10. Default is 6.
        Max number of stones is 50. 

        )help_text";
  return output.append(text);
}


