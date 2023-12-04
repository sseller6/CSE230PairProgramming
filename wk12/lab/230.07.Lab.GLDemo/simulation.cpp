#include "simulation.h"

Simulation::Simulation(Position ptUpperRight)
{
}

void Simulation::reset()
{
}

void Simulation::fire()
{
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

void Simulation::update(const Interface* pUI)
{
}

void Simulation::getInput(const Interface* pUI)
{
}

bool Simulation::hitTarget()
{
	return false;
}

double Simulation::getHeightMeters()
{
	return 0.0;
}
