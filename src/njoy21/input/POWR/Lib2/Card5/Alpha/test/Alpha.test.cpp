#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib2, Card5, Alpha",
          "[POWR] [Lib2] [Card5] [Alpha]" ){
  GIVEN( "valid inputs" ){
    for( double d : {0.0, 0.1, 1.0, 10.0} ){
      std::string situ( "valid input " + std::to_string(d) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "the values can be verified" ){
          REQUIRE( Approx( d ) == argument::extract< POWR::Lib2::Card5::Alpha >(
                                                                  iss ).value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( Approx( 0.0 ) == argument::extract< POWR::Lib2::Card5::Alpha >(
                                                                  iss ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    for( double d : {-10.0, -1.0, -0.1} ){
      std::string situ( "invalid input " + std::to_string(d) + " is provided.");
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( std::to_string( d ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< POWR::Lib2::Card5::Alpha >( iss ));
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
