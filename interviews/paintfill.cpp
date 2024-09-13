#include <iostream>
#include <string>

using namespace std;

class Pixel
{
public:
    Pixel(string c = "white") : color{c}
    {
    }
    string getColor()
    {
        return this->color;
    }

    void setColor(string c)
    {
        this->color = c;
    }

private:
    string color;
};
void paintFill(Pixel **dispScr, int x, int y, int width, int height, string origColor, string newColor)
{
    if (x < 0 || y < 0 || x >= width || y >= height)
    {
        return;
    }
    if (dispScr[y][x].getColor() != origColor)
    {
        return;
    }

    dispScr[y][x].setColor(newColor);

    paintFill(dispScr, x - 1, y, width, height, origColor, newColor);
    paintFill(dispScr, x, y - 1, width, height, origColor, newColor);
    paintFill(dispScr, x + 1, y, width, height, origColor, newColor);
    paintFill(dispScr, x, y + 1, width, height, origColor, newColor);
}

int main()
{
    const int width = 5;
    const int height = 5;

    // Create a 2D array of Pixels
    Pixel **screen = new Pixel *[height];
    for (int i = 0; i < height; ++i)
    {
        screen[i] = new Pixel[width];
        for (int j = 0; j < width; ++j)
        {
            screen[i][j] = Pixel("white");
        }
    }

    // Set some pixels to a different color
    screen[1][1].setColor("blue");
    screen[1][2].setColor("blue");
    screen[2][1].setColor("blue");
    screen[2][2].setColor("blue");

    // Print the original screen
    cout << "Original screen:" << endl;
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            cout << screen[y][x].getColor() << " ";
        }
        cout << endl;
    }

    // Perform paint fill
    paintFill(screen, 1, 1, width, height, "blue", "red");

    // Print the modified screen
    cout << "\nAfter paint fill:" << endl;
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            cout << screen[y][x].getColor() << " ";
        }
        cout << endl;
    }

    // Clean up memory
    for (int i = 0; i < height; ++i)
    {
        delete[] screen[i];
    }
    delete[] screen;

    return 0;
}
