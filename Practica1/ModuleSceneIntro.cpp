#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	// TODO 2: Place the camera one unit up in Y and one unit to the right
	// experiment with different camera placements, then use LookAt()
	// to make it look at the center

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	// TODO 1: Create a Plane primitive. This uses the plane formula
	// so you have to express the normal of the plane to create 
	// a plane centered around 0,0. Make that it draw the axis for reference

	primitive.axis = true;
	primitive.wire = true;
	if (App->input->GetMouseButton(SDL_BUTTON_RIGHT) == KEY_REPEAT) {
		App->input->GetMouseX();
		//LOG("%d",App->input->GetMouseX());
	}

	//LOG("%d", App->input->GetMouseXMotion());

	if (App->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_DOWN) {
		XButtonClickPosition = App->input->GetMouseX();
		YButtonClickPosition = App->input->GetMouseY();
		Rangle = Rangle;
	}
		
	if (App->input->GetMouseButton(SDL_BUTTON_LEFT) == KEY_REPEAT) {
	
		/*LOG("%d", App->input->GetMouseX());
		LOG("%d", RRRangle);*/

		XRangle = App->input->GetMouseX();
		YRangle = App->input->GetMouseY();
		XResult = XButtonClickPosition - XRangle;
		YResult = YButtonClickPosition - YRangle;
		LOG("%d", Rangle);
		//Rangle++;
		/*primitive.SetRotation(-YResult * 0.4, { 1,0,0 });
		primitive.SetRotation(-XResult * 0.4, { 0,1,0 });*/
		if (App->input->GetMouseXMotion() < 0) {
			Rangle += 0.5;
		}
		else if(App->input->GetMouseXMotion() > 0) {
			Rangle -= 0.5;
		}
		else {
			Rangle = Rangle;
		}

		primitive.SetRotation(Rangle, { -(float)YResult,-(float) XResult,0 });


		

		//if (XResult != 0) {
		//	primitive.SetRotation(-XResult * 0.4, { 0,1,0 });
		//}
		//else if (YResult != 0) {
		//	primitive.SetRotation(-YResult * 0.4, { 1,0,0 });
		//}else if (XResult != 0 && YResult != 0) {
		//	primitive.SetRotation(Rangle, { -(float)YResult*4,-(float)XResult*4,0 });
		//}
		
	}

	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN) {

		primitive.SetRotation(0, { 1,1,1 });
	}

	//if (App->input->GetKey(SDL_SCANCODE_Q) == KEY_REPEAT) {
	//	ZResult +=1;
	//	primitive.SetRotation(ZResult, { 0,0,1 });
	//	LOG("%d", ZResult);
	//}

	//if (App->input->GetKey(SDL_SCANCODE_Q) == KEY_REPEAT) {
	//	primitive.SetRotation(Rangle, { 0,1,0 });
	//	Rangle++;
	//}

	//if (App->input->GetKey(SDL_SCANCODE_E) == KEY_REPEAT) {
	//	primitive.SetRotation(Rangle, { 0,1,0 });
	//	Rangle--;
	//}

	//if (App->input->GetMouseButton(SDL_BUTTON_RIGHT) == KEY_UP) {
	//	Rangle++;
	//}

	//LOG("%d", Rangle);
	//primitive.Scale(2, 2, 2);
	//primitive.SetRotation(10, {1,1,1});
	//primitive.SetPos(0,1,0);
	primitive.Render();
	


	// TODO 6: Draw a sphere of 0.5f radius around the center
	// Draw somewhere else a cube and a cylinder in wireframe

	return UPDATE_CONTINUE;
}

