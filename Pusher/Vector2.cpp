//
//  Vector2.cpp
//  Pusher
//
//  Created by I_Jemin on 2015. 2. 19..
//  Copyright (c) 2015년 I_Jemin. All rights reserved.
//

#include "Vector2.h"


Vector2::Vector2()
{
    X= 0;
    Y =0;
}

Vector2::Vector2(int x,int y)
{
    X = x;
    Y = y;
}

Vector2::~Vector2()
{
    
}

void Vector2::add(int dx, int dy)
{
    X+=dx;
    Y+=dy;
}

void Vector2::set(int x, int y)
{
    this->X = x;
    this->Y = y;
}

Vector2 Vector2::operator+(Vector2 other)
{
    return Vector2(X+other.X,Y+other.Y);
}

Vector2 Vector2::operator-(Vector2 other){
    return Vector2(X-other.X,Y-other.Y);
}

void Vector2::operator=(Vector2 other)
{
    X = other.X;
    Y = other.Y;
}

int Vector2::x()
{
    return X;
}

int Vector2::y()
{
    
    return Y;
}