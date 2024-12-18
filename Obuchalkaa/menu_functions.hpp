#pragma once

#include "menu.hpp"

namespace Shkola{
    void show_menu(const MenuItem* current);


    void exit(const MenuItem* current);


    void study_summ(const MenuItem* current);
    void study_substract(const MenuItem* current);
    void study_multiply(const MenuItem* current);
    void study_go_back(const MenuItem* current);
}
