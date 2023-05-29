#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
using namespace std;


class Calc{
private:
    #define RESET "\033[0m"
    #define BLACK   "\033[30m"      /* Black */
    #define RED     "\033[31m"      /* Red */
    #define GREEN   "\033[32m"      /* Green */
    #define YELLOW  "\033[33m"      /* Yellow */
    #define BLUE    "\033[34m"      /* Blue */
    #define MAGENTA "\033[35m"      /* Magenta */
    #define CYAN    "\033[36m"      /* Cyan */
    #define WHITE   "\033[37m"      /* White */
    #define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
    #define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
    #define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
    #define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
    #define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
    #define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
    #define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
    #define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

    void printGrid(const vector<vector<char>>& grid) {
        for (const auto& row : grid) {
            for (const auto& cell : row) {
                cout << cell << ' ';
            }
            cout << '\n';
        }
    }

    void placeString(vector<vector<char>>& grid, int startX, int startY, const string& str) {
        int x = startX;
        int y = startY;
        for (char c : str) {
            grid[y][x] = c;
            x++;
            if (x >= grid[0].size()) {
                x = 0;
                y++;
                if (y >= grid.size()) {
                    // Handle the case where the string doesn't fit within the grid
                    cout << "String doesn't fit within the grid!\n";
                    return;
                }
            }
        }
    }

    void Display(int x, int y, int hight, int width, string str, char peace){
        vector<vector<char>> grid(hight, vector<char>(width, peace));
        placeString(grid, x, y, str);
        printGrid(grid);
    }
public:
    void Start(){
        Display(3,5,11,11,"Hi!!!", ' ');
        Display(3,5,11,11,"no", ' ');
    }
};