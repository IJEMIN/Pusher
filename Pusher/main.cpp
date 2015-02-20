//
//  main.cpp
//  Pusher
//
//  Created by I_Jemin on 2015. 2. 19..
//  Copyright (c) 2015년 I_Jemin. All rights reserved.
//

#include <iostream>
#include "Level.h"

using namespace std;


void renderToScreen(objState* levelInfo,Vector2 levelSize);


int main(int argc, const char * argv[]) {
    
    Level newLevel;
    
    newLevel.loadFile();
    
    while(1)
    {
        renderToScreen(newLevel.exportToRenderer(),newLevel.exportLevelSize());
        newLevel.controlPlayer();
        newLevel.updateLevel();
        
    }
    
    
    
    return 0;
}



void renderToScreen(objState* levelInfo,Vector2 levelSize)
{
    cout << endl;
    
    int x = levelSize.x();
    int y = levelSize.y();
    
    
    
    for (int i = 0; i<y; i++)
    {
        for (int k=0; k<x; k++)
        {
            switch(levelInfo[k + levelSize.x()*i])
            {
                case WALL:
                    cout << '#';
                    break;
                case BALL:
                    cout << 'o';
                    break;
                case GOAL:
                    cout << '.';
                    break;
                case PLAYER:
                    cout << 'P';
                    break;
                case EMPTY:
                    cout << ' ';
                    break;
                case BALL_ON_GOAL:
                    cout << 'O';
                    break;
                case PLAYER_ON_GOAL:
                    cout << 'P';
                    break;
            }
        }
        cout << endl;
    }
    
    
    
}