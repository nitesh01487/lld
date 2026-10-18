#include <iostream>

using namespace std;


class Desktop
{
public:
    string motherboard;
    string processor;
    string memory;
    string storage;
    string graphicsCard;

    void display()
    {
        cout << "Desktop Specs:" << endl;
        cout << "Motherboard: " << motherboard << endl;
        cout << "Processor: " << processor << endl;
        cout << "Memory: " << memory << endl;
        cout << "Storage: " << storage << endl;
        cout << "Graphics Card: " << graphicsCard << endl;
    }
};

class DesktopBuilder
{
protected:
    Desktop desktop;
public:
    virtual DesktopBuilder &buildMotherboard() = 0;
    virtual DesktopBuilder &buildProcessor() = 0;
    virtual DesktopBuilder &buildMemory() = 0;
    virtual DesktopBuilder &buildStorage() = 0;
    virtual DesktopBuilder &buildGraphicsCard() = 0;
    Desktop getDesktop() {
        return desktop;
    }
};

class DellDesktopBuilder : public DesktopBuilder
{
public:
    DesktopBuilder &buildMotherboard() {
        desktop.motherboard = "Dell Motherboard";
        return *this;
    }

    DesktopBuilder &buildProcessor() {
        desktop.processor = "Dell Processor";
        return *this;
    }

    DesktopBuilder &buildMemory() {
        desktop.memory = "Dell Memory";
        return *this;
    }

    DesktopBuilder &buildStorage() {
        desktop.storage = "Dell Storage";
        return *this;
    }

    DesktopBuilder &buildGraphicsCard() {
        desktop.graphicsCard = "Dell Graphics Card";
        return *this;
    }
};

class HPDesktopBuilder : public DesktopBuilder
{
public:
    DesktopBuilder &buildMotherboard() {
        desktop.motherboard = "HP Motherboard";
        return *this;
    }

    DesktopBuilder &buildProcessor() {
        desktop.processor = "HP Processor";
        return *this;
    }

    DesktopBuilder &buildMemory() {
        desktop.memory = "HP Memory";
        return *this;
    }

    DesktopBuilder &buildStorage() {
        desktop.storage = "HP Storage";
        return *this;
    }

    DesktopBuilder &buildGraphicsCard() {
        desktop.graphicsCard = "HP Graphics Card";
        return *this;
    }
};

class DesktopDirector
{
public:
    Desktop buildDesktop(DesktopBuilder &builder) {
        return builder.buildMotherboard()
                      .buildProcessor()
                      .buildMemory()
                      .buildStorage()
                      .buildGraphicsCard()
                      .getDesktop();
    }
};

int main() {
    DellDesktopBuilder dellBuilder;
    DesktopDirector director;
    Desktop dellDesktop = director.buildDesktop(dellBuilder);
    dellDesktop.display();

    cout << endl;

    HPDesktopBuilder hpBuilder;
    Desktop hpDesktop = director.buildDesktop(hpBuilder);
    hpDesktop.display();

    return 0;
}