//
//  Level.cpp
//  Pusher
//
//  Created by I_Jemin on 2015. 2. 19..
//  Copyright (c) 2015년 I_Jemin. All rights reserved.
//

#include "Level.h"

using namespace std;

Level::Level()
{
    numberOfGoal =0;
}

Level::~Level()
{
    
    
    
}


void Level::loadFile()
{
    ifstream inFile;
    
    inFile.open("stage.data",ios::in);
    
    char levelIterator = 0;
    
    int numberOfChar = -1;
    
    if (!inFile)
    {
        cout << "loadFailed";
    }
    
    
    //파일의 끝부분이 아닐동안
    while(!inFile.eof())
    {
        cout << "Check Number Of Level Char"<< endl;
        inFile >> levelIterator;
        
        if(levelIterator!='N')
            numberOfChar++;
    }
    
    cout << "CHAR SIZE" << numberOfChar << endl;
    
    levelInfo = new objState[numberOfChar];
    
    int levelInfoCursor = 0;
    
    inFile.close();
    
    //커서를 다시 돌리기- 재오픈
    inFile.open("stage.data");
    
    
    //플레이어 위치 커서
    int playerPositionCursor=0;
    
    while(!inFile.eof())
    {
        inFile >> levelIterator;
        
        
        if (levelIterator == 'N')
        {
            //개행 문자가 나올때 마다 y사이즈를 1씩 늘린다.
            levelSize.add(0,1);
            
        }else
        {
        
        switch(levelIterator)
        {
            case '#':
                levelInfo[levelInfoCursor] = WALL;
                levelInfoCursor++;
                break;
            case 'E':
                levelInfo[levelInfoCursor] = EMPTY;
                levelInfoCursor++;
                break;
            case 'o':
                levelInfo[levelInfoCursor] = BALL;
                levelInfoCursor++;
                break;
            case '.':
                levelInfo[levelInfoCursor] = GOAL;
                levelInfoCursor++;
                numberOfGoal++;
                break;
            case 'P':
                playerPositionCursor = levelInfoCursor;
                
                levelInfo[levelInfoCursor] = PLAYER;
                levelInfoCursor++;
                break;
        }
            
            
        }
    }
    
    //마지막 줄은 개햄문자가 없으므로.
    levelSize.add(0,1);
    
    //x사이즈 지정
    levelSize.set(numberOfChar/levelSize.y(), levelSize.y());
    
    playerPosition.set(playerPositionCursor%levelSize.x(),playerPositionCursor/levelSize.x());
    
    cout << levelSize.x() << levelSize.y();
    cout << endl;
    
}

void Level::controlPlayer()
{
    char keyInput = 0;
    cout << "Moving Position" << endl;
    
    cin >> keyInput;
    
    switch(keyInput)
    {
        case UP:
            playerDeltaPosition.add(0,-1);
            break;
        case DOWN:
            playerDeltaPosition.add(0, 1);
            break;
        case LEFT:
            playerDeltaPosition.add(-1,0);
            break;
        case RIGHT:
            playerDeltaPosition.add(1,0);
            break;
    }
}


