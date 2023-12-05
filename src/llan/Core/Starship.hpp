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

#include "llan/Sound/Sound.hpp"

namespace Llan
{
  class Starship
  {
  public:
    Starship();
    ~Starship();

    void update(bool isCenterThrust, bool isLeftThrust, bool isRightThrust);

    Vec2 getPosition() const;
    Vec2 getDirection() const;
    Vec2 getVelocity() const;
    int getThrustLevel() const;
  private:
    const float m_cLunarAccelerationByTimeStep;
    const float m_cThrustAccelerationByTimeStep;
    const Vec2 m_cGravityDirection;
    Vec2 mPosition;
    Vec2 mVelocity;
    Vec2 mDirection;
    int mThrustLevel;
    
    Sound mThrustSound;

  };
}