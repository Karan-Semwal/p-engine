#pragma once

#define LOG(m) std::cout << m << std::endl // DBG

#include "Animation/Animator.h"
#include "AssetManager/TextureManager.h"
#include "Map/Tilemap.h"
#include "Physics/Hitbox.h"
#include "Ui/Bar.h"
#include "Ui/Button.h"
#include "Player/Player.h"
#include "Utils/Timer.h"
#include "Map/LevelManager.h"
#include "Player/PlayerState.h"
#include "Camera/Camera.h"
#include "Utils/Global.h"
#include "Utils/Util.h"

namespace pengine
{
    void init();
}