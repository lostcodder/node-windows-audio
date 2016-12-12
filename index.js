const windowsaudio = require('./build/Release/windowsaudio');

console.log(windowsaudio.getOutputDevicesCount());
console.log(windowsaudio.getInputDevicesCount());