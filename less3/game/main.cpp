#include <cstdio>
#include "library.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

//#include <SDL_version.h>
class f_treugolnik
{
public:
    int pervaya;
    int vtoraya;
    int tretiya;

    f_treugolnik(int p, int v, int t)
    {
        pervaya =p;
        vtoraya = v;
        tretiya =t;
    }

};
class v_tochka
{
public:
    float x;
    float y;
    v_tochka(float x_file, float y_file)
    {
        x=x_file;
        y=y_file;
    }
};


int main()
{
    Engine engine;
    engine.init("game");

    std::vector<f_treugolnik> fvector;
    std::vector<v_tochka> vvector;



    std::ifstream in;
    in.open ("koko.txt", std::ifstream::in);
    if (in.fail())
    {
        printf("\ncould not open file");
    }
    /*face.open("engine/african_head.obj", std::ifstream::in);
    if (!face.is_open())
    {
        printf("\ncould not open file");
    }
    else
    {
        printf("\nfile is open");
    }*/



   /* for(int i=0;i<=fvector.size();i++)
    {
        int x01 = vvector[fvector[i].pervaya].x;
        int y01 = vvector[fvector[i].pervaya].y;
        int x02 = vvector[fvector[i].vtoraya].x;
        int y02 = vvector[fvector[i].vtoraya].y;
        int x03 = vvector[fvector[i].tretiya].x;
        int y03 = vvector[fvector[i].tretiya].y;

        engine.drawTriangle(x01,y01,x02,y02,x03,y03);

    }*/

    return 0;
}