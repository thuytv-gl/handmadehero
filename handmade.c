#include "handmade.h"

global_variable char running = 1;

void scc(char code) {
    if (code < 0) {
        fprintf(stderr, "SDL ERROR: %s\n", SDL_GetError());
        exit(1);
    }
}

template <typename T> T* scp(T *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "SDL ERROR: %s\n", SDL_GetError());
        exit(1);
    }
    return ptr;
}

void prepare_scene(SDL_Renderer *renderer) {
    scc(SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255));
    scc(SDL_RenderFillRect(renderer, NULL));
}

void do_render(SDL_Renderer *renderer) {
    SDL_RenderPresent(renderer);
}

void window_event_handler(SDL_Window *window, SDL_Renderer *renderer,
        SDL_Event *event)
{
    switch(event->type)
    {
        case SDL_QUIT:
        {
            // TODO(thuytv): should we X out? or do something else?
            running = 0;
        } break;
        case SDL_WINDOWEVENT: {
            switch(event->window.event) {
                case SDL_WINDOWEVENT_RESIZED:
                {
                } break;
                default: break;
            }
        } break;
        case SDL_KEYDOWN:
        {
            switch(event->key.keysym.sym) {
                /**
                case SDLK_SPACE:
                {
                    snake_forward();
                } break;
                */
                default: break;
            }
        } break;
        default: break;
    }
}

void init_sdl() {
    scc(SDL_Init(SDL_INIT_VIDEO));
}

int main(int argc, char** argv) {
    init_sdl();
    SDL_Window* window = scp(SDL_CreateWindow(WINDOW_TITLE,
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                WINDOW_WIDTH,
                WINDOW_HEIGHT,
                SDL_WINDOW_RESIZABLE));
    SDL_Renderer* renderer = scp(SDL_CreateRenderer(window, -1,
                SDL_RENDERER_ACCELERATED));
    SDL_Event event;
    while(running) {
        while(SDL_PollEvent(&event)) {
            window_event_handler(window, renderer, &event);
        }
        prepare_scene(renderer);
        do_render(renderer);
        SDL_Delay(FRAME_RATE);
    }

    SDL_Log("Q U I T");
	SDL_Quit();
    return(0);
}

