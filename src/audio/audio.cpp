#include "stdafx.h"
#include "audio.h"

int getDevicesCount(int deviceType);
int getOutputDevicesCount();
int getInputDevicesCount();



int getDevicesCount(int deviceType)
{

	HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);


	IMMDeviceEnumerator *deviceEnumerator = NULL;

	//We initialize the device enumerator here
	hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER,
		IID_PPV_ARGS(&deviceEnumerator));

	IMMDeviceCollection *deviceCollection = NULL;

	//Here we enumerate the audio endpoints of interest (in this case audio capture endpoints)
	//into our device collection. We use "eCapture" for audio capture endpoints, "eRender" for 
	//audio output endpoints and "eAll" for all audio endpoints 
	if (deviceType == 1)
	{
		hr = deviceEnumerator->EnumAudioEndpoints(eRender, DEVICE_STATE_ACTIVE,
			&deviceCollection);
	}
	else
	{
		hr = deviceEnumerator->EnumAudioEndpoints(eCapture, DEVICE_STATE_ACTIVE,
			&deviceCollection);
	}

	UINT deviceCount;

	hr = deviceCollection->GetCount(&deviceCount);

	SafeRelease(&deviceCollection);
	SafeRelease(&deviceEnumerator);
	CoUninitialize();
	return 	deviceCount;
}

int getOutputDevicesCount()
{
	int count = getDevicesCount(1);

	return count;
}

int getInputDevicesCount()
{
	int count = getDevicesCount(2);

	return count;
}



