#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

const Shkola::MenuItem* Shkola::show_menu(const MenuItem* current){
    std::cout << "Обучайка приветствует тебя, мой юный ученик!" << std::endl;
    for (int i = 1; i < current->children_count; i++){
        std::cout << current->children[i]->title << std::endl;
    }
    std::cout << current->children[0]->title << std::endl;
    std::cout << "Обучайка > ";
    
    int user_input;
    std::cin >> user_input;
    std::cout << std::endl;
    
    if (user_input >= 0 && user_input < current->children_count) {
        return current->children[user_input];
    }
    else {
        std::cout << "Неверно, попробуй ещё раз" << std::endl;
        return current;
    }
}

const Shkola::MenuItem* Shkola::exit(const MenuItem* current){
    std::exit(0);
}


const Shkola::MenuItem* Shkola::study_summ(const MenuItem* current){
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}
const Shkola::MenuItem* Shkola::study_divide(const MenuItem* current) {
    //TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}
const Shkola::MenuItem* Shkola::study_go_back(const MenuItem* current){
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}
const Shkola::MenuItem* Shkola::study_substract(const MenuItem* current){
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}
const Shkola::MenuItem* Shkola::study_multiply(const MenuItem* current){
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}
const Shkola::MenuItem* Shkola::first_grade_go_back(const MenuItem* current){
    return current->parent;
}
const Shkola::MenuItem* Shkola::first_grade_subjects(const MenuItem* current) {
    std::cout << "Выберите предмет для изучения в 1-ом классе:" << std::endl;
    return current->parent;
}
