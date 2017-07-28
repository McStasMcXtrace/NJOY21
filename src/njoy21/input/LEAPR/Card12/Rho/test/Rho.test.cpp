#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Rho input values",
  "[Card12], [Rho]" ){
  GIVEN( "a small value for ni" ){
    Argument< LEAPR::Card11::Ni > ni;
    ni.value = 3;

    WHEN( "there are the correct number of rhos and they are valid" ){
      iRecordStream< char> iss( std::istringstream(" 1.0 2.0 3.0") );

      THEN( "the rho values can be extracted correctly" ){
        auto rhos = argument::extract< 
          LEAPR::Card12::Rho >(iss, ni);
        std::vector< double > refRhos{ 1.0, 2.0, 3.0 };
        REQUIRE( refRhos == rhos.value );
      } // THEN
    } // WHEN
    WHEN( "the rho values are invalid" ){
      iRecordStream< char> iss( std::istringstream("-1.0 2.0 3.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< 
          LEAPR::Card12::Rho >( iss, ni ) );
      } // THEN
    } // WHEN
    WHEN( "too few rho values are provided" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract<
          LEAPR::Card12::Rho >( iss, ni ) );
      } // THEN
    } // WHEN
    WHEN( "too many rho values are provided" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0 3.0 4.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_NOTHROW( argument::extract<
          LEAPR::Card12::Rho >( iss, ni ) );
      } // THEN
    } // WHEN
  } // GIVEN

  GIVEN( "a larger value for ni" ){
    Argument< LEAPR::Card11::Ni > ni;
    ni.value = 15;

    WHEN( "there are the correct number of rhos and they are valid" ){
      iRecordStream< char> iss( std::istringstream(
      ".010 .015 .025 .035 .050 .075 .101 .150\n"
      "2.5e-1 3.3e-1  5.04e-1 7.56e-1 1.01e+0 1.26e+0 1.51e+0/"
      ) );

      THEN( "the rho values can be extracted correctly" ){
        auto rhos = argument::extract< 
          LEAPR::Card12::Rho >(iss, ni);
        std::vector< double > refRhos{.01, .015, .025, .035, .05,
          .075, .101, .150, .25, .33, .504, .756, 1.01, 1.26, 1.51};
        REQUIRE( refRhos == rhos.value );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
