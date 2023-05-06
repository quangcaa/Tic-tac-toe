#include "Headers/Run.h"

void run()
{
    bool run = true;
    while (run && running)
    {
        string mode;
        modeSelected = false;
        while (!modeSelected && running)
        {
            modegame(mode); // display mode selection

            if (mode == "vs computer" || mode == "vs player") // check if a valid mode was selected
            {
                modeSelected = true;
            }
        }

        clicked_home = false;
        while (!clicked_home && running)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT || event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                {
                    running = false;
                    run = false;

                    cout << run << " " << running << endl;
                }
                else
                {
                    if (mode == "vs computer")
                    {
                        handleVsComputer(event);
                    }
                    else if (mode == "vs player")
                    {
                        handleVsPlayer(event);
                    }
                }
            }

            draw();
        }
    }
}