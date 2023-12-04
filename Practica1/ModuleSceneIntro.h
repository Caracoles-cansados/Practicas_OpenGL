#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

#define BOUNCER_TIME 200

struct PhysBody3D;
class Cube;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update();
	bool CleanUp();

public:


	float Rangle= 0;
	float XButtonClickPosition = 0;
	float YButtonClickPosition = 0;

	float XRangle;
	float YRangle;
	float XResult;
	float YResult;
	
	Primitive primitive;
};
