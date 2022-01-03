//
// Created by lilu on 22/12/2021.
//

#ifndef GAME_GLPARTICALBUFFER_H
#define GAME_GLPARTICALBUFFER_H
#include "ParticalBuffer.h"
#include <vector>

class glParticalBuffer :public ParticalBuffer
{
    explicit glParticalBuffer(std::vector <ParticalData> data);
    void draw();

private:
    uint32_t VAO;
    uint32_t VBO;
    uint32_t count;



};


#endif //GAME_GLPARTICALBUFFER_H
