#pragma once

// Game Logic
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800
#define SPLASH_TIME 1
#define OBSTACLE_SPEED 200.0f
#define CACTUS_SPAWN_SPEED 3.0f
#define BIRD_SPAWN_SPEED 7.0f
#define DINO_ANIM_SPEED 0.3f
#define DINO_STATE_STILL 1
#define DINO_STATE_JUMP 2
#define DINO_STATE_FALL 3
#define GRAVITY 350.0f
#define JUMP_SPEED 350.0f
#define JUMP_DURATION 0.6f

enum GameStates {
	gameReady, gameOver
};

// Asset Paths
#define SPLASH_BACKGROUND_PATH "D:/School/Progra3/RetroEngine3/RetroEngine3/res/splashbg.jpg"
#define MAIN_BACKGROUND_PATH "D:/School/Progra3/RetroEngine3/RetroEngine3/res/bg-game.jpg"
#define BIRD1_PATH "D:/School/Progra3/RetroEngine3/RetroEngine3/res/Bird_01.png"
#define BIRD2_PATH "D:/School/Progra3/RetroEngine3/RetroEngine3/res/Bird_02.png"
#define CACTUSL_PATH "D:/School/Progra3/RetroEngine3/RetroEngine3/res/Cactus_Large_Single.png"
#define CACTUSS_PATH "D:/School/Progra3/RetroEngine3/RetroEngine3/res/Cactus_Small_Single.png"
#define DINO1_PATH "D:/School/Progra3/RetroEngine3/RetroEngine3/res/Dino_Run01.png"
#define DINO2_PATH "D:/School/Progra3/RetroEngine3/RetroEngine3/res/Dino_Run02.png"
#define GROUND_PATH "D:/School/Progra3/RetroEngine3/RetroEngine3/res/Ground.png"

// UI Paths
#define RETRY_PATH "D:/School/Progra3/RetroEngine3/RetroEngine3/res/Retry.png"
#define	NEW_GAME_PATH "D:/School/Progra3/RetroEngine3/RetroEngine3/res/New game Button.png"
#define QUIT_PATH "D:/School/Progra3/RetroEngine3/RetroEngine3/res/Quit Button.png"
#define HOME_PATH "D:/School/Progra3/RetroEngine3/RetroEngine3/res/Home Square Button.png"
#define MENU_PATH "D:/School/Progra3/RetroEngine3/RetroEngine3/res/Menu Button.png"
#define FONT_PATH "D:/School/Progra3/RetroEngine3/RetroEngine3/res/Roboto-Bold.ttf"