void Level::updateLevel()
{
    Vector2 newPlayerPosition = playerPosition + playerDeltaPosition;
    Vector2 newBallPosition = newPlayerPosition + playerDeltaPosition;
    
    int currentPositionCursor = playerPosition.x() + levelSize.x()*playerPosition.y();
    int newPositionCursor = newPlayerPosition.x()+levelSize.x()*newPlayerPosition.y();
    int newBallCursor = newBallPosition.x() + levelSize.x()*newBallPosition.y();
    
    if(levelInfo[currentPositionCursor] == PLAYER)
    {
    switch(levelInfo[newPositionCursor])
    {
        case WALL:
            //do Nothing
            break;
        case EMPTY:
            levelInfo[newPositionCursor] = PLAYER;
            levelInfo[currentPositionCursor] = EMPTY;
            
            playerPosition = newPlayerPosition;
            
            break;
        case GOAL:
            levelInfo[newPositionCursor] = PLAYER_ON_GOAL;
            levelInfo[currentPositionCursor] = EMPTY;
            
            playerPosition = newPlayerPosition;
            break;
        case BALL:
            if(levelInfo[newBallCursor] == WALL && BALL && BALL_ON_GOAL)
            {
                // do nothing
            } else if(levelInfo[newBallCursor] == GOAL)
            {
                levelInfo[newBallCursor] = BALL_ON_GOAL;
                levelInfo[newPositionCursor] = PLAYER;
                levelInfo[currentPositionCursor] = EMPTY;
                
                playerPosition = newPlayerPosition;
                
            } else if (levelInfo[newBallCursor] == EMPTY)
            {
                levelInfo[newBallCursor] = BALL;
                levelInfo[newPositionCursor] = PLAYER;
                levelInfo[currentPositionCursor] = EMPTY;
                
                playerPosition = newPlayerPosition;
            }
            break;
        case BALL_ON_GOAL:
            if(levelInfo[newBallCursor] == WALL && BALL && BALL_ON_GOAL)
            {
                // do nothing
            } else if(levelInfo[newBallCursor] == GOAL)
            {
                levelInfo[newBallCursor] = BALL_ON_GOAL;
                levelInfo[newPositionCursor] = PLAYER_ON_GOAL;
                levelInfo[currentPositionCursor] = EMPTY;
                
                playerPosition = newPlayerPosition;
                
            } else if (levelInfo[newBallCursor] == EMPTY)
            {
                levelInfo[newBallCursor] = BALL;
                levelInfo[newPositionCursor] = PLAYER_ON_GOAL;
                levelInfo[currentPositionCursor] = EMPTY;
                
                playerPosition = newPlayerPosition;
            }
            break;
    }
    }
        else if (levelInfo[currentPositionCursor] == PLAYER_ON_GOAL)
    {
        switch(levelInfo[newPositionCursor])
        {
            case WALL:
                //do Nothing
                break;
            case EMPTY:
                levelInfo[newPositionCursor] = PLAYER;
                levelInfo[currentPositionCursor] = GOAL;
                
                playerPosition = newPlayerPosition;
                
                break;
            case GOAL:
                levelInfo[newPositionCursor] = PLAYER_ON_GOAL;
                levelInfo[currentPositionCursor] = GOAL;
                
                playerPosition = newPlayerPosition;
                break;
            case BALL:
                if(levelInfo[newBallCursor] == WALL && BALL && BALL_ON_GOAL)
                {
                    // do nothing
                } else if(levelInfo[newBallCursor] == GOAL)
                {
                    levelInfo[newBallCursor] = BALL_ON_GOAL;
                    levelInfo[newPositionCursor] = PLAYER;
                    levelInfo[currentPositionCursor] = GOAL;
                    
                    playerPosition = newPlayerPosition;
                    
                } else if (levelInfo[newBallCursor] == EMPTY)
                {
                    levelInfo[newBallCursor] = BALL;
                    levelInfo[newPositionCursor] = PLAYER;
                    levelInfo[currentPositionCursor] = GOAL;
                    
                    playerPosition = newPlayerPosition;
                }
                break;
            case BALL_ON_GOAL:
                if(levelInfo[newBallCursor] == WALL && BALL && BALL_ON_GOAL)
                {
                    // do nothing
                } else if(levelInfo[newBallCursor] == GOAL)
                {
                    levelInfo[newBallCursor] = BALL_ON_GOAL;
                    levelInfo[newPositionCursor] = PLAYER_ON_GOAL;
                    levelInfo[currentPositionCursor] = GOAL;
                    
                    playerPosition = newPlayerPosition;
                    
                } else if (levelInfo[newBallCursor] == EMPTY)
                {
                    levelInfo[newBallCursor] = BALL;
                    levelInfo[newPositionCursor] = PLAYER_ON_GOAL;
                    levelInfo[currentPositionCursor] = GOAL;
                    
                    playerPosition = newPlayerPosition;
                }
                break;
        }
    }
    
    
    
    
    playerDeltaPosition.set(0,0);
}


objState* Level::exportToRenderer()
{
    
    return levelInfo;
}


Vector2 Level::exportLevelSize()
{
    
    return levelSize;
}



