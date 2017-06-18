#include <gtest/gtest.h>
#include <Utility/Utility.hpp>

TEST(OSCInput, DoesntLeak) {

    auto vec = std::vector<float>{0.f,0.f};
    auto glm_vec2 = glm::vec2{0.f,0.f};
    glm::vec2 etudes_vec2 = etudes::util::to_vec2(vec);

    ASSERT_EQ(glm_vec2, etudes_vec2);

    vec.push_back(0.f);
    auto glm_vec3 = glm::vec3{0.f,0.f,0.f};
    auto etudes_vec3 = etudes::util::to_vec3(vec);

    ASSERT_EQ(glm_vec3, etudes_vec3);

    vec.push_back(0.f);
    auto glm_vec4 = glm::vec4{0.f,0.f,0.f,0.f};
    auto etudes_vec4 = etudes::util::to_vec4(vec);

    ASSERT_EQ(glm_vec4, etudes_vec4);
}
