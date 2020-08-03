# TexturedShape
Applying textures to 2D geometry in OpenGL.

This project contains a rectangle in which two textures have been applied to it.
The textures have been interpolated so that both textures can be seen at the same time
inside the geometry.

The following API and libraries were used:
-[OpenGL](https://www.opengl.org/) for rendering
-[GLFW](https://www.glfw.org/) for window management
-[stb_image](https://github.com/nothings/stb/blob/master/stb_image.h) for image loading

If you wish to apply your own textures, just change the following code in Graphics.cpp:
TextureObj->Textures.emplace_back("resources/JamaicanAinsley.png", "texture1");
TextureObj->Textures.emplace_back("resources/PepperedAinsley.png", "texture2");

to

TextureObj->Textures.emplace_back("resources/insert file path of texture 1.png", "texture1");
TextureObj->Textures.emplace_back("resources/insert file path of texture 2.png", "texture2");

Then, add your images inside the resources folder.
