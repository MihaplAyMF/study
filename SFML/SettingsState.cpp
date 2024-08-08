#include <SFML/Graphics/RenderWindow.hpp>

#include "SettingsState.h"
#include "ResourceHolder.hpp"
#include "Utility.hpp"

SettingState::SettingState(StateStack& stack, Context context)
	: State(stack, context)
	, mGUIContainer()
{ 
	mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));
	for(std::size_t x = 0; x < 2; ++x)
	{
		addButtonLabel(PlayerAction::MoveLeft,		x, 0, "Move Left", context);
		addButtonLabel(PlayerAction::MoveRight,		x, 1, "Move Right", context);
		addButtonLabel(PlayerAction::MoveUp,		x, 2, "Move Up", context);
		addButtonLabel(PlayerAction::MoveDown,		x, 3, "Move Down", context);
		addButtonLabel(PlayerAction::Fire,			x, 4, "Fire", context);
		addButtonLabel(PlayerAction::LaunchMissile, x, 5, "Missile", context);
	}
	updateLabels();

	auto backButton = std::make_shared<GUI::Button>(context);
	backButton->setPosition(156.f, 475.f);
	backButton->setText("back");
	backButton->setCallback([this]()
	{
		requestStackPop();
	});

	mGUIContainer.pack(backButton);
}

bool SettingState::handleEvent(const sf::Event& event)
{
	bool isKeyBinding = false;

	for(std::size_t i = 0; i < 2 * PlayerAction::Count; ++i)
	{
		if(mBindingButtons[i]->isActive())
		{
			isKeyBinding = true;
			if(event.type == sf::Event::KeyReleased)
			{
				if(i < PlayerAction::Count)
					getContext().keys1->assignKey(static_cast<PlayerAction::Type>(i), event.key.code);
				else
					getContext().keys2->assignKey(static_cast<PlayerAction::Type>(i - PlayerAction::Count), event.key.code);

				mBindingButtons[i]->deactivate();
			}
			break;
		}
	}

	if(isKeyBinding)
		updateLabels();
	else
		mGUIContainer.handleEvent(event);

	return false;
}

bool SettingState::update(sf::Time dt)
{
	return true;
}

void SettingState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	
	window.draw(mBackgroundSprite);
	window.draw(mGUIContainer);
}

void SettingState::updateLabels()
{
	for(std::size_t i = 0; i < PlayerAction::Count; ++i)
	{
		auto action = static_cast<PlayerAction::Type>(i);

		// Get keys of both players
		sf::Keyboard::Key key1 = getContext().keys1->getAssignedKey(action);
		sf::Keyboard::Key key2 = getContext().keys2->getAssignedKey(action);

		// Assign both key strings to labels
		mBindingLabels[i]->setText(toString(key1));
		mBindingLabels[i + PlayerAction::Count]->setText(toString(key2));
	}
}

void SettingState::addButtonLabel(std::size_t index, std::size_t x, std::size_t y, const std::string& text, Context context)
{
	index += PlayerAction::Count * x;

	mBindingButtons[index] = std::make_shared<GUI::Button>(context);
	mBindingButtons[index]->setPosition(512.f * x + 156, 50.f * y + 150.f);
	mBindingButtons[index]->setText(text);
	mBindingButtons[index]->setToggle(true);

	mBindingLabels[index] = std::make_shared<GUI::Label>("", *context.fonts);
	mBindingLabels[index]->setPosition(512.f * x + 406, 50.f * y + 150.f);

	mGUIContainer.pack(mBindingButtons[index]);
	mGUIContainer.pack(mBindingLabels[index]);
}
