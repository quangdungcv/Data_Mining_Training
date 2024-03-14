#include <iostream>

using namespace std;
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
        cout << "Light scroll bar." << endl;
    }
};

// Implement Light Button
class LightButton : public Button
{
public:
    void draw()
    {
        cout << "Light button." << endl;
    }
};

// Implement Dark Scroll Bar
class DarkScrollBar : public ScrollBar
{
public:
    void draw()
    {
        cout << "Dark scroll bar." << endl;
    }
};

// Implement Dark Button
class DarkButton : public Button
{
public:
    void draw()
    {
        cout << "Dark button." << endl;
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
