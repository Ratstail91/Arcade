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
#ifndef GENERICENTITY_HPP_
#define GENERICENTITY_HPP_

#include "sprite_sheet.hpp"
#include "vector2.hpp"
#include "bbox.hpp"

//A quick & dirty aggregate class
class GenericEntity {
public:
	GenericEntity() {
		position = {0,0};
		motion = {0,0};
		bbox = {0,0,0,0};
	}

	~GenericEntity() = default;

	void Update(double delta) {
		sprite.Update(delta);
		position += motion * delta;
	}

	void DrawTo(SDL_Surface* const dest) {
		sprite.DrawTo(dest, position.x, position.y);
	}

	//accessors & mutators
	SpriteSheet* GetSprite() {
		return &sprite;
	}

	double SetX(double i) { return position.x = i; }
	double SetY(double j) { return position.y = j; }
	double GetX() const { return position.x; }
	double GetY() const { return position.y; }

	double SetMotionX(double i) { return motion.x = i; }
	double SetMotionY(double j) { return motion.y = j; }
	double GetMotionX() const { return motion.x; }
	double GetMotionY() const { return motion.y; }

	double SetBBoxX(double i) { return bbox.x = i; }
	double SetBBoxY(double j) { return bbox.y = j; }
	double SetBBoxW(double k) { return bbox.w = k; }
	double SetBBoxH(double l) { return bbox.h = l; }
	double GetBBoxX() const { return bbox.x; }
	double GetBBoxY() const { return bbox.y; }
	double GetBBoxW() const { return bbox.w; }
	double GetBBoxH() const { return bbox.h; }

private:
	SpriteSheet sprite;
	Vector2 position;
	Vector2 motion;
	BBox bbox;
};

#endif
