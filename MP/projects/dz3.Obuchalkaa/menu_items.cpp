#include "menu_items.hpp"

#include <cstddef>
#include "menu_functions.hpp"


const Shkola::MenuItem Shkola::RUSSIAN_LANGUAGE = {
  "1 - русский язык", Shkola::study_russian_language, &Shkola::FIRST_GRADE
};
const Shkola::MenuItem Shkola::RUSSIAN_LITERATURE = {
  "2 - русская литература", Shkola::study_russian_literature, &Shkola::FIRST_GRADE
};
const Shkola::MenuItem Shkola::MATHEMATICS = {
  "3 - математика", Shkola::study_mathematics, &Shkola::FIRST_GRADE
};
const Shkola::MenuItem Shkola::PHYSICAL_EDUCATION = {
  "4 - физкультура", Shkola::study_physical_education, &Shkola::FIRST_GRADE
};
const Shkola::MenuItem Shkola::FIRST_GRADE_GO_BACK = {
  "0 - выйти в предыдущее меню", Shkola::go_back, &Shkola::FIRST_GRADE
};

namespace {
  const Shkola::MenuItem* const first_grade_children[] = {
      &Shkola::FIRST_GRADE_GO_BACK,
      &Shkola::RUSSIAN_LANGUAGE,
      &Shkola::RUSSIAN_LITERATURE,
      &Shkola::MATHEMATICS,
      &Shkola::PHYSICAL_EDUCATION
  };
  const int first_grade_size = sizeof(first_grade_children) / sizeof(first_grade_children[0]);
}

const Shkola::MenuItem Shkola::FIRST_GRADE = {
  "1 - изучать предметы 1-го класса", Shkola::show_menu, &Shkola::STUDY, first_grade_children, first_grade_size
};
const Shkola::MenuItem Shkola::SECOND_GRADE = {
  "2 - изучать предметы 2-го класса", Shkola::study_substract, &Shkola::STUDY
};
const Shkola::MenuItem Shkola::THIRD_GRADE = {
  "3 - изучать предметы 3-го класса", Shkola::study_multiply, &Shkola::STUDY
};
const Shkola::MenuItem Shkola::FOURTH_GRADE = {
  "4 - изучать предметы 4-го класса", Shkola::study_divide, &Shkola::STUDY
};
const Shkola::MenuItem Shkola::STUDY_GO_BACK = {
  "0 - главное меню", Shkola::go_back, &Shkola::STUDY
};

namespace {
  const Shkola::MenuItem* const study_children[] = {
      &Shkola::STUDY_GO_BACK,
      &Shkola::FIRST_GRADE,
      &Shkola::SECOND_GRADE,
      &Shkola::THIRD_GRADE,
      &Shkola::FOURTH_GRADE
  };
  const int study_size = sizeof(study_children) / sizeof(study_children[0]);
}

const Shkola::MenuItem Shkola::STUDY = {
  "1-предметы какого класса школы вы хотите изучать?", Shkola::show_menu, &Shkola::MAIN, study_children,study_size
};
const Shkola::MenuItem Shkola::EXIT = {
  "0-я уже закончил школу и все знаю", Shkola::exit, &Shkola::MAIN
};

namespace {
  const Shkola::MenuItem* const main_children[] = {
    &Shkola::EXIT,
    &Shkola::STUDY
  };
  const int main_size = sizeof(main_children) / sizeof(main_children[0]);
}

const Shkola::MenuItem Shkola::MAIN = {
  nullptr, Shkola::show_menu,nullptr, main_children, main_size
};


