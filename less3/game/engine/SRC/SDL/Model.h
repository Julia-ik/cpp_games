//
// Created by lilu on 21.11.2021.
//

#ifndef GAME_MODEL_H
#define GAME_MODEL_H
#include <vector>
#include "v_point.h"
#include "f_triangle.h"
#include <string>


class Model
{
public:
    std::vector<f_triangle*> fvector;
    std::vector<v_point*> vvector;

    Model(std::string v, std::string f, int width, int heights);
    void flip_model(int yCenter);

private:
    void convertFromStr(std::string v, std::string f, int width, int heights);
};

#endif //GAME_MODEL_H
