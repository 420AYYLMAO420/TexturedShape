#include "App.h"

int main()
{
    //create instance of App
    App* app = new App();

    //run app
    if (app != nullptr) {
        app->Run();
        delete app;
    }
    else
        return -1;
 
    //return 0 if no non-OpenGL errors occurred
    return 0;
}