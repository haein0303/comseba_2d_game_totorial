#include <doodle/doodle.hpp>
#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace doodle;
using namespace std;
double                   angle{ 0.0 };
double                   grey{ 0 };
double                   x{ 0.0 };
double                   y{ 0.0 };

void on_mouse_moved(int mouse_x, int mouse_y)
{
    angle += to_radians(3.0);
    grey = 255 * (std::sin(angle) * 0.5 + 0.5);
    x = mouse_x;
    y = mouse_y;
}
bool shouldFollowMouse = false;
void on_mouse_pressed(MouseButtons button)
{
    if (button == MouseButtons::Left)
        shouldFollowMouse = true;
}

void on_mouse_released(MouseButtons button)
{
    if (button == MouseButtons::Left)
        shouldFollowMouse = false;
}

double distance(POINT input){
    POINT _delta{ input.x - x,input.y - y };

    double dis = sqrt(_delta.x * _delta.x + _delta.y * _delta.y);
    return dis;
}

int main(void)
{
    cout << "start program" << endl;
    create_window(Width, Height);
    const Image orangeHero{ "cat.png" };
    set_image_mode(RectMode::Center);
    float dgree = 0.f;

    Image walk_sprite[6];

    char filename[10];
    int walkcount = 0;

    float delta = 0.f;

    for (int i = 0; i < 6; ++i) {
        sprintf_s(filename, "%d.png", i + 1);
        walk_sprite[i] = Image((const char*)filename);
    }

    POINT elipse_location = { 0,0 };
    while (!is_window_closed())
    {
        update_window();
        clear_background(220);
        set_fill_color(grey);

        if (shouldFollowMouse && distance(elipse_location) < 100) {
            elipse_location.x = x;
            elipse_location.y = y;
        }
        
        draw_image(walk_sprite[walkcount], elipse_location.x , elipse_location.y, 300, 300);
        dgree += 5.f * DeltaTime;
        draw_image(orangeHero, elipse_location.x + sin(dgree) * 400, elipse_location.y + cos(dgree) * 400, 300, 300);
        if (delta > 1.f / 10.f) {
            delta = 0;
            walkcount = (walkcount + 1) % 6;
        }
        else {
            delta += DeltaTime;
        }
        dgree += 5.f * DeltaTime;
        
    }
    return 0;
}



