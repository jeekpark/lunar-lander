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
    mTerrainHeights = std::vector<float>(100000);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(1000.f, 1001.5f);

    for (int i = 0; i < 100000; ++i)
    {
      float randomHeight = dis(gen);
      if (i > 10 && rand() % 5 == 0)
      {
        mTerrainHeights[i - 1] = randomHeight;
        mTerrainHeights[i - 2] = randomHeight;
        mTerrainHeights[i - 3] = randomHeight;
        mTerrainHeights[i - 4] = randomHeight;
        mTerrainHeights[i - 5] = randomHeight;
        mTerrainHeights[i - 6] = randomHeight;
      }
      mTerrainHeights[i] = randomHeight;
    }
    mTerrainWidth = 100000;
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