/**
 * @file Core.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "llan/Core/Core.hpp"

namespace Llan
{
  Core::Core()
  : mWindow()
  , mWindowTitle("lunar-lander")
  {
    srand(time(NULL));
    mWindowTitle.append(LLAN_VERSION);
    mWindow.create(sf::VideoMode(WINDOW_X, WINDOW_Y), mWindowTitle);
    mWindow.setFramerateLimit(60);
    mWindow.clear();
  }

  Core::~Core()
  {

  }

  void Core::run()
  {
    while (mWindow.isOpen())
    {
      
    }
  }

  void Core::close()
  {
    mWindow.close();
  }
}