#pragma once
#include "scene.h"
#include "editor.h"
#include "game.h"
#include <iostream>
#include <fstream>


class saving :
    public scene
{
public:
    static void saving::Saved(std::string fileName, std::string Filecontents);
    static void saving::Load(std::string fileName, int map[], Tile tileArray[]);
    

};
