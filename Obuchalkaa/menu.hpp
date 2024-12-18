#pragma once

namespace Shkola{
    struct MenuItem{
        const char* const title;
        void (*func)();
    };
}
