#include <iostream>
#include "raylib.h"
#include "Agent.h"
#include "Test.h"

using namespace test;

class Scene;

void TreeBehaviorTest::start()
{
    Scene::start();

    TestSuite& testSuite = TestSuite::getInstance();
    // testSuite.setVerbose(true);

    bool allPassed = testSuite.runAllTests();
    std::cerr << (allPassed ? "Success." : "Failure!") << std::endl;
    return allPassed ? 0 : 1;
}