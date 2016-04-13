// KinectProject.cpp : Defines the entry point for the console application.

#include <iostream>
#include <Windows.h>
#include <NuiApi.h>

#include "KinectProcess.h"

int main()
{
	ozansKinect::KinectProcess kinect;
	kinect.Initialize();

	// E�er el hareketi belirtilen coordinatlara gelirse programdan ��kacak.
	kinect.ProcessSkeleton();

	return 0;
}