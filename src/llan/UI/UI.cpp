/**
 * @file UI.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */



#include "llan/UI/UI.hpp"
#include "llan/common.hpp"
#include <sstream>

namespace Llan
{
	UI::UI()
	{
		mMainFont.loadFromFile(MAIN_FONT_PATH);

		mFlightAltitude.setFont(mMainFont);
		mVerticalVelocity.setFont(mMainFont);
		mHorizontalVelocity.setFont(mMainFont);

		mFlightAltitude.setCharacterSize(18);
		mVerticalVelocity.setCharacterSize(18);
		mHorizontalVelocity.setCharacterSize(18);

		mFlightAltitude.setFillColor(sf::Color::White);
		mVerticalVelocity.setFillColor(sf::Color::White);
		mHorizontalVelocity.setFillColor(sf::Color::White);
		
		mFlightAltitude.setPosition(10, 10);
		mVerticalVelocity.setPosition(10, 10 + 30);
		mHorizontalVelocity.setPosition(10, 10 + 60);
	}

	UI::~UI()
	{

	}

	void UI::setFlightAltitude(float flightAltitude)
	{
		std::stringstream ss;
		ss << "Flight altitude: " << std::fixed << std::setprecision(1) << flightAltitude;
		mFlightAltitude.setString(ss.str());
	}

	void UI::setVerticalVelocity(float verticalVelocity)
	{
		std::stringstream ss;
		ss << "Vertical speed: " << std::fixed << std::setprecision(1) << -verticalVelocity;
		mVerticalVelocity.setString(ss.str());
	}

	void UI::setHorizontalVelocity(float horizontalVelocity)
	{
		std::stringstream ss;
		ss << "Horizontal speed: " << std::fixed << std::setprecision(1) << horizontalVelocity;
		mHorizontalVelocity.setString(ss.str());
	}

	void UI::setThrustLevel(float thrustLevel)
	{

	}




	const sf::Text& UI::getFlightAltitude() const
	{
		return mFlightAltitude;
	}
	const sf::Text& UI::getVerticalVelocity() const
	{
		return mVerticalVelocity;
	}
	const sf::Text& UI::getHorizontalVelocity() const
	{
		return mHorizontalVelocity;
	}
	const sf::Image& UI::getThrustLevel() const
	{
		return mThrustLevel;
	}
}