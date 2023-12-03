/**
 * @file Starship.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include "llan/common.hpp"

namespace Llan
{
  class Starship
  {
  public:
    Starship();
    ~Starship();

    void update();
  private:
    Vec2 mPosition;
    Vec2 mVelocity;
    Vec2 mDirection;
  };
}