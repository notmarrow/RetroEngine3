#pragma once
#include "appincludes.h"
#include "SM.h"
#include "AssetMan.h"
#include "InputMan.h"

namespace Retro {
	struct GData {
		SM statemachine;
		sf::RenderWindow window;
		AssetMan Asset;
		InputMan Input;
	};
	typedef std::shared_ptr<GData> GDref;
};