#include <iostream>

// Interface Scroll Bar
class ScrollBar
{
public:
    virtual void draw() = 0;
    virtual ~ScrollBar() {}
};

// Interface Button
class Button
{
public:
    virtual void draw() = 0;
    virtual ~Button() {}
};

// Implement Light Scroll Bar
class LightScrollBar : public ScrollBar
{
public:
    void draw()
    {
        std::cout << "Light scroll bar." << std::endl;
    }
};

// Implement Light Button
class LightButton : public Button
{
public:
    void draw()
    {
        std::cout << "Light button." << std::endl;
    }
};

// Implement Dark Scroll Bar
class DarkScrollBar : public ScrollBar
{
public:
    void draw()
    {
        std::cout << "Dark scroll bar." << std::endl;
    }
};

// Implement Dark Button
class DarkButton : public Button
{
public:
    void draw()
    {
        std::cout << "Dark button." << std::endl;
    }
};

// Abstract Factory
class WidgetFactory
{
public:
    virtual ScrollBar* createScrollBar() = 0;
    virtual Button* createButton() = 0;
    virtual ~WidgetFactory() {}
};

// implement interface
class LightThemeWidgetFactory : public WidgetFactory
{
public:
    ScrollBar* createScrollBar()
    {
        return new LightScrollBar();
    }

    Button* createButton()
    {
        return new LightButton();
    }
};

class DarkThemeWidgetFactory : public WidgetFactory
{
public:
    ScrollBar* createScrollBar()
    {
        return new DarkScrollBar();
    }

    Button* createButton()
    {
        return new DarkButton();
    }
};


int main()

    // Light theme
    WidgetFactory* factory = new LightThemeWidgetFactory();

    ScrollBar* scrollBar = factory->createScrollBar();
    Button* button = factory->createButton();

    scrollBar->draw();
    button->draw();

    delete scrollBar;
    delete button;
    delete factory;

    // Dark theme
    factory = new DarkThemeWidgetFactory();

    scrollBar = factory->createScrollBar();
    button = factory->createButton();

    scrollBar->draw();
    button->draw();

    delete scrollBar;
    delete button;
    delete factory;

    return 0;
}
