/**
 * @file Starship.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "llan/Core/Starship.hpp"

namespace Llan
{
  Starship::Starship()
  {
    mPosition = Vec2(WINDOW_X / 2.f, WINDOW_Y / 2.f);
    mDirection = Vec2(-1.f, 0.f);
    mVelocity = Vec2(0.f, 0.f);
  }

  Starship::~Starship()
  {

  }

  
}