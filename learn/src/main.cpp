#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <queue>
#include <iomanip>
#include <string.h>
using namespace std;

static constexpr int ME = 1;
static constexpr int OPP = 0;
static constexpr int NONE = -1;
int count_action = 0;

int width;
int height;

int my_matter;
int opp_matter;

// intial cords for center of my robots
int inisx;
int inisy;

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
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

// tyypes may i need

struct visted
{
    int parent_x = -2;
    int parent_y = -2;
    int viseted = -1;
};

struct Tile
{
    int x, y, scrap_amount, owner, units;
    bool recycler, can_build, can_spawn, in_range_of_recycler;
    int grass = 0;
    ostream &dump(ostream &ioOut) const
    {
        ioOut << x << " " << y;
        return ioOut;
    }
};

ostream &operator<<(ostream &ioOut, const Tile &obj) { return obj.dump(ioOut); }
// all actions i neeed (MOVE , BUILD  , SPAWN, )
class ACTION
{
public:
    static void MOVE(int amount, Tile target, Tile robot)
    {
        cout << "MOVE " << amount << " " << robot << " " << target << ";";
        count_action++;
    }
    static void MOVE_ERR(int amount, Tile target, Tile robot)
    {
        cerr << "MOVE " << amount << " " << robot << " " << target << ";";
    }
    static void BUILD(Tile tile)
    {
        cout << "BUILD " << tile << ";";
        count_action++;
    }
    static void SPAWN(int amount, Tile tile)
    {
        cout << "SPAWN " << amount << " " << tile << ";";
        count_action++;
    }
};
bool isValid(vector<vector<visted>> &vis,
             int x, int y)
{
    // If cell lies out of bounds
    if (x < 0 || y < 0 || y >= height || x >= width)
        return false;

    // If cell is already visited
    // if (vis[y][x].viseted)
    //     return false;

    // Otherwise
    return true;
}

#define YELLOW 3
#define BLUE 4
#define GREEN 5
#define NC -1

void set_color(int color, visted &vis)
{
    if (vis.viseted == NC && vis.viseted != GREEN)
        vis.viseted = color;
    else if (vis.viseted != color)
        vis.viseted = GREEN;
}

struct adj
{
    int x = -1, y = -1, parent = 0;
};

string color_get(vector<vector<visted>> vis, int i, int j)
{
    if (vis[i][j].viseted == NC)
        return  "N ";
    else if (vis[i][j].viseted == BLUE)
        return  "B ";
    else if (vis[i][j].viseted == GREEN)
        return  "G ";
    else if (vis[i][j].viseted == YELLOW)
        return  "Y ";
    else
        return  "p ";
}

void print_map(vector<vector<visted>> vis)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // cerr.width(14);
		    cerr << " ("<<vis[i][j].parent_x <<  " " << vis[i][j].parent_y << ") ";
            // cerr.width(1);
            // cerr <<  " (" << vis[i][j].parent_x << " ," << vis[i][j].parent_y << ") ";
        }
        cerr << endl;
    }
    cerr << endl;
}

bool cmp_x(Tile a, Tile b)
{
    return a.x < b.x;
}
bool cmp_x_r(Tile a, Tile b)
{
    return a.x > b.x;
}
bool cmp_y(Tile a, Tile b)
{
    return a.y > b.y;
}

void print_path(vector<vector<visted>> vis,vector<vector<Tile>> grid, Tile tile)
{

    visted temp;

    temp = vis[tile.y][tile.x];

    while (!(temp.parent_x == -1 && temp.parent_y == -1))
    {
        cerr << temp.parent_x << " " << temp.parent_y << " ;";
        temp = vis[temp.parent_y][temp.parent_x];
    }
    cerr << endl;

}




