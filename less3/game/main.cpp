#include "library.hpp"
#include "Model_head.h"
#include "Model.h"

int main()
{
    Engine engine(700, 700);
    Model_head source;
    Model model(source.v_source, source.f_source, engine.width, engine.heights);

    engine.init("game", &engine.window, &engine.r);

    engine.full(&model);

    return 0;
}

// gonna leave it here just for future...

//    FILE * f = fopen("/home/lilu/lilu/cpp_games/cpp_games/less3/game/koko.txt", "r");
//    int val;
//    fscanf(f, "%d", &val);
//    bool succes = f !=nullptr;
//std::ifstream f("/home/lilu/lilu/cpp_games/cpp_games/less3/game/koko.txt");
//int v;
//f >> v;