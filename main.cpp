#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    const float FPS = 60.0f;
    int x = 100;
    int max = 0;
    int y =150;
    int x1 = 700, x2 = 838;
    int y1 = 375, y2 = 127;
    float spF = 0;
    int x_p;
    float spp = 2.5;
    float rsm=0;
    auto score = 0;
    int type = 0;
    bool is_start_new_game = false;
    RenderWindow window(VideoMode(700,504),"FLAPPY BIRD");
    window.setFramerateLimit(FPS);

    Font font;
    font.loadFromFile("./score.ttf");
    Text text;
    text.setFont(font);
    text.setPosition(10,10);
    text.setFillColor(Color::White);

    Text text_over;
    text_over.setFont(font);
    text_over.setPosition(180,200);
    text_over.setFillColor(Color::Red);
    text_over.setScale (2.5 , 2.5);

    Text text_max;
    text_max.setFont(font);
    text_max.setPosition(0,0);
    text_max.setFillColor(Color::White);
    text_max.setScale(1.5,1.5);

    Text curtain_score;
    curtain_score.setFont(font);
    curtain_score.setPosition(0, 50);
    curtain_score.setFillColor(Color::White);
    curtain_score.setScale(1.5, 1.5);

    Text text_restart;
    text_restart.setFont(font);
    text_restart.setPosition(160,280);
    text_restart.setFillColor(Color::Red);

    Text game_start;
    game_start.setFont(font);
    game_start.setPosition(200,180);
    game_start.setFillColor(Color::White);
    game_start.setScale(1.1 , 1.1);

    Texture hero_texture;
    hero_texture.loadFromFile ("./duck.png");

    Texture hero_texture1;
    hero_texture1.loadFromFile ("./duck1.png");

    Texture hero_texture2;
    hero_texture2.loadFromFile ("./duck2.png");

    Texture hero_texture3;
    hero_texture3.loadFromFile ("./duck3.png");

    Texture Get_Ready;
    Get_Ready.loadFromFile ("./get_ready.png");

    Texture backGround_Texture;
    backGround_Texture.loadFromFile("./ff.png");   //дневной фон

    Texture backGround_Texture_night;
    backGround_Texture_night.loadFromFile("./ff2.png");

    Texture backGround_Over;
    backGround_Over.loadFromFile("./game_over.png");  //конец игры

    Texture pipe_texture;
    pipe_texture.loadFromFile("./pipe.png");

    SoundBuffer sfx_die;
    sfx_die.loadFromFile("./sfx_die.ogg");// помер
    Sound sound_die;
    sound_die.setBuffer(sfx_die);

    SoundBuffer sfx_point;
    sfx_point.loadFromFile("./sfx_point.ogg");// прибавляем score
    Sound sound_point;
    sound_point.setBuffer(sfx_point);


    SoundBuffer sfx_swooshing;
    sfx_swooshing.loadFromFile("./sfx_swooshing.ogg");// при перезапуске игры
    Sound sound_swooshing;
    sound_swooshing.setBuffer(sfx_swooshing);


    SoundBuffer sfx_wing;
    sfx_wing.loadFromFile("./sfx_wing.ogg");// взмах
    Sound sound_wing;
    sound_wing.setBuffer(sfx_wing);


    Sprite hero;
    Sprite hero1;
    Sprite hero2;
    Sprite background;
    Sprite background1;
    Sprite pipe;
    Sprite pipe1;
    Sprite background_night;
    Sprite background1_night;
    Sprite get_ready;

    pipe.setTexture(pipe_texture);
    pipe1.setTexture(pipe_texture);
    pipe1.setRotation(180);
    pipe1.setPosition(x2 , y2);
    pipe.setPosition(x1 , y1);

    background.setTexture(backGround_Texture);
    background.setPosition(0 , 0);
    background1.setTexture(backGround_Texture);
    background1.setPosition(700 , 0);
    background1.setScale(2.5 , 3);
    background.setScale(2.5 , 3);

    background_night.setTexture(backGround_Texture_night);
    background_night.setPosition(0 , 0);
    background1_night.setTexture(backGround_Texture_night);
    background1_night.setPosition(700 , 0);
    background_night.setScale(2.3 , 2.3);
    background1_night.setScale(2.3 , 2.3);

    get_ready.setTexture(Get_Ready);
    get_ready.setPosition(200, 100);

    hero.setTexture(hero_texture);
    hero.setPosition(x , y);
    hero.setScale(0.4 , 0.4);

    hero1.setTexture(hero_texture1);
    hero1.setPosition(x , y);
    hero1.setScale(0.4 , 0.4);

    hero2.setTexture(hero_texture2);
    hero2.setPosition(x , y);
    hero2.setScale(0.4 , 0.4);

    rsm -= 10;

    Event event;

    while(window.isOpen())
    {
		/////
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
                window.close();

            if(event.type == Event::KeyPressed)
            {

                if (event.key.code == Keyboard::Space)
                    spF = -7.5;
                    sound_wing.play();
            }
            if (event.type == Event::KeyReleased)
            {

                if (event.key.code == Keyboard::R)
                {
                    is_start_new_game = false;
                    hero.setPosition(x,y);
                    score = 0;
                    sound_die.play();
                    pipe.setPosition(x1,y1);
                    pipe1.setPosition(x2,y2);
                    background.setPosition(0 , 0);
                    background1.setPosition(700 , 0);
                    window.draw(get_ready);
                }
                if (event.key.code == Keyboard::Escape)
                {
                    window.close();
                }
            }
        }
        type=rand() % 3+1;
		if(type == 1)
		{
			y2=202-rsm;
			y1=440+rsm;
		}
		if(type == 2)
		{
			y2=127-rsm;
			y1=375+rsm;
		}
		if(type == 3)
		{
			y2=62-rsm;
			y1=300+rsm;
		}
        spF+=0.5;
        hero.move(0, spF);
        hero.setRotation(static_cast<int>(spF - 2.5) % 90);
        pipe.move(spp*-10,0);
        pipe1.move(spp*-10,0);
        spp+=0,04;
        background.move(-0.4,0);
        background1.move(-0.4,0);
        if(background.getPosition().x <= -700)
            background.setPosition(700, 0);
        if(background1.getPosition().x <= -700)
            background1.setPosition(700, 0);
        x_p = pipe1.getPosition().x;
        if(x_p < 0)
        {
            pipe.setPosition(x1,y1);
            pipe1.setPosition(x2,y2);
            score++;

             if (score > max)
            max =  score;
        if (max >=1 ) //меняем текстуру
            hero_texture = hero_texture1;
            sound_point.play();

        if (max >=2 ) //меняем текстуру
            hero_texture = hero_texture2;
            sound_point.play();

        if (max >=3 ) //меняем текстуру
            hero_texture = hero_texture3;
            sound_point.play();

        }

        if((hero.getPosition().y<=-100) || (hero.getPosition().y>=430) || (is_start_new_game) || ((hero.getGlobalBounds().intersects(pipe.getGlobalBounds())|| (hero.getGlobalBounds().intersects(pipe1.getGlobalBounds())))))

					{
                    sound_point.pause();
                    score = 0;
                    spp = 2.5;
					window.clear();
					background.setPosition(0,0);
                    window.draw(background);
                    text_max.setString("Max score " + to_string(max));
                    text_over.setString("GAME OVER");
                    text_restart.setString("Press R to restart the game");
                    window.draw(text_over);
                    window.draw(text_restart);
                    window.draw(text_max);
					is_start_new_game=true;
					window.display();
              }

        else
                {
                    text.setString("Score " + to_string(score));
                    window.clear();
                    window.draw(background1);
                    window.draw(background);
                    window.draw(pipe);
                    window.draw(pipe1);
                    window.draw(hero);
                    window.draw(text);
                    window.display();
                }


    }

    return 0;
}
