// KinectProject.cpp : Defines the entry point for the console application.

#include <iostream>
#include <Windows.h>
#include <NuiApi.h>

#include "Kinect.h"

int main()
{
	ozansKinect::Kinect kinect;
	kinect.Initialize();

	// E�er el hareketi belirtilen coordinatlara gelirse programdan ��kacak.
	kinect.ProcessSkeleton();

	return 0;
}