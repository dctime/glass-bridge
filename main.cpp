#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

// defines all glasses state
enum GlassState
{
    UNBREAKABLE, BREAKABLE, BROKEN
};

void initialOutputScreen(char outputElements[][85]);
// a is the array ready to pint out
// the pass in array must be 15 * 85
// pass in empty array, returns array that is ready to show on the screen

void initialGlassState(GlassState glasses[][30]);
// pass in array must be 2 or it won't work
// pass in blank array, and it will auto assign GlassStates to every elements of glasses

void showGlassState(const GlassState glasses[][30], ostream& outputDevice = cout);
// show glasses' GlassState on an output device, default is the screen(cout)

void showScreen(const char outputElements[][85]);
// show output elements on the screen

void updateOutputElements(const GlassState glasses[][30], char outputElements[][85]);
// update outputElements array by glasses'states
// BROKEN -> X


int main()
{
    // Stores glasses data
    GlassState glasses[2][30];
    // placing glasses on the bridge
    initialGlassState(glasses);
    glasses[0][5] = BROKEN;
    // printing out glasses data
    showGlassState(glasses);

    // outputScreen : Stores characters ready to be displayed on the screen
    char outputElements[15][85];
    // constructing the screen
    initialOutputScreen(outputElements);
    updateOutputElements(glasses, outputElements);
    // show the screen
    showScreen(outputElements);


}

void initialGlassState(GlassState glasses[][30])
{
    srand(time(0));

    for (int i = 0; i < 30; i++)
    {
        int randomNumberZeroOrOne = rand()%2;
        // if even -> BREAKABLE, odd -> UNBREAKABLE
        if (randomNumberZeroOrOne == 1)
        {
            glasses[0][i] = BREAKABLE;
            glasses[1][i] = UNBREAKABLE;
        }
        else if (randomNumberZeroOrOne == 0)
        {
            glasses[0][i] = UNBREAKABLE;
            glasses[1][i] = BREAKABLE;
        }
        else
        {
            cout << "Warning: RandomNumberZeroOrOne Got Problems!!" << endl;
        }
    }
}

void initialOutputScreen(char outputElements[][85])
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 85; j++)
            outputElements[i][j] = ' ';
    }//設初始值

    for (int i = 0; i < 85; i++)
    {
        outputElements[0][i] = '*';
        outputElements[14][i] = '*';
    }//設上下框

    for (int i = 1; i < 10; i++)
    {
        outputElements[6][i] = '*';
        outputElements[8][i] = '*';
    }//start上下

    outputElements[7][1] = '*';
    outputElements[7][9] = '*';//start左右

    outputElements[7][3] = 'S';
    outputElements[7][4] = 'T';
    outputElements[7][5] = 'A';
    outputElements[7][6] = 'R';
    outputElements[7][7] = 'T';//start文字

    for (int i = 77; i < 84; i++)
    {
        outputElements[6][i] = '$';
        outputElements[8][i] = '$';
    }//end上下

    outputElements[7][77] = '$';
    outputElements[7][83] = '$';//end左右
    outputElements[7][79] = 'E';
    outputElements[7][80] = 'N';
    outputElements[7][81] = 'D';//end文字

    for (int i = 13; i < 74; i++)
        outputElements[5][i] = '-';
    for (int i = 13; i < 74; i+=2)
        outputElements[6][i] = '|';
    for (int i = 13; i < 74; i++)
        outputElements[7][i] = '-';
    for (int i = 13; i < 74; i+=2)
        outputElements[8][i] = '|';
    for (int i = 13; i < 74; i++)
        outputElements[9][i] = '-';//玻璃橋設置
}

void showGlassState(const GlassState glasses[][30], ostream& outputDevice)
{
    for (int yIndex = 0; yIndex < 2; yIndex++)
    {
        for (int xIndex = 0; xIndex < 30; xIndex++)
        {
            outputDevice << glasses[yIndex][xIndex] << " ";
        }
        outputDevice << endl;
    }
}

void showScreen(const char outputElements[][85])
{
    for (int yOutputScreenIndex = 0; yOutputScreenIndex < 15; yOutputScreenIndex++)
    {
        for (int xOutputScreenIndex = 0; xOutputScreenIndex < 85; xOutputScreenIndex++)
            cout << outputElements[yOutputScreenIndex][xOutputScreenIndex];
        cout << endl;
    }//輸出畫面
}

void updateOutputElements(const GlassState glasses[][30], char outputElements[][85])
{
    for (int glassesYIndex = 0; glassesYIndex < 30; glassesYIndex++)
    {
        for (int glassesXIndex = 0; glassesXIndex < 30; glassesXIndex++)
        {
            if (glasses[glassesYIndex][glassesXIndex] == BROKEN)
            {
                outputElements[6+2*glassesYIndex][14+2*glassesXIndex] = 'X';
            }
        }
    }
}
