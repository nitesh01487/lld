#include <iostream>

using namespace std;

class FoodItem
{
public:
    virtual void getDescription() = 0;
    virtual double getPrice() = 0;
    virtual ~FoodItem() = default;
};

class Pizza : public FoodItem
{
public:
    void getDescription() override {
        cout << "Pizza" << endl;
    }

    double getPrice() override {
        return 8.99;
    }
};

class Burger : public FoodItem
{
public:
    void getDescription() override {
        cout << "Burger" << endl;
    }

    double getPrice() override {
        return 5.99;
    }
};


class Decorator : public FoodItem
{
protected:
    FoodItem* foodItem;

public:
    Decorator(FoodItem* item) : foodItem(item) {}

    void getDescription() override {
        foodItem->getDescription();
    }

    double getPrice() override {
        return foodItem->getPrice();
    }
};


class ExtraCheeseDecorator : public Decorator
{
public:
    ExtraCheeseDecorator(FoodItem* item) : Decorator(item) {}

    void getDescription() override {
        foodItem->getDescription();
        cout << " with Cheese" << endl;
    }

    double getPrice() override {
        return foodItem->getPrice() + 2.99;
    }
};

class ExtraToppingsDecorator : public Decorator
{
public:
    ExtraToppingsDecorator(FoodItem* item) : Decorator(item) {}

    void getDescription() override {
        foodItem->getDescription();
        cout << " with Extra Toppings" << endl;
    }

    double getPrice() override {
        return foodItem->getPrice() + 3.99;
    }
};

class ExtraSauceDecorator : public Decorator
{
public:
    ExtraSauceDecorator(FoodItem* item) : Decorator(item) {}

    void getDescription() override {
        foodItem->getDescription();
        cout << " with Extra Sauce" << endl;
    }

    double getPrice() override {
        return foodItem->getPrice() + 1.99;
    }
};


int main() {
    FoodItem* pizza = new Pizza();
    pizza = new ExtraCheeseDecorator(pizza);
    pizza = new ExtraToppingsDecorator(pizza);
    // pizza = new ExtraSauceDecorator(pizza);

    cout << "Description: ";
    pizza->getDescription();
    cout << "Total Price: $" << pizza->getPrice() << endl;

    delete pizza;
    return 0;
}