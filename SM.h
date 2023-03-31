#pragma once
#include "appincludes.h"
#include "Retro.h"

namespace Retro {
	/*
		La clase SM contiene a la máquina de estados, la cual controla los distintos estados del juego y permite
		cambiar entre ellos y utilizarlos en el loop principal
	*/
	typedef std::unique_ptr<State> sref; // Tipo de variable que mantendrá un objeto de tipo estado
	class SM {
	public:
		SM() {};
		~SM() {};
		
		void Addsref(sref newstate, bool replace = true);
		void Removesref();
		void ProcesssrefChange(); // Método que nos permitirá cambiar de estados de ser necesario

		sref& GetCurrentState();
	private:
		std::stack<sref> _statestack; // Stack en el que se guardan los estados
		sref _newstate;
		bool remove;
		bool add;
		bool _replace;
	};
};