#include "library.hpp"
#include "../../Model.h"
#include <GL/glew.h>

#include <SDL.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iostream>


Engine::Engine(int w, int h)
{
    width=w;
    heights=h;



    window = SDL_CreateWindow("  ",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              width,
                              heights,
                              SDL_WINDOW_OPENGL);


   r = SDL_CreateRenderer(window, -1, SDL_WINDOW_OPENGL);


}

void Engine::drawWindow(Model *model, bool isItGL)
{
    if(isItGL)
    {
        programID = initGL();
    }
    else{
        initSDL();
    }

    do
    {
        isItGL ? drawGLModel(programID) : drawSDLModel(model);
    }
    while( true) ;

}

void Engine::drawGLModel(GLuint programID)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(programID);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VAO);
    glVertexAttribPointer(
            0,
            3,                  // Размер
            GL_FLOAT,           // Тип
            GL_FALSE,           // Указывает, что значения не нормализованы
            0,                  // Шаг
            (void*)0            // Смещение массива в буфере
    );

    glDrawArrays(GL_TRIANGLES, 0, 3); // Начиная с вершины 0, всего 3 вершины -> один треугольник

    glDisableVertexAttribArray(0);

    SDL_GL_SwapWindow(window);
}
void Engine::initSDL()
{
    printVersionInfo();

    SDL_Init(SDL_INIT_VIDEO);
}
GLuint Engine::initGL()
{
    /*struct Point
    {
    public:
        float x;
        float y;

    };

    struct Triangle {
    public:
        Point v1;
        Point v2;
        Point v3;

    };

    Triangle triangle ={100,300,80, 100, 400, 150};
    std::vector<uint32_t> vect= {1,2,3};*/

    SDL_GL_CreateContext(window);

    glewExperimental=true;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "cannot identify GLEWn");
    }

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glClearColor(1.0, 0.5, 0.0, 1.0);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,24);


    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,3);

    GLuint programId = LoadShaders("/home/lilu/lilu/cpp_games/cpp_games/less3/game/vertexShader.txt",
                                   "/home/lilu/lilu/cpp_games/cpp_games/less3/game/fragmentShader.txt");



    //glBufferData(GL_ARRAY_BUFFER, 3 *sizeof(Point), &triangle, GL_STATIC_DRAW);

    /*glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,2,GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), reinterpret_cast<void *>(0));

    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, vect.size()* sizeof(std::vector<uint32_t>), vect.data(), GL_STATIC_DRAW);

    glBindVertexArray(VAO);
    glDrawElements(GL_LINES, 3, GL_UNSIGNED_INT,0);

//creating two shaders like in lection
    /*VertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader.txt, 1, &vs, nullptr);
    glCompileShader(vertexShader.txt);

    fragmentShader.txt = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader.txt, 1, &ps, nullptr);
    glCompileShader(fragmentShader.txt);*/



    printVersionInfo();
    return programId;
}
void Engine::printVersionInfo()
{
    SDL_version version = {0, 0, 0};
    SDL_GetVersion(&version);
    printf("SDL Version: %d.%d.%d, version.major, version.patch, version minor");
}


