#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class Cell
{
private:
    std::string id;
    bool isEnd = false;
    std::vector<Cell *> neighborList;

public:
    Cell(const std::string &id) : id(id) {}

    std::string getId() const
    {
        return id;
    }

    const std::vector<Cell *> &getNeighborList() const
    {
        return neighborList;
    }

    void addNeighbor(Cell *neighbor)
    {
        neighborList.push_back(neighbor);
    }

    bool isEndCell() const
    {
        return isEnd;
    }

    void setIsEnd(bool end)
    {
        isEnd = end;
    }

    std::string toString() const
    {
        return id;
    }
};

bool findPath(Cell *current, std::vector<Cell *> &currentPath)
{
    currentPath.push_back(current);
    if (current->isEndCell())
    {
        return true;
    }

    for (Cell *neighbor : current->getNeighborList())
    {
        if (std::find(currentPath.begin(), currentPath.end(), neighbor) == currentPath.end())
        {
            std::vector<Cell *> neighborPath = currentPath;

            if (findPath(neighbor, neighborPath))
            {
                currentPath = neighborPath;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    // Create a simple maze
    Cell *start = new Cell("A");
    Cell *b = new Cell("B");
    Cell *c = new Cell("C");
    Cell *d = new Cell("D");
    Cell *end = new Cell("E");

    // Set up connections
    start->addNeighbor(b);
    start->addNeighbor(c);
    b->addNeighbor(d);
    c->addNeighbor(d);
    d->addNeighbor(end);

    // Set the end cell
    end->setIsEnd(true);

    // Find the path
    std::vector<Cell *> path;
    bool pathFound = findPath(start, path);

    // Print the result
    if (pathFound)
    {
        std::cout << "Path found: ";
        for (Cell *cell : path)
        {
            std::cout << cell->toString() << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "No path found." << std::endl;
    }

    // Clean up memory
    delete start;
    delete b;
    delete c;
    delete d;
    delete end;

    return 0;
}
