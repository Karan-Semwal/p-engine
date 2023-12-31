#pragma once
#include <string>

inline const int TILE_WIDTH  = 64;
inline const int TILE_HEIGHT = 64;

inline const int TILE_SCALE = 1;

inline const int TILE_WIDTH_SIZE  = TILE_WIDTH  * TILE_SCALE; 
inline const int TILE_HEIGHT_SIZE = TILE_HEIGHT * TILE_SCALE;

inline const int WINDOW_WIDTH  = TILE_WIDTH_SIZE  * 16;
inline const int WINDOW_HEIGHT = TILE_HEIGHT_SIZE * 9;

inline const int WINDOW_CENTER_X = WINDOW_WIDTH  / 2.f;
inline const int WINDOW_CENTER_Y = WINDOW_HEIGHT / 2.f;

inline const float BUTTON_W = 100.f;
inline const float BUTTON_H = 50.f;

constexpr inline int TOTAL_NUMBER_OF_LEVELS = 3;

inline std::string LEVELS_DIR  = "../game/Levels/";
inline std::string TEXTURE_DIR = "../res/texture/";
inline std::string AUDIO_DIR   = "../res/audio/";

// 16 : 9