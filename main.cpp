// Peekaboo Game
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <windows.h>
using namespace sf;
using namespace std;

int size = 80;
int n = 10;
int m = 10;
int w = n * size;
int h = m * size;
int points = 0;

struct tile
{
    int x, y;
} t;

void tick()
{
    int a, b;
    a = rand() % n; b = rand() % m;
    t.x = a * size; t.y = b * size;
}

int main()
{
    // CONSOLE
    cout << "\n\n\tPEEKABOO GAME" << endl << "\n\n\tMADE IN SFML" << endl;
    cout << "You will have a time of ten seconds. try to capture most odd tiles to win the game with a high score" << endl;
    system("PAUSE");

    srand(time(NULL));
    Clock clock;
    RenderWindow window(VideoMode(w, h), "Peekaboo");

    RectangleShape background(Vector2f(800.0f, 800.0f));
    background.setFillColor(Color::Red);

    Texture t1, t2;
    t1.loadFromFile("images/button.png");
    t2.loadFromFile("images/peekaboo.png");

    Sprite button(t1);
    Sprite tile(t2);

    t.x = t.y = 0;

    int time = 0;

    while(window.isOpen())
    {
        Event e;
        while(window.pollEvent(e))
        {
            if(e.type == Event::Closed)
            {
                window.close();
            }
        }

        if(Mouse::isButtonPressed(Mouse::Left))
        {
            Vector2i mousePos = Mouse::getPosition(window);
            if(mousePos.x / 100 == t.x / 100 && mousePos.y / 100 == t.y / 100)
            {
                system("CLS");
                ++points;
                cout << "POINTS: " << points << endl;

                tick();
                tile.setPosition(t.x, t.y);
                window.draw(tile);
            }
        }
        
        // DRAW //
        window.draw(background);

        // Background tiles
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                button.setPosition(i * size, j * size);
                window.draw(button);
            }
        }

        // Peekaboo Tile
        tile.setPosition(t.x, t.y);
        window.draw(tile);
        window.display();

        // timer
        Time elapsed = clock.getElapsedTime();
        if((int)elapsed.asSeconds() > 10)
        {
            window.close();
        }

    }

    cout << "YOU HAVE SCORED: " << points << endl;
    system("PAUSE");
    
    return 0;
}