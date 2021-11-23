#include "library.hpp"
#include "Model_head.h"
#include "Model.h"

int main()
{
    Engine engine(700, 700);
    Model_head source;
    Model model(source.v_source, source.f_source, engine.width, engine.heights);

    engine.init("game", &engine.window, &engine.r);

    model.flip_model(engine.heights/2);

    for(int i=0; i<model.fvector.size();i++)
    {
       int x01 = model.vvector[model.fvector[i]->first]-> x;
       int y01 = model.vvector[model.fvector[i]->first]-> y;
       int x02 = model.vvector[model.fvector[i]->second]->x;
       int y02 = model.vvector[model.fvector[i]->second]->y;
       int x03 = model.vvector[model.fvector[i]->third]-> x;
       int y03 = model.vvector[model.fvector[i]->third]-> y;

        engine.drawTriangle(&engine.r,x01,y01,x02,y02,x03,y03);
    }

    engine.destroyEngine(&engine.window,&engine.r);

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