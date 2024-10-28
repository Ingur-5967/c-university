#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    int cellSize = 50;
    const int gridSize = 10;

    RenderWindow window(VideoMode(500, 500), "Cube");

    RectangleShape cells[gridSize][gridSize];

    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        for (int y = 0; y < gridSize; y++) {
            for (int x = 0; x < gridSize; x++) {
                cells[x][y].setSize(Vector2f(cellSize - 2, cellSize - 2));
                cells[x][y].setPosition(x * cellSize, y * cellSize);
                cells[x][y].setFillColor(Color::Black);
                cells[x][y].setOutlineColor(Color::White);
                cells[x][y].setOutlineThickness(1);

                if(x == y - (gridSize/2) || x < y - (gridSize / 2)) 
                    cells[x][y].setFillColor(Color::Green);

                window.draw(cells[x][y]);
            }
        

        }
        window.display();
    }

    return 0;
}