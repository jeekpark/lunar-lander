/**
 * @file UI.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "llan/common.hpp"

namespace Llan
{
	class UI
	{
	public:
		UI();
		~UI();

		void setFlightAltitude(float flightAltitude);
		void setVerticalVelocity(float verticalVelocity);
		void setHorizontalVelocity(float horizontalVelocity);
		void setThrustLevel(float thrustLevel);
		void setSafetyLanding(bool isSafetyLandingVelocity);

		const sf::Text& getFlightAltitude() const;
		const sf::Text& getVerticalVelocity() const;
		const sf::Text& getHorizontalVelocity() const;
		const sf::Image& getThrustLevel() const;
		const sf::Text& getSafetyLanding() const;
	private:
		sf::Font mMainFont;
		sf::Text mFlightAltitude;
		sf::Text mVerticalVelocity;
		sf::Text mHorizontalVelocity;
		//sf::Text mTotalVelocity;
		sf::Image mThrustLevel;
		sf::Text mSafetyLanding;
	};
}