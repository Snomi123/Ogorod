#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

void Shkola::show_menu(const MenuItem* current){
    std::cout << "Обучайка приветствует тебя, мой юный ученик!" << std::endl;
    for (int i = 1; i < current->children_count; i++){
        std::cout << current->children[i]->title << std::endl;
    }
    std::cout << current->children[0]->title << std::endl;
    std::cout << "Обучайка > ";
    
}

void Shkola::exit(){
    std::exit(0);
}



void Shkola::study_summ(const MenuItem* current){
    // TODO
}
void Shkola::study_go_back(const MenuItem* current){
    // TODO
}
void Shkola::study_substract(const MenuItem* current){
    // TODO
}
void Shkola::study_multiply(const MenuItem* current){
    // TODO
}
