// Lance Reyes ID: 5550001857
#ifndef MESA_CISC187_MAIN_H
#define MESA_CISC187_MAIN_H

#include <iostream>
#include <vector>
#include <string>
 
void full_display(std::vector<int> piles_vector);
void display_stones(int stone_number);
int subtract(int userInput,int updated_element, std::vector<int> &heap);
bool error_check(int input, int element, std::vector<int> &vector);
bool vector_check(std::vector<int> &vector ); 
std::string usage(const char* name);
std::string help(const char* name);


#endif
