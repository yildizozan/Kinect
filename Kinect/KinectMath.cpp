﻿// Fundamentals
#include <iostream>

// Windows headers
#include <Windows.h>

// Kinect Api
#include "NuiApi.h"

// My Classes
#include "Organ.h"
#include "Kinect.h"
#include "KinectMath.h"


ozansKinect::KinectMath::KinectMath()
	:coordinateW(0), coordinateX(0), coordinateY(0), coordinateZ(0)
{
}

ozansKinect::KinectMath::~KinectMath()
{
}

//
//	FUNCTION:	fallibility
//
//	PURPOSE:	Percent of number
//
//	COMMENTS(TR):
//
//		Verilen yanılma paylarına göre sayı arasında bir yerde mi diye control eder.
//
bool ozansKinect::KinectMath::fallibility(const DWORD &border, const DWORD &percent, const DWORD &current)
{
	if ((border - percent) <= current && current <= (border + percent))
		return true;

	return false;
}

bool ozansKinect::KinectMath::fallibility(const DWORD &border, const DWORD &percent, const Vector4 &organ)

{
	if ((border - percent) <= organ.x && organ.x <= (border + percent))
		if ((border - percent) <= organ.y && organ.y <= (border + percent))
			return true;

	return false;
}

//
//	FUNCTION: Coordinate2Sens
//
//	PURPOSE:
//
//	COMMENTS:
//
Vector4 ozansKinect::KinectMath::getCoordinate2Sens(Vector4 &data)
{
	data.w = data.w * 10;
	data.x = data.x * 10;
	data.y = data.y * 10;
	data.z = data.z * 10;

	return data;
}

//
//	FUNCTION:	Coordinate3Sens
//
//	PURPOSE:	Transform coordinate 3 decimal number
//
//	COMMENTS:	asd
//
Vector4 ozansKinect::KinectMath::getCoordinate3Sens(Vector4 &data)
{
	data.w = data.w * 1000;
	data.x = data.x * 1000;
	data.y = data.y * 1000;
	data.z = data.z * 1000;

	return data;
}

// Setters and Getters
void ozansKinect::KinectMath::setCoordinateW(int newW)
{
	coordinateW = newW;
}

int ozansKinect::KinectMath::getCoordinateW() const
{
	return 0;
}

void ozansKinect::KinectMath::setCoordinateX(int newX)
{
	coordinateX = newX;
}

int ozansKinect::KinectMath::getCoordinateX() const
{
	return 0;
}

void ozansKinect::KinectMath::setCoordinateY(int newY)
{
	coordinateY = newY;
}

int ozansKinect::KinectMath::getCoordinateY() const
{
	return 0;
}

void ozansKinect::KinectMath::setCoordinateZ(int newZ)
{
	coordinateZ = newZ;
}

int ozansKinect::KinectMath::getCoordinateZ() const
{
	return 0;
}
