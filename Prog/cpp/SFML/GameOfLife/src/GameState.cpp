#include "GameState.h"
#include <cstdlib>
#include <imgui-SFML.h>

GameState::GameState(sf::RenderWindow& window)
    : mWindow(window)
    , mCellSizeOptions{16, 32, 64}
    , mSelectedCellSizeIndex(0)
    , mCellSize(16)
    , mGridWidth(768) 
    , mGridHeight(768)
    , mIsRunning(false)
{
    if(!ImGui::SFML::Init(mWindow))
        abort();
    
    cols = mGridWidth / mCellSize;
    rows = mGridHeight / mCellSize;

    grid.resize(cols, std::vector<bool>(rows, false));
    nextGrid = grid;
}

GameState::~GameState() 
{
    ImGui::SFML::Shutdown();
}

void GameState::handle(const sf::Event& event)
{
    ImGui::SFML::ProcessEvent(mWindow, event);

    if (event.is<sf::Event::MouseButtonPressed>())
    {
        const auto& mouseEvent = event.getIf<sf::Event::MouseButtonPressed>();
        int mouseX = mouseEvent->position.x - 256;
        int mouseY = mouseEvent->position.y;

        if (mouseX >= 0 && mouseX < mGridWidth && mouseY >= 0 && mouseY < mGridHeight)
        {
            int col = mouseX / mCellSize;
            int row = mouseY / mCellSize;
            grid[col][row] = !grid[col][row];
        }
    }

   
    if (event.is<sf::Event::KeyReleased>())
    {
        if (event.getIf<sf::Event::KeyReleased>()->scancode == sf::Keyboard::Scan::Escape)
        {
            mWindow.close();
        }
    }
}

void GameState::update()
{   
    if (!mIsRunning) return;
    
    for (int i = 0; i < cols; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            int neighbors = countNeighbors(i, j);
            if (grid[i][j])
            {
                nextGrid[i][j] = (neighbors == 2 || neighbors == 3);
            }
            else
            {
                nextGrid[i][j] = (neighbors == 3);
            }
        }
    }

    grid = nextGrid;
}

void GameState::render()
{   
    ImGui::SFML::Update(mWindow, deltaClock.restart());

    ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(256, 768), ImGuiCond_Always);

    ImGui::Begin("Settings", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);

    const char* items[] = {"16", "32", "64"};
    if (ImGui::Combo("Cell Size", &mSelectedCellSizeIndex, items, IM_ARRAYSIZE(items)))
    {
        mCellSize = mCellSizeOptions[mSelectedCellSizeIndex];
        cols = mGridWidth / mCellSize;
        rows = mGridHeight / mCellSize;
        grid.assign(cols, std::vector<bool>(rows, false));
        nextGrid.assign(cols, std::vector<bool>(rows, false));
    }

    if (ImGui::Button(mIsRunning ? "Pause" : "Start"))
    {
        mIsRunning = !mIsRunning;
    }

    ImGui::End();

    drawGrid();

    ImGui::SFML::Render(mWindow);
}

void GameState::drawGrid()
{
    sf::RectangleShape cellShape;
    cellShape.setSize(sf::Vector2f(mCellSize - 1, mCellSize - 1));
    cellShape.setOutlineThickness(1);
    cellShape.setOutlineColor(sf::Color(200, 200, 200));

    for (int i = 0; i < cols; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            cellShape.setFillColor(grid[i][j] ? sf::Color::White : sf::Color::Black);
            cellShape.setPosition({256 + i * mCellSize, j * mCellSize});
            mWindow.draw(cellShape);
        }
    }
}

int GameState::countNeighbors(int x, int y)
{
    int count = 0;
    for (int dx = -1; dx <= 1; ++dx)
    {
        for (int dy = -1; dy <= 1; ++dy)
        {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < cols && ny >= 0 && ny < rows)
            {
                count += grid[nx][ny];
            }
        }
    }
    return count;
}
