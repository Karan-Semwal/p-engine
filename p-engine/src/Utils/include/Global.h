#pragma once
#include <string>

inline const int TILE_WIDTH  = 64;
inline const int TILE_HEIGHT = 64;

inline const int TILE_SCALE = 1;

inline const int TILE_WIDTH_SIZE  = TILE_WIDTH  * TILE_SCALE; 
inline const int TILE_HEIGHT_SIZE = TILE_HEIGHT * TILE_SCALE;

inline const int WINDOW_WIDTH  = TILE_WIDTH_SIZE  * 16;
inline const int WINDOW_HEIGHT = TILE_HEIGHT_SIZE * 9;

inline std::string LEVELS_DIR  = "../game/Levels/";
inline std::string TEXTURE_DIR = "../res/texture/";
inline std::string AUDIO_DIR   = "../res/audio/";

// 16 : 9