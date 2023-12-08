#include "simulation.h"

Simulation::Simulation(Position ptUpperRight)
{
}

void Simulation::run(const Interface* pUI)
{
	// Check to see if the howitzer has been fired
	if (isFired)
	{
		// Check to see if projectile has hit the ground
		if (!ground.hitGround())
		{
			projectile.advance();
		}
		else if (hitTarget())
		{
			win();
		}
		else
		{
		    lose();
		}
	}
	else
	{
		getInput();
	}
}

void Simulation::reset()
{
}

void Simulation::fire()
{
	time = 0.00;
	// projectile.fire(projectile.getPosition(), time,
	//	            howitzer.getMuzzleAngle(), howitzer.getMuzzleVelocity());
}

void Simulation::display(ogstream& gout, const Interface* pUI)
{
	// draws everything
	
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
		 << time << "seconds\n";
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
