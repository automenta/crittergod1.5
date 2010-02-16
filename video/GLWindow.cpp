#include "GLWindow.h"

GLWindow::GLWindow()
{
}

void GLWindow::create(const char* title, int width, int height)
{

	if( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		cerr << "Video initialization failed: " << SDL_GetError() << endl;
		exit(1);
	}
	vidInfo = SDL_GetVideoInfo();
	
	w_bpp = vidInfo->vfmt->BitsPerPixel;
	
	if ( !vidInfo )
	{
		cerr << "Cannot get video information: " <<  SDL_GetError() << endl;
		exit(1);
	}

	vidFlags = SDL_OPENGL | SDL_GL_DOUBLEBUFFER | SDL_HWPALETTE;

	hwaccel = false;
	if( vidInfo->hw_available )
	{
		hwaccel = true;
		vidFlags |= SDL_HWSURFACE;
	}
	else
		vidFlags |= SDL_SWSURFACE;

        if( vidInfo->blit_hw != 0 )
                vidFlags |= SDL_HWACCEL;

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 4);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 4);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 4);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 4);
// 	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDL_WM_SetCaption(title, 0);

	w_width = width;
	w_height = height;

	n_width = width;
	n_height = height;

	//Settings::Instance()->winWidth = &w_width;
	//Settings::Instance()->winHeight = &w_height;

	//settingsfs = Settings::Instance()->getCVarPtr("fullscreen");

	fs = 0; //*settingsfs;

	if ( fs == 1 )
		surface = SDL_SetVideoMode( w_width, w_height, w_bpp, vidFlags | SDL_FULLSCREEN );
	else
		surface = SDL_SetVideoMode( w_width, w_height, w_bpp, vidFlags | SDL_RESIZABLE );

	cerr << "SDL: subsystem initalized\n";
// 	cerr << "Video " << front.width() << "x" << front.height() << "x" << int(front.getSurface()->format->BitsPerPixel) << "\n";
// 	cerr << "Render Mode: " <<  ((hwaccel) ? "Direct Rendering" : "Software Rendering")   << "\n";
// 	cerr << "Hardware Blit Acceleration: " << ((vidInfo->blit_hw) ? "Yes": "No") << "\n";
}

void GLWindow::resize()
{
	if ( w_height == 0 ) w_height = 1;
	if ( w_width == 0 ) w_width = 1;

#ifndef _WIN32
	SDL_FreeSurface(surface);
	surface = SDL_SetVideoMode( w_width, w_height, w_bpp, vidFlags | SDL_RESIZABLE );
#endif

	spacetime->resize(w_width, w_height);
}

void GLWindow::toggleFs()
{
	if ( fs )
	{
		if ( w_height == 0 ) w_height = 1;
		if ( w_width == 0 ) w_width = 1;

		SDL_FreeSurface(surface);
		n_width = w_width;
		n_height = w_height;
		//w_width = Settings::Instance()->getCVar("fsX");
		//w_height = Settings::Instance()->getCVar("fsY");

		surface = SDL_SetVideoMode( w_width, w_height, w_bpp, vidFlags | SDL_FULLSCREEN );
		Displaylists::Instance()->generateList();
		//Textprinter::Instance()->setUpFonts();
	}
	else
	{
		SDL_FreeSurface(surface);
		w_width = n_width;
		w_height = n_height;

		surface = SDL_SetVideoMode( w_width, w_height, w_bpp, vidFlags | SDL_RESIZABLE );

		Displaylists::Instance()->generateList();
		//Textprinter::Instance()->setUpFonts();
	}
}

int runFunc(void* vs) {

}

void GLWindow::start(Spacetime* s) {
	spacetime = s;

	s->init(w_width, w_height);

	bool stop = false;

	while(!stop)
	{
		while(SDL_PollEvent(&event)) 	{

	      if(event.type == SDL_VIDEORESIZE)
			{
				w_width = event.resize.w;
				w_height = event.resize.h;
	            resize();
			}
			else if(event.type == SDL_QUIT)
				stop = true;
			else {
				s->forward(&event);
			}
		}



//		if ( fs != *settingsfs )
//		{
//			fs = *settingsfs;
//			toggleFs();
//		}

		s->draw();
	}

    SDL_Quit();

//    thread = SDL_CreateThread(runFunc, this);
//    if ( thread == NULL ) {
//        fprintf(stderr, "Unable to create thread: %s\n", SDL_GetError());
//        return;
//    }

//    for ( i=0; i<5; ++i ) {
//        printf("Changing value to %d\n", i);
//        global_data = i;
//        SDL_Delay(1000);
//    }
//
//    printf("Signaling thread to quit\n");
//    global_data = -1;
//    SDL_WaitThread(thread, NULL);
}


GLWindow::~GLWindow()
{

}


