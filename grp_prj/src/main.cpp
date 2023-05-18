#include <iostream>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

#include "vec.hpp"
#include "mat.hpp"
#include "basic-engine.hpp"
#include "fuel-tank.hpp"

void DrawVec(sf::RenderTarget& target, sf::Color color, Vec theVec, Vec where) {
    sf::VertexArray a(sf::PrimitiveType::Lines, 2);
    a[0] = sf::Vertex(sf::Vector2f(where.x, where.y), color);
    a[1] = sf::Vertex(sf::Vector2f(where.x + theVec.x, where.y + theVec.y), color);
    target.draw(a);
}

class Rocket {
public:
    Rocket(double mass, Mat inertia, Vec pos, Vec vel,
            std::vector<BasicEngine*> engines, std::vector<FuelTank*> tanks) :
        mass(mass), inertia(inertia), pos(pos), vel(vel), engines(engines),
        tanks(tanks) {}

    Vec getPos() const { return pos; }
    Vec getVel() const { return vel; }

    void update(double dt) {
        pos = pos + vel * dt;
    }

private:
    double mass;
    Mat inertia;
    Vec pos;
    Vec vel;

    std::vector<BasicEngine*> engines;
    std::vector<FuelTank*> tanks;
};

class RocketRenderer {
public:
    RocketRenderer(Rocket& rocket) : rocket(rocket) {}


    void render(sf::RenderTarget& target) {
        DrawVec(target, sf::Color::Green, rocket.getVel(), rocket.getPos());
    }

private:
    Rocket& rocket;
};

int main() {
    Rocket rocket(1000, Mat(), Vec(400, 400, 0), Vec(25, 25, 0),
        std::vector<BasicEngine*>(), std::vector<FuelTank*>());

    RocketRenderer rocketRenderer(rocket);

    sf::RenderWindow window(sf::VideoMode(800, 800), "ROCKET SCIENCE");
    sf::Clock clock;

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            switch(event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        double dt = clock.getElapsedTime().asSeconds();
        clock.restart();

        rocket.update(dt);

        window.clear();
        rocketRenderer.render(window);
        window.display();
    }

    return 0;
}
