#include "testApp.h"
#include "ofAppGlutWindow.h"

//#import "Syphon/Syphon.h"

int main() {
	ofAppGlutWindow window;
	ofSetupOpenGL(&window, 1280, 720, OF_WINDOW);
	ofRunApp(new testApp());
}
