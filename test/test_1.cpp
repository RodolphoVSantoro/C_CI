#include "../src/lib.h"
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

class SomaTest : public CPPUNIT_NS::TestCase
{
  SomaTest( std::string name ) : CppUnit::TestCase( name ) {}
  
  void testeSoma() {
    CPPUNIT_ASSERT( soma(10, 2) == 12 );
  }
};

  CPPUNIT_TEST_SUITE(SomaTest);
  CPPUNIT_TEST(testeSoma);
  CPPUNIT_TEST_SUITE_END();
  CPPUNIT_TEST_SUITE_REGISTRATION( MyTest );

int main(){

  CPPUNIT_NS::TestResult controller;

  CPPUNIT_NS::TestResultCollector result;
  controller.addListener(&result);

  CPPUNIT_NS::BriefTestProgressListener progress;
  controller.addListener(&progress);

  CPPUNIT_NS::TestRunner runner;
  runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
  runner.run(controller);

  return result.wasSuccessful() ? 0 : 1;
}
