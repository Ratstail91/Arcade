/* Copyright: (c) Kayne Ruse 2013
 * 
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 * 
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 * 
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 * 
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 * 
 * 3. This notice may not be removed or altered from any source
 * distribution.
*/
#include "space_invaders.hpp"

#include <iostream>

using namespace std;

//-------------------------
//macros
//-------------------------

#define PLAYER_SPEED 140

//-------------------------
//Public access members
//-------------------------

SpaceInvaders::SpaceInvaders() {
	//setup the player
	player.GetSprite()->LoadSurface("rsc\\player.bmp", 1, 1);
	player.SetBBoxW(static_cast<double>(player.GetSprite()->GetImage()->GetClipW()));
	player.SetBBoxH(static_cast<double>(player.GetSprite()->GetImage()->GetClipH()));
	player.SetX(400 - player.GetBBoxW() / 2);
	player.SetY(550);
}

SpaceInvaders::~SpaceInvaders() {
	//
}

//-------------------------
//Frame loop
//-------------------------

void SpaceInvaders::FrameStart() {
	//
}

void SpaceInvaders::Update(double delta) {
	//update the player
	player.Update(delta);
	if (player.GetX() <= 0) {
		player.SetX(0);
	}

	if (player.GetX() + player.GetBBoxW() >= GetScreen()->w) {
		player.SetX(GetScreen()->w - player.GetBBoxW());
	}
}

void SpaceInvaders::FrameEnd() {
	//
}

void SpaceInvaders::Render(SDL_Surface* const screen) {
	player.DrawTo(screen);
}

//-------------------------
//Event handlers
//-------------------------

void SpaceInvaders::MouseMotion(SDL_MouseMotionEvent const& motion) {
	//
}

void SpaceInvaders::MouseButtonDown(SDL_MouseButtonEvent const& button) {
	//
}

void SpaceInvaders::MouseButtonUp(SDL_MouseButtonEvent const& button) {
	//
}

void SpaceInvaders::KeyDown(SDL_KeyboardEvent const& key) {
	switch(key.keysym.sym) {
		case SDLK_ESCAPE:
			QuitEvent();
		break;

		//player movement
		case SDLK_LEFT:
			if (player.GetMotionX() >= 0) {
				player.SetMotionX(player.GetMotionX() - PLAYER_SPEED); //shift
			}
		break;

		case SDLK_RIGHT:
			if (player.GetMotionX() <= 0) {
				player.SetMotionX(player.GetMotionX() + PLAYER_SPEED); //shift
			}
		break;
	}
}

void SpaceInvaders::KeyUp(SDL_KeyboardEvent const& key) {
	switch(key.keysym.sym) {
		//player movement
		case SDLK_LEFT:
			if (player.GetMotionX() <= 0) {
				player.SetMotionX(player.GetMotionX() + PLAYER_SPEED); //shift
			}
		break;

		case SDLK_RIGHT:
			if (player.GetMotionX() >= 0) {
				player.SetMotionX(player.GetMotionX() - PLAYER_SPEED); //shift
			}
		break;
	}

}
