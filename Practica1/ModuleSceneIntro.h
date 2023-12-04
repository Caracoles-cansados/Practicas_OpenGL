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


	int Rangle= 0;
	int XButtonClickPosition = 0;
	int YButtonClickPosition = 0;

	int XRangle;
	int YRangle;
	int XResult;
	int YResult;
	
	Primitive primitive;
};
