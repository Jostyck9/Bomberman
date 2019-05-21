#ifndef WALL_HPP
#define WALL_HPP

class Wall
{

private:
    bool _isBreakable;
    GraphicalElements _info_display;

public:
    IItem* createRandomItem();

    Wall(std::string& texture);
};

#endif
