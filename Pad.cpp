/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pad.cpp
 * Author: marcin
 * 
 * Created on 27 kwietnia 2016, 12:43
 */

#include "Pad.h"

Pad::Pad()
{
    color_ = Constants::BLUE;
    position_ = Vector2D(Constants::SCREEN_WIDTH / 2 - Constants::PAD_WIDTH / 2, 100);
    
    rectangle_.x = position_.getX();
    rectangle_.y = position_.getY();
    
    rectangle_.w = Constants::PAD_WIDTH;
    rectangle_.h = Constants::PAD_HEIGHT;
}

void Pad::handle_events(SDL_Event& e)
{
    const Uint8* state = SDL_GetKeyboardState(NULL);
    
    velocity_.setX(0);
    
    if(state[SDL_SCANCODE_LEFT] && !state[SDL_SCANCODE_RIGHT])
        velocity_.setX(-1);
    
    if(state[SDL_SCANCODE_RIGHT] && !state[SDL_SCANCODE_LEFT])
        velocity_.setX(1);
}

void Pad::update(int delta)
{
    position_ += velocity_ * (Constants::PAD_SPEED * delta/1000);
    
    if(position_.getX() < 0)
        position_ = Vector2D(0, position_.getY());
    
    else if(position_.getX() + Constants::PAD_WIDTH > Constants::SCREEN_WIDTH)
        position_ = Vector2D(Constants::SCREEN_WIDTH - Constants::PAD_WIDTH, position_.getY());
    
    rectangle_.x = position_.getX();
    rectangle_.y = position_.getY();
}