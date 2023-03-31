#pragma once
#include "appincludes.h"
#include "Retro.h"

namespace Retro {
	typedef std::unique_ptr<State> sref;
	class SM {
	public:
		SM() {};
		~SM() {};
		
		void Addsref(sref newstate, bool replace = true);
		void Removesref();
		void ProcesssrefChange();

		sref& GetCurrentState();
	private:
		std::stack<sref> _statestack;
		sref _newstate;
		bool remove;
		bool add;
		bool _replace;
	};
};