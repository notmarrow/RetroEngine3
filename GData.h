#pragma once
#include "appincludes.h"
#include "SM.h"
#include "AssetMan.h"
#include "InputMan.h"

namespace Retro {
	/*
		La estructura GData se usa para tener acceso a los elementos que serán necesarios a través del engine entero
		como lo que es la máquina de estados, la ventana principal, el assetmanager y el input manager
	*/
	struct GData {
		SM statemachine;
		sf::RenderWindow window;
		AssetMan Asset;
		InputMan Input;
	};
	typedef std::shared_ptr<GData> GDref; 
	/* 
		Se define un tipo de variable con un puntero a GData para referenciar de manera que el objeto se elimine 
		después de que acabe  el scope de su última llamada
	*/
};