#include "Math.h"

#include <math.h>

namespace Math
{
	double ConvertToRadians(double degrees)
	{
		return (degrees * PI) / 180;
	}

	double ConvertToDegrees(double radians)
	{
		return (radians * 180) / PI;
	}

	Vector3 RotatePoint(Vector3 point, Vector3 pivot, float rotation)
	{
		double radianRotation = ConvertToRadians(rotation);
		double _sin = sin(radianRotation);
		double _cos = cos(radianRotation);

		point = point - pivot;
		float newX = (float)(point.x * _cos - point.y * _sin);
		float newY = (float)(point.x * _sin + point.y * _cos);

		point.x = newX + pivot.x;
		point.y = newY + pivot.y;

		return point;
	}

	float Min(vector<float> x)
	{
		float retVal = x[0];

		for (int i = 1; i < x.size(); i++)
		{
			if (x[i] < retVal)
				retVal = x[i];
		}

		return retVal;
	}

	float Max(vector<float> x)
	{
		float retVal = x[0];

		for (int i = 1; i < x.size(); i++)
		{
			if (x[i] > retVal)
				retVal = x[i];
		}

		return retVal;
	}
}