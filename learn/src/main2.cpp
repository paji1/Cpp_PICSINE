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
int count_action= 0;

int width;
int height;

int my_matter;
int opp_matter;

// intial cords for center of my robots
int inisx;
int inisy;

// attack derction 1 or -1
int attack_direction;
int attack_direction_y;

int ddx[] = {-1, 0 , 1, 0};
int ddy[] = {0 , 1, 0 ,-1};
// derictions for bfs
int dx[] = { -1, 0, 0, 0 };
int dy[] = { 0, 1, 0, -1 };

// tyypes may i need
#define REC 3;
#define OP_UNIT 4; 
#define MY_UNIT 5; 
#define EMPTY_CELL 6; 
#define OP_CELL 7; 
#define MY_CELL 8; 
#define GRASS 9; 


struct visted
{
	int type;
	int viseted = 0;
};

struct Tile {
    int x, y, scrap_amount, owner, units, grass;
    bool recycler, can_build, can_spawn, in_range_of_recycler;
        ostream& dump(ostream& ioOut) const {
        ioOut << x << " " << y;
        return ioOut;
    }
};

ostream& operator<<(ostream& ioOut, const Tile& obj) { return obj.dump(ioOut); }
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
float distance_p(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}

bool com_on_far_x(Tile a, Tile b)
{
    int x;
    int y;
    if (attack_direction == -1)
    {
        x = 0;
        y = height / 2;
    }
    if (attack_direction == 1)
    {
        x = width;
        y = height / 2;
    }
    return distance_p(x,y, a.x, a.y) <= distance_p(x,y, b.x, b.y);
}
bool com_on_far_x_r(Tile a, Tile b)
{
    int x;
    int y;
    if (attack_direction == 1)
    {
        x = 0;
        y = height / 2;
    }
    if (attack_direction == -1)
    {
        x = width;
        y = height / 2;
    }
    return distance_p(x,y, a.x, a.y) <= distance_p(x,y, b.x, b.y);
}
// Function to check if a cell
// is be visited or not
bool isValid(vector<vector<visted>>& vis,
             int x, int y)
{
    // If cell lies out of bounds
    if (x < 0 || y < 0
        || y >= height || x >= width)
        return false;
 
    // If cell is already visited
    // if (vis[y][x].viseted)
    //     return false;
 
    // Otherwise
    return true;
}
bool isValid2(vector<vector<visted>>& vis,
             int x, int y)
{
    // If cell lies out of bounds
    if (x < 0 || y < 0
        || y >= height || x >= width)
        return false;
 
    // If cell is already visited
    if (vis[y][x].viseted)
        return false;
 
    // Otherwise
    return true;
}
class cord
{
    int x;
    int y;
};
bool is_build(vector<vector<Tile>>& grid, Tile tile)
{
    for (int i = 0; i < 4; i++) 
    {
 
    int adjx = tile.x + ddx[i];
    int adjy = tile.y + ddy[i];
    vector<vector<visted>> l;
    if (isValid(l, adjx, adjy) && tile.units == 0 && tile.owner == 1 && grid[adjy][adjx].owner == 0 && (grid[adjy][adjx].units >= 1 && !grid[adjy][adjx].recycler))
    {
        grid[adjy][adjx].recycler = 1;
        return true;
    }
    return false;
    }
}
int do_build (vector<vector<Tile>> &grid, vector<Tile> tiles)
{
    int i = 0;
    sort(tiles.begin(), tiles.end(), com_on_far_x_r);
    for (Tile tile : tiles)
    {
        bool should_move = my_matter > 10; // TODO: pick whether to move units from here
        if (should_move)
        {
            int amount = 0; // TODO: pick amount of units to move

            if (is_build(grid, tile))
            {
                i = 1;
                ACTION::BUILD(tile);
                my_matter -= 10;
            }
        }
    }
    return i;
}
int get_empty_cels(vector<vector<Tile>>& grid, vector<vector<visted>>& vis, Tile tile)
{
    int count = 0;

    for (int i = 0; i < 4; i++) 
    { 
        int adjx = tile.x + dx[i];
        int adjy = tile.y + dy[i];

        if (isValid(vis, adjx, adjy) && grid[adjy][adjx].owner != 1 && vis[adjy][adjx].viseted != 1) {
            count++;
        }
    }
    int can_spawn = my_matter / 10; 
    if (can_spawn - count >= 0)
        return count;
    else
        return  0;
}
// int do_spawn(vector<vector<Tile>>& grid, vector<vector<visted>>& vis, Tile tile)
// {

// }


