#ifndef _FMOD_MANAGER_H
#define _FMOD_MANAGER_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "fmod_studio.h"

bool InitFmod();
bool UpdateFmod();
bool ReleaseFmod();

int LoadBank(const char* path);

int GetBus(const char* path);
bool SetBusVolume(int key, float volume);
float GetBusVolume(int key);
bool SetBusMute(int key, FMOD_BOOL mute);
bool GetBusMute(int key);

int GetVCA(const char* path);
bool SetVcaVolume(int key, float volume);
float GetVcaVolume(int key);

int CreateInstance(const char* path);
bool PlayOneShotEvent(const char* path);
bool PlayEvent(int key);
bool StopEvent(int key);
bool PauseEvent(int key, FMOD_BOOL paused);
bool EventIsPlaying(int key);
//FMOD_RESULT F_CALLBACK EventMarkerCallback(FMOD_STUDIO_EVENT_CALLBACK_TYPE type, FMOD_STUDIO_EVENTINSTANCE *event, FMOD_STUDIO_TIMELINE_MARKER_PROPERTIES *parameters);
//bool SetEventMarkerCallback(void(*func)(const char* name), int key);

float GetParamaterByName(int key, const char* name);
bool SetParamaterByName(int key, const char* name, float value);
float GetGlobalParamaterByName(const char* name);
bool SetGlobalParamaterByName(const char* name, float value);

#endif