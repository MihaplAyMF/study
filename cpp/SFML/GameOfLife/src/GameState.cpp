#include "GameState.h"
#include <cstdlib>
#include <imgui-SFML.h>

GameState::GameState(sf::RenderWindow& window)
    : mWindow(window)
    , mCellSize(5.f)
{
    cell.setSize(sf::Vector2f(10, 10));
    cell.setFillColor(sf::Color::White);
    cell.setPosition({300, 300}); 
    if(!ImGui::SFML::Init(mWindow))
        abort();
}

GameState::~GameState() 
{
    ImGui::SFML::Shutdown();
}

void GameState::handle(const sf::Event& event)
{
    ImGui::SFML::ProcessEvent(mWindow, event);
}

void GameState::update()
{    

}

void GameState::render()
{
    
    ImGui::SFML::Update(mWindow, deltaClock.restart());

    ImGui::SetNextWindowPos(ImVec2(10, 10), ImGuiCond_Always);  // Вказуємо координати
    ImGui::SetNextWindowSize(ImVec2(300, 200), ImGuiCond_Always);  // Розмір вікна
    
    ImGui::Begin("Settings", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);

    ImGui::SliderFloat("Cell Size", &mCellSize, 5.0f, 200.0f);

    cell.setSize(sf::Vector2f(mCellSize, mCellSize));

    ImGui::End();
    ImGui::SFML::Render(mWindow);
    mWindow.draw(cell);
}