// Function to perform the BFS traversal
int BFS_tocheck_end(vector<vector<Tile>> grid, vector<vector<visted>> vis,
         int x_r, int y_r)
{
	Tile tile;

	tile.x = x_r;
	tile.y = y_r;
    // Stores indices of the matrix cells
    queue<pair<int, int> > q;
 
    // Mark the starting cell as visited
    // and push it into the queue
    q.push({x_r, y_r});
    vis[y_r][x_r].viseted = true;
 
    // Iterate while the queue
    // is not empty
    while (!q.empty()) {
 
        pair<int, int> cell = q.front();
        int x = cell.first;
        int y = cell.second;
 
		
        cerr << x << "hello " << endl;
		if (x == width - 1)
		{
       		return 1;
		}
        q.pop();
        // Go to the adjacent cells
        for (int i = 0; i < 4; i++) {
 
            int adjx = x + ddx[i];
            int adjy = y + ddy[i];
 
            if (isValid(vis, adjx, adjy)) {
                q.push({ adjx, adjy });
            }
        }
    }
    return 0;
}
// Function to perform the BFS traversal
void BFS(vector<vector<Tile>>& grid, vector<vector<visted>>& vis,
         int x_r, int y_r, vector<Tile>& my_units)
{
	Tile tile;

    int count = -1;
	tile.x = x_r;
	tile.y = y_r;
    tile.units = grid[tile.y][tile.x].units;
    // Stores indices of the matrix cells
    queue<pair<int, int> > q;
 
    // Mark the starting cell as visited
    // and push it into the queue
    q.push({x_r, y_r});
    vis[y_r][x_r].viseted = true;
 
    // Iterate while the queue
    // is not empty
        cerr << "x r " << x_r<< " "<< y_r << endl;
    while (!q.empty() &&  ++count < 1000) {
    
 
        pair<int, int> cell = q.front();
        int x = cell.first;
        int y = cell.second;
 
		if (attack_direction == -1 && x_r == 0)
        {
            dx[0] = 1;
            dx[2] = -1;
            attack_direction = 1;
            
        }
		
		else if (attack_direction == 1 && x_r == width -1)
        {
            dx[0] = -1;
            dx[2] = 1;
            attack_direction = -1;
        }
        if (is_build(grid, grid[y][x]) && my_matter / 10)
            ACTION::BUILD(grid[y][x]);
		if (grid[y][x].owner != 1 && vis[y][x].viseted != 1)
		{
            ACTION::MOVE(1, grid[y][x], tile);
            vis[y][x].viseted = true;
            
            if (get_empty_cels(grid, vis, tile) && tile.recycler != 1 && my_matter > 10)
            {
                ACTION::SPAWN(get_empty_cels(grid, vis, tile), tile);
                my_matter -=10;
            }
            my_units.push_back(tile);
       		return ;
		}	
        q.pop();
        // Go to the adjacent cells
        for (int i = 0; i < 4; i++) {
 
            int adjx = x + dx[i];
            int adjy = y + dy[i];
 
            if (isValid(vis, adjx, adjy)) {
                q.push({ adjx, adjy });
            }
        }
    }
}

void get_attack_deriction(int x, int y)
{
    static int i;
    if (!i)
    {
        if (x <= width / 2)
            attack_direction = 1;
        else
            attack_direction = -1;
        if (y <= height)
            attack_direction_y = 1;
        else
            attack_direction_y = -1;

        dx[0] = attack_direction;
        dy[1] = attack_direction;
        dy[3] = -1 * attack_direction;
        ddy[1] = attack_direction;
        ddy[3] = -1 * attack_direction;
        ddx[0] = attack_direction;
        ddx[2] = -1 * attack_direction;
        i =1;
    }
}



int main()
{
    
    cin >> width >> height; cin.ignore();
    
    // game loop
    while (1) {
        count_action =0;
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

        
        cin >> my_matter >> opp_matter; cin.ignore();
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int scrap_amount;
                int owner; // 1 = me, 0 = foe, -1 = neutral
                int units;
                int recycler;
                int can_build;
                int can_spawn;
                int in_range_of_recycler;
                cin >> scrap_amount >> owner >> units >> recycler >> can_build >> can_spawn >> in_range_of_recycler; cin.ignore();
				visted viss;
                Tile tile = {x, y, scrap_amount, owner, units, recycler == 1, can_build == 1, can_spawn == 1, in_range_of_recycler == 1};
                tiles.emplace_back(tile);
                
				grid[y].emplace_back(tile);
				vis[y].emplace_back(viss);
                if (tile.owner == ME) {
					vis[y][x].viseted = 1;
                    my_tiles.emplace_back(tile);
                    if (tile.units > 0) {
                        get_attack_deriction(tile.x, tile.y);
                        my_units.emplace_back(tile);
                    } else if (tile.recycler) {
                        my_recyclers.emplace_back(tile);
                    }
                } else if (tile.owner == OPP) {
					vis[y][x].viseted = 0;
                    opp_tiles.emplace_back(tile);
                    if (tile.units > 0) {
                        opp_units.emplace_back(tile);
                    } else if (tile.recycler) {
					    vis[y][x].viseted = 1;
                        opp_recyclers.emplace_back(tile);
                    }
                } else if (tile.scrap_amount == 0) {
					vis[y][x].viseted = 1;
					tile.grass = 1;
                } else {
                    neutral_tiles.emplace_back(tile);
                }
            }
        }
        cerr << attack_direction << endl;
        do_build(grid, tiles);
        sort(my_units.begin(), my_units.end(), com_on_far_x_r);    
		for (Tile tile : my_units)
		{
            bool should_move = true; // TODO: pick whether to move units from here
            if (should_move)
			{
                int amount = 0; // TODO: pick amount of units to move
                 // TODO: pick a destination
                BFS(grid, vis , tile.x, tile.y, my_units);
            }
        }
            // cerr << count_action;
        if (my_matter / 10 && (my_units.size() <= 3 || count_action <= 2)) 
        {
            memcpy(dx, ddx , 4 * 4);
            memcpy(dy, ddy , 4 * 4);
            if (attack_direction == -1)
            {
                dx[0] = 1;
                dx[2] = -1;
                attack_direction = 1;
                
            }
            
            else if (attack_direction == 1 )
            {
                dx[0] = -1;
                dx[2] = 1;
                attack_direction = -1;
            }
            sort(my_tiles.begin(), my_tiles.end(), com_on_far_x_r);
            for (Tile tile : my_tiles)
		    {
                bool should_move = my_matter / 10; // TODO: pick whether to move units from here
                if (should_move)
                {
                    int amount = 1; // TODO: pick amount of units to move
                        // TODO: pick a destination
                        ACTION::SPAWN(1, tile);
                }
                else
                    cout << "WAIT;";
            }
        }
        else
            cout << "WAIT;";
        my_units.clear();
		cout << endl;
        
    }
}


            


























