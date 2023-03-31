#include "SM.h"

namespace Retro {
	void SM::Addsref(sref newstate, bool replace) {
		this->add = true;
		this->_replace = replace;
		this->_newstate = std::move(newstate);
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
		}

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
	}
	sref& SM::GetCurrentState() {
		return this->_statestack.top();
	}
};