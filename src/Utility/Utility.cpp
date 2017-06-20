#include <gtest/gtest.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/ext.hpp>
#include <Utility/Utility.hpp>

TEST(Utility, ConvertsToGLMVecs) {

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

TEST(Utility, SplitString) {
    std::string s = "/first/rest/of/string";

    auto first = etudes::util::splitStringFirst(s);
    ASSERT_EQ(first, "/first");

    auto rest = etudes::util::splitStringRest(s);
    ASSERT_EQ(rest, "rest/of/string");
}

TEST(Utility, DegToRad) {
    ASSERT_EQ(etudes::util::deg2rad(0), 0);
    ASSERT_EQ(etudes::util::deg2rad(180), glm::pi<float>());
    ASSERT_EQ(etudes::util::deg2rad(360), 2 * glm::pi<float>());
    ASSERT_EQ(etudes::util::deg2rad(720), 4 * glm::pi<float>());

    ASSERT_EQ(etudes::util::deg2rad(-180), -1 *glm::pi<float>());
    ASSERT_EQ(etudes::util::deg2rad(-360), -2 * glm::pi<float>());
    ASSERT_EQ(etudes::util::deg2rad(-720), -4 * glm::pi<float>());
}

TEST(Utility, RadToDeg) {
    ASSERT_EQ(etudes::util::rad2deg(0), 0);
    ASSERT_EQ(etudes::util::rad2deg(glm::pi<float>()), 180);
    ASSERT_EQ(etudes::util::rad2deg(glm::pi<float>() * 2), 360);
    ASSERT_EQ(etudes::util::rad2deg(glm::pi<float>() * 4), 720);

    ASSERT_EQ(etudes::util::rad2deg(glm::pi<float>() * -1), -180);
    ASSERT_EQ(etudes::util::rad2deg(glm::pi<float>() * -2), -360);
    ASSERT_EQ(etudes::util::rad2deg(glm::pi<float>() * -4), -720);
}

// don't really know how to test this...
//TEST(Utility, ElapsedTime) {
//
//}

//TEST(Utility, GLErrors) {
//
//}
//
//TEST(Utility, registerDefautlShaders) {
//
//}
