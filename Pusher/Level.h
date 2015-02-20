//
//  Level.h
//  Pusher
//
//  Created by I_Jemin on 2015. 2. 19..
//  Copyright (c) 2015년 I_Jemin. All rights reserved.
//

#ifndef __Pusher__Level__
#define __Pusher__Level__

#include <iostream>
#include "Vector2.h"
#include <fstream>




//Key Bidning

const char UP = 'w';
const char DOWN = 's';
const char LEFT = 'a';
const char RIGHT = 'd';



/*
 레벨 디자인의 정보를 가져오고,
 키보드로 부터 입력을 받아 플레이어의 위치를 변화시킨다.
 
 입력을 받은 뒤 레벨의 변화를 기록하고 이를 랜더러 클래스로 출력한다.
 */


//각 포지션에 위치한 오브젝트들의 상태를 나타낸다.
enum objState{WALL,EMPTY,GOAL,BALL,BALL_ON_GOAL,PLAYER,PLAYER_ON_GOAL};

class Level{
private:
    
    //플레이어의 현재 위치
    Vector2 playerPosition;
    
    //플레이어가 이동하는 방향, 초기화 해주자.
    Vector2 playerDeltaPosition;
    
    //레벨의 가로x,세로y 사이즈
    Vector2 levelSize;
    
    //레벨의 정보를 1차원 배열로 저장한다.
    objState* levelInfo;
    
    //클리어시 필요한 목표의 수이다.
    int numberOfGoal;
    

    
public:
    
    Level();
    
    ~Level();
    
    
    
    void loadFile();
    
    //deltaVector 를 업데이트한다. 즉 플레이어가 이동한 양을 리턴한다.
    void controlPlayer();
    
    //플레이어의 이동에 따라 레벨을 업데이트 한다.
    void updateLevel();
    
    //레벨 정보를 랜더러에게 전송
    objState* exportToRenderer();
    
    
    Vector2 exportLevelSize();
    
};
#endif /* defined(__Pusher__Level__) */