GLuint Engine::LoadShaders(const char * vertex_file_path,const char * fragment_file_path){

    // Создаем шейдеры
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    // Загружаем код Вершинного Шейдера из файла
    std::string VertexShaderCode = "#version 330 core\n"
                                   "layout(location = 0) in vec3 vertexPosition_modelspace;\n"
                                   "\n"
                                   "void main(){\n"
                                   "    gl_Position.xyz = vertexPosition_modelspace;\n"
                                   "    gl_Position.w = 1.0;\n"
                                   " }";
    /*
    std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
    if(VertexShaderStream.is_open())
    {
        std::stringstream sstr;
        sstr << VertexShaderStream.rdbuf();
        VertexShaderCode = sstr.str();
        VertexShaderStream.close();
    }*/

    // Загружаем код Фрагментного шейдера из файла
    std::string FragmentShaderCode = "#version 330 core\n"
                                     "out vec3 color;\n"
                                     "\n"
                                     "void main(){\n"
                                     "    color = vec3(0.5f,0,0.5f);\n"
                                     "}";

    /*std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
    if(FragmentShaderStream.is_open()){
        std::stringstream sstr;
        sstr << FragmentShaderStream.rdbuf();
        FragmentShaderCode = sstr.str();
        FragmentShaderStream.close();
    }*/

    GLint Result = GL_FALSE;
    int InfoLogLength;

    // Компилируем Вершинный шейдер
    printf("compiling vertex shader: %sn", vertex_file_path);
    char const * VertexSourcePointer = VertexShaderCode.c_str();
    glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
    glCompileShader(VertexShaderID);

    // Выполняем проверку Вершинного шейдера
    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
        glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        fprintf(stdout, "%sn", &VertexShaderErrorMessage[0]);
    }

    // Компилируем Фрагментный шейдер
    printf("compiling fragment shader: %sn", fragment_file_path);
    char const * FragmentSourcePointer = FragmentShaderCode.c_str();
    glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
    glCompileShader(FragmentShaderID);

    // Проверяем Фрагментный шейдер
    glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
        glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
        fprintf(stdout, "%s\n", &FragmentShaderErrorMessage[0]);
    }

    // Создаем шейдерную программу и привязываем шейдеры к ней
    fprintf(stdout, "creating shader program");
    GLuint ProgramID = glCreateProgram();
    glAttachShader(ProgramID, VertexShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    glLinkProgram(ProgramID);

    // Проверяем шейдерную программу
    glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
    glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> ProgramErrorMessage(InfoLogLength+1);
        glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        fprintf(stdout, "%s\n", &ProgramErrorMessage[0]);
    }

    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);

    return ProgramID;
}




void Engine::drawTriangle(SDL_Renderer **r, float x1, float y1, float x2, float y2, float x3, float y3)
{
  SDL_SetRenderDrawColor(*r, 255, 0, 0, SDL_ALPHA_OPAQUE);

  SDL_RenderDrawLine(*r,x1, y1, x2, y2);
  SDL_RenderDrawLine(*r,x1,y1,x3,y3);
  SDL_RenderDrawLine(*r, x2,y2,x3,y3);
  SDL_RenderPresent(*r);

}


void Engine::drawSDLModel(Model * model)
{

    for(int i=0; i<model->fvector.size();i++)
    {
        int x01 = model->vvector[model->fvector[i]->first]-> x;
        int y01 = model->vvector[model->fvector[i]->first]-> y;
        int x02 = model->vvector[model->fvector[i]->second]->x;
        int y02 = model->vvector[model->fvector[i]->second]->y;
        int x03 = model->vvector[model->fvector[i]->third]-> x;
        int y03 = model->vvector[model->fvector[i]->third]-> y;

        drawTriangle(&r,x01,y01,x02,y02,x03,y03);
    }

    destroyEngine(&window,&r);
}

void Engine::destroyEngine(SDL_Window **window, SDL_Renderer **renderer)
{
    SDL_Delay(7000);
    SDL_DestroyWindow(*window);
    SDL_Quit();
}

/*void Engine::checkForErrors()
{
    GLenum err(glGetError());
    while(err!=SDL_GL_CONTEXT_NO_ERROR)
    {
        std::string error;
        switch(err)
        {
            case GL_INVALID_OPERATION:error ="INVALID_FRAMEBUFFER_OPERATION";
            break;
            case GL_INVALID_ENUM:error = "INVALID_ENUM";
            break;
            case GL_INVALID_VALUE:error="OUT_OF_MEMORY";
            break;
            case GL_INVALID_FRAMEBUFFER_OPERATION:error ="INVALID_FRAMEBUFFER_OPERATOR";
            break;
            default:error = "UNKNOWN";
            break;
        }

        std::cerr<<"GL_"<<error<<": 0x"<<std::hex<<err<<std::dec<<"-"<<std::endl;
        err=glGetError();
    }*/
//}

