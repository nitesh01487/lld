#include <iostream>

using namespace std;

class Chair {
public:
    virtual void sitOn() = 0;
    virtual ~Chair() {}
};

class Sofa {
public:     
    virtual void lieOn() = 0;
    virtual ~Sofa() {}
};

class Table {
public:
    virtual void eatOn() = 0;
    virtual ~Table() {}
};

class ModernChair : public Chair {
public:
    void sitOn() override {
        cout << "Sitting on a modern chair." << endl;
    }
};

class ModernSofa : public Sofa {
public:
    void lieOn() override {
        cout << "Lying on a modern sofa." << endl;
    }
};

class ModernTable : public Table {
public:
    void eatOn() override {
        cout << "Eating on a modern table." << endl;
    }
};

class TraditionalChair : public Chair {
public:
    void sitOn() override {
        cout << "Sitting on a traditional chair." << endl;
    }
};

class TraditionalSofa : public Sofa {
public:
    void lieOn() override {
        cout << "Lying on a traditional sofa." << endl;
    }
};

class TraditionalTable : public Table {
public:
    void eatOn() override {
        cout << "Eating on a traditional table." << endl;
    }
};

class FurnitureFactory {
public:
    virtual Chair* createChair() = 0;
    virtual Sofa* createSofa() = 0;
    virtual Table* createTable() = 0;

    static FurnitureFactory* getFactory(const string& style);
};

class ModernFurnitureFactory : public FurnitureFactory {
public:
    Chair* createChair() override {
        return new ModernChair();
    }

    Sofa* createSofa() override {
        return new ModernSofa();
    }

    Table* createTable() override {
        return new ModernTable();
    }
};

class TraditionalFurnitureFactory : public FurnitureFactory {
public:
    Chair* createChair() override {
        return new TraditionalChair();
    }

    Sofa* createSofa() override {
        return new TraditionalSofa();
    }

    Table* createTable() override {
        return new TraditionalTable();
    }
};

FurnitureFactory* getFactory(const string& style) {
    if (style == "modern") {
        return new ModernFurnitureFactory();
    } else if (style == "traditional") {
        return new TraditionalFurnitureFactory();
    } else {
        return nullptr;
    }
}

int main() {
    FurnitureFactory* modernFactory = getFactory("modern");
    Chair* modernChair = modernFactory->createChair();
    Sofa* modernSofa = modernFactory->createSofa();
    Table* modernTable = modernFactory->createTable();

    modernChair->sitOn();
    modernSofa->lieOn();
    modernTable->eatOn();

    delete modernChair;
    delete modernSofa;
    delete modernTable;
    delete modernFactory;

    FurnitureFactory* traditionalFactory = getFactory("traditional");
    Chair* traditionalChair = traditionalFactory->createChair();
    Sofa* traditionalSofa = traditionalFactory->createSofa();
    Table* traditionalTable = traditionalFactory->createTable();

    traditionalChair->sitOn();
    traditionalSofa->lieOn();
    traditionalTable->eatOn();

    delete traditionalChair;
    delete traditionalSofa;
    delete traditionalTable;
    delete traditionalFactory;

    return 0;
}