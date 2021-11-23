//
// Created by lilu on 21.11.2021.
//

#include "Model.h"
#include <sstream>
#include <string>
#include <algorithm>
#include <iostream>

Model::Model(std::string v,std::string f, int width, int heights)
{
    Model::convertFromStr(v, f, width, heights);
}

void Model::convertFromStr(std::string v, std::string f, int width, int heights)
{
    std::istringstream iss;
    iss.str(v.c_str());
    char trash;
    std::string line;
    while (!iss.eof())
    {
        std::getline(iss, line);
        std::istringstream iss(line.c_str());
        char trash;

        if (!line.compare(0, 2, "v ")) {
            iss >> trash;
            std::vector<float> temp_v;
            while (iss) {
                float n;
                iss >> n;
                temp_v.push_back(n);
            }
            vvector.push_back(new v_point((temp_v[0]+1.)*width/2,
                                          (temp_v[1]+1.)*heights/2,
                                          temp_v[2]));
            temp_v.clear();
        }
    }


    std::istringstream s_iss;
    s_iss.str(f.c_str());
    std::string line_s;

    while (!s_iss.eof()) {
        std::getline(s_iss, line_s);
        std::istringstream s_iss(line_s.c_str());
        char trash;

        if (!line_s.compare(0, 2, "f ")) {
            int itrash, idx;
            s_iss >> trash;

            std::vector<int> temp_f;


            while (s_iss >> idx >> trash >> itrash >> trash >> itrash) {
                idx--;
                temp_f.push_back(idx);
            }
            fvector.push_back(new f_triangle(temp_f[0], temp_f[1], temp_f[2]));
            temp_f.clear();

        }
    }
}

void Model::flip_model(int yCenter)
{

    for(int i =0; i<vvector.size();i++)
    {
        vvector[i]->y < yCenter ?
            vvector[i]->y = (yCenter - vvector[i]->y) + yCenter:
                vvector[i]->y = yCenter - (vvector[i]->y - yCenter);
    }
}
