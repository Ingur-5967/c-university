#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>
#include <cmath>

using namespace sf;
using namespace std;


void drawGraph(sf::RenderWindow& window, std::function<float(float)> func, float xMin, float xMax, float scaleX, float scaleY, sf::Color color) {
    sf::VertexArray graph(sf::LinesStrip);

    for (float x = xMin; x <= xMax; x += 0.1f) {
        float y = func(x); // Вычисление значения функции

        // Преобразование координат в экранные
        float screenX = 400 + x * scaleX;
        float screenY = 300 - y * scaleY;

        // Добавление точки в массив вершин
        graph.append(sf::Vertex(sf::Vector2f(screenX, screenY), color));
    }

    window.draw(graph);
}

string getSection(double x, double y) {

    if (y < x && y > (3 * abs(x) - 9)) 
        return "Section 1";

    if (y > x && y > (3 * abs(x) - 9)) 
        return "Section 2";

    if (y > x && (y < (3 * abs(x) - 9)) && x < 0) 
        return "Section 4";

    if (y > x && (y > (- 3 * abs(x) + 9))) 
        return "Section 3";

    return "None";
}


int main()
{
    RenderWindow window(sf::VideoMode(800, 600), "Graph control");

  
    CircleShape userPoint(5); 
    userPoint.setFillColor(Color::Red);
    bool userPointExists = false; 


    Font font;
    font.loadFromFile("arial.ttf");
    
    Text coordinatesText;
    coordinatesText.setFont(font);
    coordinatesText.setFillColor(Color::White);
    coordinatesText.setCharacterSize(20);
    coordinatesText.setPosition(10, 10);


    // Оси X и Y
    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = Vector2f(50, 300); // Начало оси X
    xAxis[0].color = Color::White; // Цвет оси
    xAxis[1].position = Vector2f(750, 300); // Конец оси X
    xAxis[1].color = Color::White;

    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(400, 50); // Начало оси Y
    yAxis[0].color = sf::Color::White; // Цвет оси
    yAxis[1].position = sf::Vector2f(400, 550); // Конец оси Y
    yAxis[1].color = sf::Color::White;

    while (window.isOpen()) {
        Event event;

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();


            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
          
                    Vector2i mousePos = Mouse::getPosition(window);

                    float mathX = (mousePos.x - 400) / 30.0f;
                    float mathY = -(mousePos.y - 300) / 90.0f;

                    userPoint.setPosition(mousePos.x - userPoint.getRadius(), mousePos.y - userPoint.getRadius());
                    userPointExists = true;

                    double normalizeYCoordinate = round(mathY * 10);
                    double normalizeXCoordinate = round(mathX);

                    double graphLiniar = normalizeXCoordinate;
                    double graphABS = 3 * abs(normalizeXCoordinate) - 9;

                    string specialPosition = "None";

                    if (normalizeYCoordinate == graphLiniar)
                        specialPosition = "Linear graph";

                    else if (normalizeYCoordinate == -graphABS || normalizeYCoordinate == graphABS) 
                        specialPosition = "ABS graph";


                    coordinatesText.setString("Coordinates: (" + std::to_string(mathX) + ", " + std::to_string(mathY) + ") Position: " + (getSection(normalizeXCoordinate, normalizeYCoordinate) + ";" + specialPosition));

                }
                  
            }
        }


        window.clear();

        // Отрисовка осей
        window.draw(xAxis);
        window.draw(yAxis);

        drawGraph(window, [](float x) { return x; }, -10, 10, 30, 10, sf::Color::Blue);

        drawGraph(window, [](float x) { return 3*abs(x) - 9; }, -10, 10, 30, 10, sf::Color::Red);

        if (userPointExists) {
            window.draw(userPoint);
            window.draw(coordinatesText);
        }

        window.display();
    }

    return 0;
}
