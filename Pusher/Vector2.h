//
//  Vector2.h
//  Pusher
//
//  Created by I_Jemin on 2015. 2. 19..
//  Copyright (c) 2015년 I_Jemin. All rights reserved.
//

#ifndef __Pusher__Vector2__
#define __Pusher__Vector2__

#include <stdio.h>

class Vector2
{
private:
    int X;
    int Y;
    
public:
    
    Vector2();
    Vector2(int x, int y);
    
    ~Vector2();
    
    //getX나 getY보다 좀더 쉽게 접근하도록 하기 위해서.
    int x();
    int y();
    
    void set(int x, int y);
    void add(int dx, int dy);
    
    Vector2 operator+ (Vector2 other);
    void operator= (Vector2 other);
    Vector2 operator- (Vector2 other);
    
};

#endif /* defined(__Pusher__Vector2__) */
