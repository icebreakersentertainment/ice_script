#include <vector>
#include <tuple>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

#include "Types.hpp"

namespace ice_script
{
namespace detail
{

// Original source: https://stackoverflow.com/questions/47086858/create-a-grid-in-opengl
inline std::tuple<std::vector<glm::vec3>, std::vector<uint32>> generateGrid(const uint32 width = 64, const uint32 height = 64, const glm::vec2& offset = glm::vec2(), const uint32 resolution = 1)
{
	std::vector<glm::vec3> vertices;
	std::vector<uint32> indices;
	
    for (uint32 j=0; j <= width; ++j)
    {
        for (uint32 i=0; i <= height; ++i)
        {
            float32 x = ((float32)i / (float32)resolution) + offset.x;
            float32 y = 0.0f;
            float32 z = ((float32)j / (float32)resolution) + offset.y;
            vertices.push_back(glm::vec3(x, y, z));
        }
    }

    for (uint32 j=0; j < width; ++j)
    {
        for (uint32 i=0; i < height; ++i)
        {
            const uint32 row1 = j * (height+1);
            const uint32 row2 = (j+1) * (height+1);

            // triangle 1
            indices.push_back(row1+i);
            indices.push_back(row1+i+1);
            indices.push_back(row2+i+1); 

            // triangle 2
            indices.push_back(row1+i);
            indices.push_back(row2+i+1);
            indices.push_back(row2+i); 
        }
    }
    
    return std::make_tuple(std::move(vertices), std::move(indices));
}

}
}
