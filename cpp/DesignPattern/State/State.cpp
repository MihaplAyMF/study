#include <iostream>
#include <memory>

class MainMenuState;

class State 
{
public:
    struct Context 
    {
        std::unique_ptr<State> state;

        template <typename T>
        void SetState() 
        {
            static_assert(std::is_base_of<State, T>::value, "T must inherit from State");
            state = std::make_unique<T>();
        }

        void Request() 
        {
            if (state) state->Handle(*this);
        }
    };

    virtual void Handle(Context& context) = 0;
    virtual ~State() = default;
};


class PlayState : public State 
{
public:
    void Handle(Context& context) override 
    {
        std::cout << "\nPlaying game...\n";
        context.SetState<MainMenuState>();
    }
};

class SettingsState : public State 
{
public:
    void Handle(Context& context) override 
    {
        std::cout << "\nSettings:\n - Sound: On\n - Difficulty: Medium\n";
        context.SetState<MainMenuState>();
    }
};

class ExitState : public State 
{
public:
    void Handle(Context&) override 
    {
        std::cout << "\nExiting game...\n";
    }
};

class MainMenuState : public State 
{
public:
    void Handle(Context& context) override 
    {
        std::cout << "\n--- Main Menu ---\n";
        std::cout << "1. Play\n2. Settings\n3. Exit\nChoose: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: context.SetState<PlayState>(); break;
            case 2: context.SetState<SettingsState>(); break;
            case 3: context.SetState<ExitState>(); break;
            default: std::cout << "Invalid choice\n";
        }
    }
};

int main()
{
    State::Context context;
    context.SetState<MainMenuState>();

    while (dynamic_cast<ExitState*>(context.state.get()) == nullptr) 
    {
        context.Request();
    }

    return 0;
}

