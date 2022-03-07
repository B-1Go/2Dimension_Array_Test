#pragma once

#define SINGLE(type) public:\
						static type* GetInst()\
							{\
								static type mgr;\
								return &mgr;\
							}\
					private:\
						type();\
						~type();\




enum class Diraction
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80,
};