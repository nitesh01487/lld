#include <iostream>

using namespace std;

// Implementation of the Bridge Design Pattern for a navigation system
class Navigation {
public:
    virtual void navigateTo(string destination) = 0;
    virtual ~Navigation() = default;
};


class GoogleMaps : public Navigation {
public:
    void navigateTo(string destination) override {
        cout << "Navigating to " << destination << " using Google Maps." << endl;
    }
};

class AppleMaps : public Navigation {
public:
    void navigateTo(string destination) override {
        cout << "Navigating to " << destination << " using Apple Maps." << endl;
    }
};


class NavigationSystem {
protected:
    Navigation* navigation;

public:
    NavigationSystem(Navigation* nav) : navigation(nav) {}

    virtual void navigate(string destination) = 0;
    virtual void setNavigation(Navigation* nav) = 0;
};

class UberNavigationSystem : public NavigationSystem {
public:
    UberNavigationSystem(Navigation* nav) : NavigationSystem(nav) {}

    void navigate(string destination) override {
        navigation->navigateTo(destination);
    }

    void setNavigation(Navigation* nav) override {
        navigation = nav;
    }
};

class OlaNavigationSystem : public NavigationSystem {
public:
    OlaNavigationSystem(Navigation* nav) : NavigationSystem(nav) {}

    void navigate(string destination) override {
        navigation->navigateTo(destination);
    }

    void setNavigation(Navigation* nav) override {
        navigation = nav;
    }
};


int main() {
    Navigation* googleMaps = new GoogleMaps();
    Navigation* appleMaps = new AppleMaps();

    NavigationSystem* uberNav = new UberNavigationSystem(googleMaps);
    uberNav->navigate("Central Park");

    uberNav->setNavigation(appleMaps);
    uberNav->navigate("Times Square");

    delete googleMaps;
    delete appleMaps;
    delete uberNav;

    return 0;
}