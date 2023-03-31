#include "SM.h"

namespace Retro {
	void SM::Addsref(sref newstate, bool replace) {
		this->add = true;
		this->_replace = replace;
		this->_newstate = std::move(newstate);

		// A�ade un estado nuevo he indica si va a reemplazar al estado actual para el m�todo de procesamiento de estados
	}

	void SM::Removesref() { this->remove = true; }
	void SM::ProcesssrefChange()
	{
		if (this->remove && !this->_statestack.empty()) {
			this->_statestack.pop();
			if (!this->_statestack.empty()) {
				this->_statestack.top()->_unpause();
			}
			this->remove = false;
		} // Si se activa el booleano de remover, se quita el estado actual del stack

		if (this->add) {
			if (!this->_statestack.empty()) {
				if (this->_replace) {
					this->_statestack.pop();
				}
				else {
					this->_statestack.top()->_pause();
				}
			}
			this->_statestack.push(std::move(this->_newstate));
			this->_statestack.top()->_init();
			this->add = false;
		}
		/*
			Si se activa el booleano de a�adir, se checa si el stack esta vac�o, si no, se checa si se debe reemplazar
			el estado, si no, se pausa el estado actual, si s�, se quita del stack. Despu�s se a�ade el estado al stack
			y se activa el m�todo _init() del estado en la parte superior del stack.
		*/
	}
	sref& SM::GetCurrentState() {
		return this->_statestack.top();
	}
};