// Standard lib
#include <iostream>
#include <Windows.h>

<<<<<<< HEAD
#include "KinectProcess.h"
=======
// Nui Api
#include "NuiApi.h"

// My Header
#include "Kinect.h"
>>>>>>> refs/remotes/origin/master


using namespace OzansKinect;

int main()
{
<<<<<<< HEAD
	ozansKinect::KinectProcess kinect;
	kinect.Initialize();

	// E�er el hareketi belirtilen coordinatlara gelirse programdan ��kacak.
	kinect.ProcessSkeleton();
=======
	Kinect kinect;
	
	HRESULT hr = kinect.Connection();
	if (SUCCEEDED(hr))
	{
		while (1)
			kinect.Process();
	}

>>>>>>> refs/remotes/origin/master

	return 0;
}