#include <iostream>
#include <vector>

using namespace std;

class Product {
public:
    Product(const string& name, double price) : name(name), price(price) {}

    string getName() const { return name; }
    double getPrice() const { return price; }
private:
    string name;
    double price;
};

class Iterator {
public:
    virtual ~Iterator() {}
    virtual bool hasNext() const = 0;
    virtual Product* next() = 0;
    virtual Product* first() = 0;
};

class ProductIterator : public Iterator {
public:
    ProductIterator(const vector<Product*>& products) : products(products), index(0) {}

    bool hasNext() const override {
        return index < products.size();
    }

    Product* next() override {
        if (hasNext()) {
            return products[index++];
        }
        throw out_of_range("No more products.");
    }

    Product* first() override {
        index = 0;
        if (hasNext()) {
            return products[index];
        }
        return NULL; // Return a default value or handle the case when there are no products
    }

private:
    const vector<Product*> products;
    size_t index;
};


class ProductCollection {

    vector<Product*> products;
public:
    void addProduct(Product* product) {
        products.push_back(product);
    }

    Iterator* createIterator() const {
        return new ProductIterator(products);
    }
};

int main() {

    Product *product1 = new Product("Laptop", 999.99);
    Product *product2 = new Product("Smartphone", 499.99);
    Product *product3 = new Product("Tablet", 299.99);

    ProductCollection collection;
    collection.addProduct(product1);
    collection.addProduct(product2);
    collection.addProduct(product3);

    Iterator* iterator = collection.createIterator();
    for (Product* product = iterator->first(); product != NULL && iterator->hasNext(); ) {
        cout << "Product: " << product->getName() << ", Price: $" << product->getPrice() << endl;
        product = iterator->next();
    }

    delete product1;
    delete product2;
    delete product3;
    delete iterator;
    return 0;
}