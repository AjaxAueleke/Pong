// Pong.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "bat.h"
#include "ball.h"
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    Clock clock;
    Time td = clock.restart();
    RenderWindow window(VideoMode(800, 600), "Pong",Style::Default);
    Ball ball(Vector2f(300, 50));
    Font font;
    if (font.loadFromFile("font/ds_digital/DS-DIGI.TTF"))
    {
        std::cout << "FONT loaded correctly" << std::endl;
    }
    Text text,text2;
    Text paused_text;

    paused_text.setFont(font);
    paused_text.setString("Press Enter to play");
    paused_text.setCharacterSize(30);
    paused_text.setFillColor(Color::White);
    paused_text.setPosition(300, 200);
    // select the font
    text.setFont(font); // font is a sf::Font
    text2.setFont(font);
    // set the string to display
    text.setString("LIVES : 3 SCORE : 0");
    text2.setString("");
    // set the character size
    text.setCharacterSize(32); // in pixels, not points!
    text2.setCharacterSize(32);
    // set the color
    text.setFillColor(sf::Color::White);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(Vector2f(670, 0));
    Bat bat(200, 500);
    bool paused = true;
    int score = 0;
    int lives = 3;
    std::string score_s;
    std::string lives_s;
    std::stringstream ss, ss2;
    std::string hud1, hud2;
    while (window.isOpen())
    { 
        hud1 = "LIVES : ";
        hud1.append(std::to_string(lives));
        hud2 = "SCORE : ";
        hud2.append(std::to_string(score));
        text.setString(hud1);
        text2.setString(hud2);
        
       // std::cout << hud << std::endl;
        Event event;
        while (window.pollEvent(event))
        {
          
            if (event.type == Event::Closed)
            {
                window.close();
            }
            
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::P)
                {
                    paused = true;
                }
                if (event.key.code == Keyboard::Enter)
                {
                    paused = false;
                    ball.setSpeed(20, 20);
                }
                    if (!paused)
                    {
                        if (event.key.code == Keyboard::Right)
                        {
                            bat.Move(20);
                        }
                        else if (event.key.code == Keyboard::Left)
                        {
                            bat.Move(-20);
                        }

                    
                    }
                if (event.key.code == Keyboard::Escape)
                {
                    window.close();
                }
            }
        }
       // std::cout << "ball pos " << ball.m_getShape().getPosition().y  << std::endl;
        if (!paused)
        {
            if (ball.m_getShape().getPosition().y > 600)
            {
               
                ball.setPosition(Vector2f(300, 50));
                lives = lives - 1;
                if (lives < 0)
                {
                    score = 0;
                    paused_text.setString("NO MORE LIVES LEFT! PRESS Enter");
                    paused = true;
                    lives = 3;
                }
                
            }
        }

        window.clear();
        
        if (!paused)
        {
            ball.move(td);

        }
        else
        {
            window.draw(paused_text);
        }
        score = ball.collision_bat(bat, td, score);
        ball.collision_sides();
        ball.collision_s();
        
        window.draw(ball.m_getShape());
        window.draw(text);
        window.draw(bat.m_getShape());
        window.draw(text2);
        window.display();

    }
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
