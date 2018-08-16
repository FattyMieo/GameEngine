#pragma once

#include <fmod.hpp>
#include <fmod_errors.h>
#include <stdio.h>

//FMOD Error Check
static void FMOD_ErrorCheck(FMOD_RESULT result)
{
	if (result != FMOD_OK)
	{
		printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
	}
}
