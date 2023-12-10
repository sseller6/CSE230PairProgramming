#include "simulation.h"

Simulation::Simulation(Position ptUpperRight)
	: ptUpperRight(ptUpperRight),
	  ground(ptUpperRight),
	  projectile(46.7, 0.077445),
	  time(0.0),
	  timeInterval(0.5),
	  isFired(false)
{
	howitzer.position.setPixelsX(Position(ptUpperRight).getPixelsX() / 2.0);
	ground.reset(howitzer.position);
}

void Simulation::run(const Interface* pUI)
{
	// Check to see if the howitzer has been fired
 	if (isFired)
	{
		// Check to see if projectile has hit the ground
		if (projectile.flying())
		{
			projectile.advance(timeInterval);
		}
		else
		{
			if (hitTarget())
			{
				win();
			}
			else
			{
				lose();
			}
		}
	}
	else
	{
		getInput(pUI);
	}
}

void Simulation::reset()
{
	ground.reset(howitzer.position); // Fixed by making simulation friend of howitzer figure out better way later
	projectile.reset();
	isFired = false;
	time = 0.0;
}

void Simulation::fire()
{
	cout << "Sim Fired" << endl;
	isFired = true;
	time = 0.00;
	projectile.fire(howitzer.getPosition(), time,
		            howitzer.getMuzzleAngle(), howitzer.getMuzzleVelocity());
}

void Simulation::display(const Interface* pUI)
{
	ogstream gout(Position(10.0, ptUpperRight.getPixelsY() - 20.0));

	// draw the ground first
	ground.draw(gout);

	// draw the howitzer
	howitzer.draw(gout, time);

	// draw the projectile
	projectile.draw(gout);

	// draw HUD
	gout.setf(ios::fixed | ios::showpoint);
	gout.precision(2);
	gout << "Time since the bullet was fired: "
		<< time << "seconds\n"
		<< "Muzzle Angle: " << howitzer.getMuzzleAngle() << "radians\n"
		<< "Is Fired: " << isFired << "\n"
		<< "Bullet Location: " << projectile.getPosition().getPixelsX() << "x Pixels\n"
		<< "                 " << projectile.getPosition().getPixelsY() << "y Pixels\n";
}

void Simulation::getInput(const Interface* pUI)
{
	// move a large amount
	if (pUI->isRight())
		howitzer.rotateRight();
	if (pUI->isLeft())
		howitzer.rotateLeft();

	// move by a little
	if (pUI->isUp())
		howitzer.raiseUp();
	if (pUI->isDown())
		howitzer.raiseDown();

	// fire that gun
	if (pUI->isSpace())
		fire();
}

bool Simulation::hitTarget()
{
	return false;
}

double Simulation::getHeightMeters()
{
	return 0.0;
}

void Simulation::win()
{
	// Display vicotry <- lol "vicotry"
	projectile.reset();
}

void Simulation::lose()
{
	// Display you suck
	projectile.reset();
}