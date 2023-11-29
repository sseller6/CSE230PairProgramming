

#include "physics.h"

// Linear interpolation
double linearInterpolation(const Mapping mapping[], int numMapping, double domain)
{
	// off the scale on the small end
	if (domain < mapping[0].domain)
	{
		return mapping[0].range;
	}

	// within the table
	for (int i = 0; i < numMapping - 1; i++)
	{
		// the domain must be in order
		assert(mapping[i + 0].domain < mapping[i + 1].domain);
		if (mapping[i + 0].domain <= domain && domain <= mapping[i + 1].domain)
		{
			return linearInterpolation(mapping[i + 0], mapping[i + 1], domain);
		}
	}

	// off the scale on the large end
	return mapping[numMapping - 1].range;
}

// Gravity from altitude
double gravityFromAltitude(double altitude)
{
	const Mapping gravityMapping[] =
	{ //  altitude      gravity
		{ 0.0        ,  9.807 },
		{ 1000.0     ,  9.804 },
		{ 2000.0     ,  9.801 },
		{ 3000.0     ,  9.797 },
		{ 4000.0     ,  9.794 },
		{ 5000.0     ,  9.791 },
		{ 6000.0     ,  9.788 },
		{ 7000.0     ,  9.785 },
		{ 8000.0     ,  9.782 },
		{ 9000.0     ,  9.779 },
		{ 10000.0    ,  9.776 },
		{ 15000.0    ,  9.761 },
		{ 20000.0    ,  9.745 },
		{ 25000.0    ,  9.73  },
		{ 30000.0    ,  9.715 },
		{ 40000.0    ,  9.684 },
		{ 50000.0    ,  9.654 },
		{ 60000.0    ,  9.624 },
		{ 70000.0    ,  9.594 },
		{ 80000.0    ,  9.564 },
	};

	// Look up the value
	double gravity = linearInterpolation(gravityMapping, 
		sizeof(gravityMapping) / sizeof(gravityMapping[0]),
		altitude);

	return gravity;
}

// TODO: Add the rest of the mappings

double densityFromAltitude(double altitude)
{
	const Mapping densityMapping[] =
	{ // altidtude     density
		{0.0      , 1.2250000 },
	    {1000.0   , 1.1120000 },
		{2000.0   , 1.0070000 },
		{3000.0   , 0.9093000 },
		{4000.0   , 0.8194000 },
		{5000.0   , 0.7364000 },
		{6000.0   , 0.6601000 },
		{7000.0   , 0.5900000 },
		{8000.0   , 0.5258000 },
		{9000.0   , 0.4671000 },
		{10000.0  , 0.4135000 },
		{15000.0  , 0.1948000 },
		{20000.0  , 0.0889100 },
		{25000.0  , 0.0400800 },
		{30000.0  , 0.0184100 },
		{40000.0  , 0.0039960 },
		{50000.0  , 0.0010270 },
		{60000.0  , 0.0003097 },
		{70000.0  , 0.0000828 },
		{80000.0  , 0.0000185 }
	};

	// Look up the value
	double density = linearInterpolation(densityMapping,
		sizeof(densityMapping) / sizeof(densityMapping[0]),
		altitude);

	return density;
}

double dragFromMach(double mach)
{
	const Mapping dragMapping[] =
	{ // mach         drag
		{0.300      , 0.1629  },
		{0.500      , 0.1659  },
		{0.700      , 0.2031  },
		{0.890      , 0.2597  },
		{0.920      , 0.3010  },
		{0.960      , 0.3287  },
		{0.980      , 0.4002  },
		{1.000      , 0.4258  },
		{1.020      , 0.4335  },
		{1.060      , 0.4483  },
		{1.240      , 0.4064  },
		{1.530      , 0.3663  },
		{1.990      , 0.2897  },
		{2.870      , 0.2297  },
		{2.890      , 0.2306  },
		{5.000      , 0.2656  }
	};

	// Look up the value
	double drag = linearInterpolation(dragMapping,
		sizeof(dragMapping) / sizeof(dragMapping[0]),
		mach);

	return drag;
}

double speedOfSoundFromAltitude(double altitude)
{
	const Mapping speedOfSoundMapping[] =
	{ // altidtude     speed of sound
		{ 0            , 340        },
		{1000          , 336        },
		{2000          , 332        },
		{3000          , 328        },
		{4000          , 324        },
		{5000          , 320        },
		{6000          , 316        },
		{7000          , 312        },
		{8000          , 308        },
		{9000          , 303        },
		{10000         , 299        },
		{15000         , 295        },
		{20000         , 295        },
		{25000         , 295        },
		{30000         , 305        },
		{40000         , 324        }
	};

	// Look up the value
	double speedOfSound = linearInterpolation(speedOfSoundMapping,
		sizeof(speedOfSoundMapping) / sizeof(speedOfSoundMapping[0]),
		altitude);

	return speedOfSound;
}