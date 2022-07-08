#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

#include <stb_image.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include "core/Input/Input.h"
#include "core/graphics/API/Buffers.hpp"
#include "core/graphics/API/Shader/Shader.hpp"
#include "core/Window.hpp"
#include "core/Component.hpp"
#include "core/Components/InputCapture.h"
#include "Entities/Camera.hpp"
#include "core/Log.h"
#include "util/FileIO.hpp"
#include "spdlog/spdlog.h"
