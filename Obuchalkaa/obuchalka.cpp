#include <clocale>
#include <iostream>

#include "menu.hpp"
#include "menu_functions.hpp"

int main() {
    std::setlocale(LC_ALL, "");
    
    
    Shkola::MenuItem study_summ = {"1 - Изучать предметы 1 класса", Shkola::study_summ};
    Shkola::MenuItem study_substract = {"2 - Изучать предметы 2 класса", Shkola::study_substract};
    Shkola::MenuItem study_multiply = {"3 - Изучать предметы 3 класса", Shkola::study_multiply};
    Shkola::MenuItem study_go_back = {"0 - Выйти в главное меню", Shkola::study_go_back};
    
    
    Shkola::MenuItem* study_children[] = {
        &study_go_back,
        &study_summ,
        &study_substract,
        &study_multiply
    };
    const int study_size = sizeof(study_children)/sizeof(study_children[0]);
    
    
    Shkola::MenuItem study = { "1 - Предметы какого класса вы хотите изучить?", Shkola::show_menu, study_children, study_size};
    Shkola::MenuItem exit = {"0 - Я уже закончил школу, и всё знаю :(", Shkola::exit};
    
    Shkola::MenuItem* main_children[] = { &exit, &study };
    const int main_size = sizeof(main_children)/sizeof(main_children[0]);
    
    Shkola::MenuItem main = { nullptr, Shkola::show_menu, main_children, main_size };
    
    main.func(&main);
    int user_input;
    do {
        std::cin >> user_input;
        std::cout << std::endl;
        
        main.children[user_input]->func(main.children[user_input]);
    } while (true);
    
    return 0;
    
}

