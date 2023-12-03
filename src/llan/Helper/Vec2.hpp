/**
 * @file Vec2.hpp
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
  class Vec2
  {
  public:
    Vec2(float x = 0.f, float y = 0.f) : mX(x), mY(y) {}

    float getX() { return mX; }
    float getY() { return mY; }

    void setX(float x) { mX = x; }
    void setY(float y) { mY = y; }

    Vec2 operator+(const Vec2& other) const { return Vec2(mX + other.mX, mY + other.mY); }
    Vec2 operator-(const Vec2& other) const { return Vec2(mX - other.mX, mY - other.mY); }
    Vec2 operator*(float scalar) const { return Vec2(mX * scalar, mY * scalar); }
    Vec2 operator/(float scalar) const { return Vec2(mX / scalar, mY / scalar); }

    float dot(const Vec2& other) const { return mX * other.mX + mY * other.mY; }
    float length() const { return std::sqrt(mX * mX + mY * mY); }
    float distance(const Vec2& other) const { return (*this - other).length(); }
    Vec2 normalize() const { return Vec2(mX / length(), mY / length()); }

  private:
    float mX;
    float mY;
  };
}
