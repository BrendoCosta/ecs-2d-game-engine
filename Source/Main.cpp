#include <Entity/Object.h>
#include <Entity/ObjectManager.h>
#include <Component/Vec2.h>
#include <System/Game.h>
#include <iostream>

int main(int argc, char* argv[])
{
    // clear && clang++ -g Main.cpp -std=c++20 Entity/Object.cpp Entity/ObjectManager.cpp System/Physics.cpp System/Game.cpp System/Movement.cpp System/Animation.cpp System/Renderer.cpp System/Image.cpp -I"./" -lSDL2main -lSDL2_image -lSDL2 -o Main && ./Main
    // valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./Main
    auto game = Project::System::Game();
    game.run();
    return 0;
}