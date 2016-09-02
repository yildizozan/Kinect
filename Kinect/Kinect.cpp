// Standard lib
#include <iostream>
#include <Windows.h>

// OpenGL
#include <gl/glut.h>

// Nui Api
#include "NuiApi.h"

// My Header
#include "Kinect.h"


OzansKinect::Kinect::Kinect()
	:mNuiSensor(NULL)
{
}


OzansKinect::Kinect::~Kinect()
{
	if (mNuiSensor)
	{
		mNuiSensor->NuiShutdown();
	}
}

HRESULT OzansKinect::Kinect::Connection()
{
	INuiSensor* pNuiSensor;

	int iSensorCount = 0;
	HRESULT hr = NuiGetSensorCount(&iSensorCount);
	if (FAILED(hr))
	{
		return hr;
	}

	// Look at the kinect
	for (int i = 0; i < iSensorCount; ++i)
	{
		// Create a sensor for check
		hr = NuiCreateSensorByIndex(i, &pNuiSensor);
		if (FAILED(hr))
		{
			continue;
		}

		// Get the status sensor
		hr = pNuiSensor->NuiStatus();
		if (S_OK == hr)
		{
			mNuiSensor = pNuiSensor;
			break;
		}

		// We can release temproray variable
		pNuiSensor->Release();
	}

	if (mNuiSensor != NULL)
	{
		// Initialize the Kinect for skeleton mod
		mNuiSensor->NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON);
	}

	if (mNuiSensor == NULL || FAILED(hr))
	{
		std::cout << "Kinect not found!" << std::endl;
		return E_FAIL;

	}

	return hr;
}

HRESULT OzansKinect::Kinect::Process()
{
	NUI_SKELETON_FRAME skeletonFrame;

	HRESULT hr = mNuiSensor->NuiSkeletonGetNextFrame(0, &skeletonFrame);
	if (FAILED(hr))
	{
		return hr;
	}

	// Smooth skeleton data
	mNuiSensor->NuiTransformSmooth(&skeletonFrame, NULL);

	for (int i = 0; i < NUI_SKELETON_COUNT; i++)
	{
		NUI_SKELETON_TRACKING_STATE trackingState = skeletonFrame.SkeletonData[i].eTrackingState;
		if (trackingState == NUI_SKELETON_TRACKED)
		{
			Draw(skeletonFrame.SkeletonData[i]);
		}
	}
	system("CLS");

	return S_OK;
}

void OzansKinect::Kinect::Draw(const NUI_SKELETON_DATA &skeletonData)
{
	glClear(GL_COLOR_CLEAR_VALUE);
	glBegin(GL_POINT);
	glPointSize(2);
	for (int i = 0; i < NUI_SKELETON_POSITION_COUNT; i++)
	{
		glVertex3f(skeletonData.SkeletonPositions[i].x, skeletonData.SkeletonPositions[i].x, skeletonData.SkeletonPositions[i].x);
	}
	glEnd();

	glFlush();
}