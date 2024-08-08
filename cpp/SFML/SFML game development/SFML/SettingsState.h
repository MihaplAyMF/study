#pragma once

#include <array>
#include <memory>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include "State.h"
#include "Player.h"
#include "Container.h"
#include "Button.h"
#include "Label.h"

class SettingState : public State
{
public:
	SettingState(StateStack& stack, Context context);

	virtual bool handleEvent(const sf::Event& event);
	virtual bool update(sf::Time dt);
	virtual void draw();
	
private:
	void updateLabels();
	void addButtonLabel(std::size_t index, std::size_t x, std::size_t y, const std::string& text, Context context);

	sf::Sprite											mBackgroundSprite;
	GUI::Container										mGUIContainer;
	std::array<GUI::Button::Ptr, 2*PlayerAction::Count>	mBindingButtons;
	std::array<GUI::Label::Ptr, 2*PlayerAction::Count> 	mBindingLabels;

};