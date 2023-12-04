/**
 * @file main.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "llan/Llan.hpp"
#include <cstdlib>

int main(const int, const char**)
{
  Llan::Core* game = new Llan::Core();
  game->run();
  delete game;
  return 0;
}