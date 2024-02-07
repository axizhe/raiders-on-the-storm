#include "raylib.h"
#include "event.h"

#define MAX_RAIN_DROPS 200

typedef struct RainDrop{
  Vector2 position;
  Color color;
  float speed;
  float length;
} RainDrop;


int main(){

  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight,"Riders on the storm");
  InitAudioDevice();

 //Ahora cargo los assets 
 //Musica . Voy a cargar varios sonidos
  Music lluvia1 = LoadMusicStream("lluvia_y_tormenta.wav"); //Lluvia con relampagos
 //Music lluvia2 = LoadMusicStream("rain2.mp3"); //Lluvia dentro del auto


  PlayMusicStream(lluvia1); //Abre el juego
  //i
  RainDrop rainDrops[MAX_RAIN_DROPS];

  //Aca pregenero la lluvia en aleatorio
  for (int i=0; i<MAX_RAIN_DROPS; i++){
    rainDrops[i].position.x = GetRandomValue(0,screenWidth);
    rainDrops[i].position.y = GetRandomValue(0,screenHeight);
    rainDrops[i].color = BLUE;
    rainDrops[i].speed = (float)GetRandomValue(50, 200)/50.0f;
    rainDrops[i].length = (float)GetRandomValue(5, 10);
  }

  SetTargetFPS(60);

  while(!WindowShouldClose()){
    UpdateMusicStream(lluvia1);
    BeginDrawing();
    ClearBackground(BLACK);
    
    for (int i=0; i<MAX_RAIN_DROPS; i++){
      rainDrops[i].position.y += rainDrops[i].speed;

      if (rainDrops[i].position.y > screenHeight){
        rainDrops[i].position.y = 0;
        rainDrops[i].position.x = GetRandomValue(0,screenWidth);
      }
      //rainDrops[i].color = Fade(rainDrops[i].color, 0.01f);
      DrawLineV(rainDrops[i].position, (Vector2){rainDrops[i].position.x,rainDrops[i].position.y + rainDrops[i].length}, rainDrops[i].color);
    }
    EndDrawing();
  }
  
  UnloadMusicStream(lluvia1);
  ////UnloadMusicStream(lluvia2);
  CloseWindow();


  return 0;
}
