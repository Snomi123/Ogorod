#pragma once

#include "menu.hpp"

namespace Shkola{
    const MenuItem* show_menu(const MenuItem* current);

    const MenuItem* exit(const MenuItem* current);

    const MenuItem* study_summ(const MenuItem* current);
    const MenuItem* study_substract(const MenuItem* current);
    const MenuItem* study_multiply(const MenuItem* current);
    const MenuItem* study_divide(const MenuItem* current);
    const MenuItem* go_back(const MenuItem* current);

    const MenuItem* study_mathematics(const MenuItem* current);
    const MenuItem* study_russian_language(const MenuItem* current);
    const MenuItem* study_russian_literature(const MenuItem* current);
    const MenuItem* study_physical_education(const MenuItem* current);
}
