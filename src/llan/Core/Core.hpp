/**
 * @file Core.hpp
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
  class Core
  {
  public:
    Core();
    ~Core();
    void run();
    void close();
  private:
    sf::RenderWindow mWindow;
    std::string mWindowTitle;
  };
}