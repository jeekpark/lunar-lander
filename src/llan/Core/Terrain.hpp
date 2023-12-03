/**
 * @file Terrain.hpp
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
  class Terrain
  {
  public:
    Terrain();
    ~Terrain();

    float getTerrainHeight(int x) const;
  private:
    std::vector<float> mTerrainHeights;
    int mTerrainWidth;
  };
}