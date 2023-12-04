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
#include "llan/Helper/Vec2.hpp"

namespace Llan
{
  Starship::Starship()
  : m_cLunarAccelerationByTimeStep(LUNAR_GRAVITY_ACCELERATION / FRAME_PER_SECOND)
  , m_cThrustAccelerationByTimeStep(LUNAL_MODULE_THRUST_ACCELERATION / FRAME_PER_SECOND)
  , m_cGravityDirection(Vec2(0.f, 1.f))
  {
    mPosition = Vec2(2000.f, 980.f);
    mDirection = Vec2(1.f, 0.f);
    mVelocity = Vec2(80.f, 0.f);
    mThrustLevel = 0;
  }

  Starship::~Starship()
  {

  }

  void Starship::update(bool isCenterThrust, bool isLeftThrust, bool isRightThrust)
  {
    if (mPosition.getY() > 999.5f)
    {
      mDirection = Vec2(0.f, -1.f);
      mVelocity = Vec2(0.f, 0.f);
      mPosition = Vec2(mPosition.getX(), 999.5f);
      mThrustLevel = 0;
      return;
    }
    if (isCenterThrust && mThrustLevel < 9) mThrustLevel++;
    else if (!isCenterThrust && mThrustLevel > 0) mThrustLevel--;

    mVelocity = mVelocity + m_cGravityDirection * m_cLunarAccelerationByTimeStep;
    if (isLeftThrust && !isRightThrust)
      mDirection = mDirection.rotate(0.05f);
    else if (isRightThrust && !isLeftThrust)
      mDirection = mDirection.rotate(-0.05f);
    if (isCenterThrust)
      mVelocity = mVelocity + mDirection * m_cThrustAccelerationByTimeStep;
    Vec2 deltaDistance = mVelocity * TIME_STEP_S;
    mPosition = mPosition + deltaDistance;
  }

  Vec2 Starship::getPosition() const
  {
    return mPosition;
  }

  Vec2 Starship::getDirection() const
  {
    return mDirection;
  }

  Vec2 Starship::getVelocity() const
  {
    return mVelocity;
  }
  
  int Starship::getThrustLevel() const
  {
    return mThrustLevel;
  }
}