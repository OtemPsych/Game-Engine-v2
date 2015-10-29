#ifndef StateStack_H_
#define StateStack_H_

#include "State.h"

#include <memory>
#include <map>
#include <functional>

namespace gE
{
	class StateStack : private sf::NonCopyable
	{
	public:
		// Public Enum(s)
		enum Action { Push, Pop, Clear };
	private:
		// Private Typedef(s)
		using StatePtr = std::unique_ptr<State>;
		// Private Struct(s)
		struct PendingChange {
			explicit PendingChange(Action action, States::ID stateID = States::None);

			Action	   action;
			States::ID stateID;
		};
	private:
		// Private Member(s)
		std::vector<StatePtr>						    mStack;
		std::vector<PendingChange>					    mPendingList;

		std::map<States::ID, std::function<StatePtr()>> mFactories;
		sf::RenderWindow&								mWindow;

	private:
		// Private Method(s)
		StatePtr createState(States::ID stateID);
		void	 applyPendingChanges();
	public:
		// Constructor(s)
		explicit StateStack(sf::RenderWindow& window);
		// Public Method(s)
		void handleEvent(const sf::Event& event);
		void update(sf::Time dt);
		void draw();

		void pushState(States::ID stateID);
		void popState();
		void clearStates();

		template <typename T>
		void registerState(States::ID stateID);

		bool isEmpty() const;
	};
}
#include "StateStack.inl"
#endif