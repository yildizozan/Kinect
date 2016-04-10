﻿/*
*	Author: Ozan Yıldız
*/
#ifndef ORGAN_H
#define ORGAN_H

namespace ozansKinect
{
	class Organ
	{
		friend class Organ;

	public:
		Organ();
		~Organ();
		void printRightHandCoord(Vector4 []);
		void printLeftHandCoord(Vector4 []);


	private:
		Vector4 skeletonData;
	};
}

#endif // !ORGAN_H