void BFS(vector<vector<Tile>> &grid, vector<vector<visted>> &vis,
         vector<Tile> &my_units, vector<Tile> &op_units)
{

    vector<Tile> colored;
    // Stores indices of the matrix cells
    queue<adj> my_q;
    queue<adj> op_q;

    sort(my_units.begin(), my_units.end(), cmp_x);
    sort(my_units.begin(), my_units.end(), cmp_y);
    for (Tile tile : my_units)
    {
        adj adjt;

        adjt.x = tile.x;
        adjt.y = tile.y;
        vis[adjt.y][adjt.x].parent_x = -1;
        vis[adjt.y][adjt.x].parent_y = -1;
        set_color(YELLOW, vis[tile.y][tile.x]);
        my_q.push(adjt);
    }

    sort(op_units.begin(), op_units.end(), cmp_x_r);
    sort(op_units.begin(), op_units.end(), cmp_y);
    for (Tile tile : op_units)
    {
        adj adjt;
        adjt.x = tile.x;
        adjt.y = tile.y;
        vis[adjt.y][adjt.x].parent_x = -1;
        vis[adjt.y][adjt.x].parent_y = -1;
        set_color(BLUE, vis[tile.y][tile.x]);
        op_q.push({adjt});
    }

    // Mark the starting cell as visited
    // and push it into the queue

    // Iterate while the queue
    // is not empty
    while (!my_q.empty() && !op_q.empty())
    {

        int x = my_q.front().x;
        int y = my_q.front().y;
        int parent = my_q.front().parent;

        int op_x = op_q.front().x;
        int op_y = op_q.front().y;
        int op_parent = op_q.front().parent;

        op_q.pop();
        my_q.pop();

        // Go to the adjacent cells

        for (int i = 0; i < 4; i++)
        {

            int adjx = op_x + ddx[i];
            int adjy = op_y + ddy[i];

            if (isValid(vis, adjx, adjy) && !grid[adjy][adjx].recycler && grid[adjy][adjx].grass != 1 && (vis[adjy][adjx].viseted == YELLOW || vis[adjy][adjx].viseted == NC))
            {
                adj adt;

                adt.x = adjx;
                adt.y = adjy;

                set_color(BLUE, vis[adjy][adjx]);
                if (vis[adjy][adjx].viseted != GREEN)
                {
                    op_q.push(adt);
                }
            }
            if (isValid(vis, adjx, adjy) && vis[adjy][adjx].viseted == GREEN && !(width % 2))
            {
                // cerr << grid[adjy][adjx] <<  "-----------  green  ---------" <<endl;
                colored.push_back(grid[adjy][adjx]);
                break;
            }
        }
        for (int i = 0; i < 4; i++)
        {

            int adjx = x + dx[i];
            int adjy = y + dy[i];

            if (isValid(vis, adjx, adjy) && !grid[adjy][adjx].recycler && grid[adjy][adjx].grass != 1 && (vis[adjy][adjx].viseted == BLUE || vis[adjy][adjx].viseted == NC))
            {
                adj adt;


                if (vis[adjy][adjx].parent_x == -2)
                {
                    vis[adjy][adjx].parent_x = x;
                    vis[adjy][adjx].parent_y = y;
                }
                if (vis[adjy][adjx].viseted != GREEN)
                    set_color(YELLOW, vis[adjy][adjx]);
                adt.x = adjx;
                adt.y = adjy;

                if (vis[adjy][adjx].viseted != GREEN)
                {
                    my_q.push(adt);
                }
            }
            if (isValid(vis, adjx, adjy) && vis[adjy][adjx].viseted == GREEN && (width % 2))
            {
                // cerr << grid[adjy][adjx] <<  "-----------  green  ---------" <<endl;
                colored.push_back(grid[adjy][adjx]);
                break;
            }
        }
    }
    print_map(vis);
    for (Tile tile : colored)
    {
        print_path(vis, grid, tile);
        // cerr << tile << endl;
    }
}

int main()
{

    cin >> width >> height;
    cin.ignore();
    int turn = -1;

    // game loop
    while (1)
    {
        turn++;
        count_action = 0;
        vector<Tile> tiles;
        vector<Tile> my_tiles;
        vector<Tile> opp_tiles;
        vector<Tile> neutral_tiles;
        vector<Tile> my_units;
        vector<Tile> opp_units;
        vector<Tile> my_recyclers;
        vector<Tile> opp_recyclers;
        vector<vector<Tile>> grid(height);
        vector<vector<visted>> vis(height);

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
                    opp_tiles.emplace_back(tile);
                    if (tile.units > 0)
                    {
                        opp_units.emplace_back(tile);
                    }
                    else if (tile.recycler)
                    {
                        opp_recyclers.emplace_back(tile);
                    }
                }
                else if (tile.scrap_amount == 0)
                {
                    tile.grass = 1;
                    grid[y][x].grass = 1;
                }
                else
                {
                    neutral_tiles.emplace_back(tile);
                }
                if (tile.recycler)
                    cerr << "sss " << tile << endl;
            }
        }

        // if (do_spawn(grid, my_tiles))

        BFS(grid, vis, my_units, opp_units);
        cout << "WAIT;";
        cout << endl;
    }
}
