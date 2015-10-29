#include <cassert>

namespace gE {
		// Register State
	template <typename T>
	void StateStack::registerState(States::ID stateID)
	{
		mFactories[stateID] = [this]() {
			return StatePtr(new T(this, mWindow));
		};
	}
}