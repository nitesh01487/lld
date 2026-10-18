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
    virtual void buildMotherboard() = 0;
    virtual void buildProcessor() = 0;
    virtual void buildMemory() = 0;
    virtual void buildStorage() = 0;
    virtual void buildGraphicsCard() = 0;
    Desktop getDesktop() {
        return desktop;
    }
};

class DellDesktopBuilder : public DesktopBuilder
{
public:
    void buildMotherboard() {
        desktop.motherboard = "Dell Motherboard";
    }

    void buildProcessor() {
        desktop.processor = "Dell Processor";
    }

    void buildMemory() {
        desktop.memory = "Dell Memory";
    }

    void buildStorage() {
        desktop.storage = "Dell Storage";
    }

    void buildGraphicsCard() {
        desktop.graphicsCard = "Dell Graphics Card";
    }
};

class HPDesktopBuilder : public DesktopBuilder
{
public:
    void buildMotherboard() {
        desktop.motherboard = "HP Motherboard";
    }

    void buildProcessor() {
        desktop.processor = "HP Processor";
    }

    void buildMemory() {
        desktop.memory = "HP Memory";
    }

    void buildStorage() {
        desktop.storage = "HP Storage";
    }

    void buildGraphicsCard() {
        desktop.graphicsCard = "HP Graphics Card";
    }
};

class DesktopDirector
{
public:
    Desktop buildDesktop(DesktopBuilder &builder) {
        builder.buildMotherboard();
        builder.buildProcessor();
        builder.buildMemory();
        builder.buildStorage();
        builder.buildGraphicsCard();
        return builder.getDesktop();
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