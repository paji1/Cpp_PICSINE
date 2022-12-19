#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <queue>
#include <string.h>
using namespace std;

static constexpr int ME = 1;
static constexpr int OPP = 0;
static constexpr int NONE = -1;


int width;
int height;

int x_him;
int y_him;

int my_matter;
int opp_matter;

// intial cords for center of my robots
int inisx;
int inisy;

int max_bfc;
int count_bfc;

#define UP 30
#define DOWN 31


#define FIRST 10
#define SECOND 11
#define FINAL 12
int state = FIRST;

// attack derction 1 or -1
int attack_direction;
int attack_direction_y;

int ddx[] = {-1, 0, 1, 0};
int ddy[] = {0, 1, 0, -1};
// derictions for bfs
int dx[] = {-1, 0, 0, 0};
int dy[] = {0, 1, 0, -1};struct visted
{
    int type;
    int viseted = 0;
};

struct Tile
{
    int x, y, scrap_amount, owner, units, grass = 0;
    bool recycler, can_build, can_spawn, in_range_of_recycler;
    ostream &dump(ostream &ioOut) const
    {
        ioOut << x << " " << y;
        return ioOut;
    }
};

ostream &operator<<(ostream &ioOut, const Tile &obj) { return obj.dump(ioOut); }
// all actions i neeed (MOVE , BUILD  , SPAWN, )




class vars 
{
    public:
    vector<string> actions;
    vector<Tile> tiles;
    vector<Tile> my_tiles;
    vector<Tile> opp_tiles;
    vector<Tile> neutral_tiles;
    vector<Tile> my_units;
    vector<Tile> opp_units;
    vector<Tile> my_recyclers;
    vector<Tile> opp_recyclers;
    vector<vector<Tile>> grid;
    vector<vector<visted>> vis;
    vars(int& turn)
    {
        turn++;
        grid.resize(height);
        vis.resize(height);
        tiles.reserve(width * height);

        cin >> my_matter >> opp_matter;
        cin.ignore();
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                int scrap_amount;
                int owner; // 1 = me, 0 = foe, -1 = neutral
                int units;
                int recycler;
                int can_build;
                int can_spawn;
                int in_range_of_recycler;
                cin >> scrap_amount >> owner >> units >> recycler >> can_build >> can_spawn >> in_range_of_recycler;
                cin.ignore();
                visted viss;
                Tile tile = {x, y, scrap_amount, owner, units, recycler == 1, can_build == 1, can_spawn == 1, in_range_of_recycler == 1};
                tiles.emplace_back(tile);

                grid[y].emplace_back(tile);
                vis[y].emplace_back(viss);
                if (tile.owner == ME)
                {
                    vis[y][x].viseted = 1;
                    my_tiles.emplace_back(tile);
                    if (tile.units > 0)
                    {
                        my_units.emplace_back(tile);
                    }
                    else if (tile.recycler)
                    {
                        my_recyclers.emplace_back(tile);
                    }
                }
                else if (tile.owner == OPP)
                {
                    vis[y][x].viseted = 0;
                    opp_tiles.emplace_back(tile);
                    if (tile.units > 0)
                    {
                        if (!turn)
                        {
                            x_him = tile.x;
                            y_him = tile.y;
                        }
                        opp_units.emplace_back(tile);
                    }
                    else if (tile.recycler)
                    {
                        vis[y][x].viseted = 1;

                        opp_recyclers.emplace_back(tile);
                    }
                }
                else if (tile.scrap_amount == 0)
                {
                    vis[y][x].viseted = 1;
                    tile.grass = 1;
                }
                else
                {
                    neutral_tiles.emplace_back(tile);
                }
            }
        }
    }
    void MOVE(int amount, Tile target, Tile robot)
    {
        ostringstream action;
        action << "MOVE " << amount << " " << robot << " " << target << ";";
        actions.emplace_back(
                        action.str()
                    );
    }
    void MOVE_ERR(int amount, Tile target, Tile robot)
    {
        cerr << "MOVE " << amount << " " << robot << " " << target << ";";
    }
    void BUILD(Tile tile)
    {
        ostringstream action;
        action << "BUILD " << tile << ";";
        actions.emplace_back(
                        action.str()
                    );
        actions.emplace_back(
                        action.str()
                    );
        my_matter -= 10;
    }
    void SPAWN(int amount, Tile tile)
    {
        ostringstream action;
        cout << "SPAWN " << amount << " " << tile << ";";
        actions.emplace_back(
                        action.str()
                    );
        my_matter -= amount;
    }
    void first_stage();
    void second_stage();
    void final_stage();

};


void vars::first_stage()
{
    BUILD(my_tiles.back());
}

void vars::second_stage()
{
    
}

void vars::final_stage()
{
    
}




int main()
{

    cin >> width >> height;
    cin.ignore();
    int turn = -1;

    // game loop
    while (1)
    {
        vars game(turn);
    
        game.first_stage();
        game.second_stage();
        game.final_stage();
        
        cerr << game.actions.back()<< endl;
        cout << "WAIT;";
        cout << endl;
    }
}
