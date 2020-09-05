/*Laser Jump - Chris Antes
9/4/2020
This will be a game test.
Probably a lot of variables, just testing collision..
*/
#include "Engine/Engine.h"
#include "Engine/Graphics/Sprite.h"
#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"
#include "Engine/Timer.h"

#include "myGame/InputManager.h"
#include "myGame/Object.h"

#include <iostream>



using namespace std;

int main()
{ //Console Log..
    std::cout << "Jump game test\n"; 
	//Create the Game, and title..
	Engine engine;
	engine.Initialize("Moon Game TEST");
	//Create a sprite..
	Sprite testSprite = Sprite("Assets/Art/guy01_red.png", Vector3((float)Engine::SCREEN_WIDTH/2, (float)Engine::SCREEN_HEIGHT / 2,(float)0));
	testSprite.SetScale(1.25f);
	//Create a player
	Object player(testSprite);
	//Grass..
	Sprite grass1 = Sprite("Assets/Art/grass01.png", Vector3(100, 100, 0));
	grass1.SetScale(1.25f);
	//Set grass to not have any gravity
	Object grass(grass1);
	grass.GetRB().setGravity(0);
	grass.GetSprite().MoveTo(Vector3(513, 18, 0));
	//orb spawn
	Sprite orb1 = Sprite("Assets/Art/whiteorb01.png", Vector3(513, 60, 0));
	Object *orb = new Object(orb1);
	orb->GetRB().setGravity(0);
	//timer
	Timer clock;
	bool orbExist = true;
	//nan
	Sprite nan = Sprite("Assets/Art/nan.png", Vector3(0, 0, 0));
	bool isBlue = false;
	//blue laser
	Sprite bluelaser1 = Sprite("Assets/Art/bluelaser01.png", Vector3(256, 100, 0));
	Sprite redlaser1 = Sprite("Assets/Art/redlaser01.png", Vector3(758, 100, 0));
	Object bluelaser(bluelaser1);
	Object redlaser(redlaser1);
	bluelaser.GetRB().setGravity(0);
	redlaser.GetRB().setGravity(0);

	//Manager
	InputManager im(&player);
	//Run the game..
	while (true) {
		//Update the game and sprite
		engine.Update();
		player.Update();
		grass.Update();
		bluelaser.Update();
		redlaser.Update();

		double player_x = player.GetSprite().GetPos()->x;
		double player_y = player.GetSprite().GetPos()->y;
		//Check player position
		if ((player_x > (float)Engine::SCREEN_WIDTH) || (player_y > (float)Engine::SCREEN_HEIGHT) || player_y < -10 || player_x < -10) {
			player.GetSprite().MoveTo(Vector3((float)Engine::SCREEN_WIDTH / 2, (float)Engine::SCREEN_HEIGHT / 2, (float)0));
		}

		//Make it exist
		/*cout << (isBlue==true ? "Blue " : "Red ");
		cout << (int)clock.getCurrentSeconds() << "\n";*/
		cout << player.GetSprite().GetPos()->x << "," << player.GetSprite().GetPos()->y << "," << player.GetSprite().GetPos()->x << "\n";
		if (orbExist == false && clock.getCurrentSeconds() >= (double)5) {
			clock.stopTimer();
			orbExist = true;
			orb->GetSprite().setTexture("Assets/Art/whiteorb01.png");
		}
		//if they col
		bool orbColl = false;
		if (orbExist == true) {
			orb->Update();
			orbColl = Rigidbody::IsColliding(player.GetRB(), orb->GetRB());
		}
		bool isColliding = Rigidbody::IsColliding(player.GetRB(), grass.GetRB());
		bool redCol = Rigidbody::IsColliding(player.GetRB(), redlaser.GetRB());
		bool blueCol = Rigidbody::IsColliding(player.GetRB(), bluelaser.GetRB());

		if (redCol && isBlue && player.GetSprite().GetPos()->y >= redlaser.GetSprite().GetPos()->y) {
			player.GetRB().setGravity(0);
			Vector3 vel = player.GetRB().GetVal();
			vel.y = 0;
			player.GetRB().SetVel(vel);
			player.straightenOb();
		}
		if (blueCol && !isBlue && player.GetSprite().GetPos()->y >= bluelaser.GetSprite().GetPos()->y) {
			player.GetRB().setGravity(0);
			Vector3 vel = player.GetRB().GetVal();
			vel.y = 0;
			player.GetRB().SetVel(vel);
			player.straightenOb();
		}

		//if we touch ball
		if (orbColl) {
			clock.startTimer();
			orbExist = false;
			orb->GetSprite().setTexture("Assets/Art/nan.png");
			if (isBlue == true) { //Make him red..
				player.GetSprite().setTexture("Assets/Art/guy01_red.png");
				isBlue = false;

			} //Make him blue..
			else {
				player.GetSprite().setTexture("Assets/Art/guy01_blue.png");
				isBlue = true;		
			}
		}
		if (isColliding) {
			player.GetRB().setGravity(0);
			//player.GetSprite().MoveTo(Vector3(player.GetSprite().GetPos()->x, player.GetSprite().GetPos()->y, 0));
			Vector3 vel = player.GetRB().GetVal();
			vel.y = 5;
			player.GetRB().SetVel(vel);
			//player.GetRB().AddForce(Vector3(0, 10, 0));
		} else if (!blueCol && !redCol) {
			player.GetRB().setGravity(-10);
		}

		//Update the manager..
		im.Update();

		//after manager for gravity fix and reroute..
		if (redCol && isBlue && (!(player.GetSprite().GetPos()->y >= redlaser.GetSprite().GetPos()->y*2.4))) {
			player.GetRB().setGravity(-10);
			Vector3 vel = player.GetRB().GetVal();
			vel.x = abs(vel.x)-5000;
			vel.y += 2;
			player.GetRB().SetVel(vel);
			player.straightenOb();
		}
		if (blueCol && !isBlue && (!(player.GetSprite().GetPos()->y >= redlaser.GetSprite().GetPos()->y*2.4))) {
			player.GetRB().setGravity(-10);
			Vector3 vel = player.GetRB().GetVal();
			vel.x = abs(vel.x)-5000;
			vel.y += 2;
			player.GetRB().SetVel(vel);
			player.straightenOb();
		}

		bluelaser.GetRB().AddForce(Vector3(-10, 0, 0));
		redlaser.GetRB().AddForce(Vector3(-10, 0, 0));
		if (bluelaser.GetSprite().GetPos()->x <= 0) {
			bluelaser.GetSprite().GetPos()->x = 1000;
		}
		if (redlaser.GetSprite().GetPos()->x <= 0) {
			redlaser.GetSprite().GetPos()->x = 1000;
		}

		//Render the game and sprite
		engine.BeginRender();
		bluelaser.GetSprite().Render();
		redlaser.GetSprite().Render();
		player.GetSprite().Render();
		grass.GetSprite().Render();
		if (orbExist == true) {
			orb->GetSprite().Render();
		}
		engine.EndRender();

	}


	return 0;
}

