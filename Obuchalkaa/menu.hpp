#pragma once

namespace Shkola{
    struct MenuItem{
        const char* const title;
        void (*func)(const MenuItem* current);
        
        const MenuItem* const *children;
        const int children_count;
    };
}
