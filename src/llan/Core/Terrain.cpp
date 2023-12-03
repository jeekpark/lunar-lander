/**
 * @file Terrain.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "llan/Core/Terrain.hpp"

namespace Llan
{
  Terrain::Terrain()
  {
    mTerrainHeights = std::vector<float>(10'000);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(1000.f, 1020.f);

    for (int i = 0; i < 10'000; ++i)
    {
      float randomHeight = dis(gen);
      mTerrainHeights[i] = randomHeight;
    }
    int mTerrainWidth = 10'000;
  }

  Terrain::~Terrain()
  {
    
  }

  float Terrain::getTerrainHeight(int x) const
  {
    if (0 <= x && x < mTerrainWidth)
    {
      return mTerrainHeights[x];
    }
    else
    {
      return -1.f;
    }
  }
}