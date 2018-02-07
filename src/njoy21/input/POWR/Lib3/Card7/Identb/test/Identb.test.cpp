#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib3, Card7, Identb",
          "[POWR] [Lib3] [Card7] [Identb]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( auto i : {-100, -1, 0, 1, 100} ){
        iRecordStream<char> iss( std::istringstream( std::to_string ( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< POWR::Lib3::Card7::Identb >(
                                                         iss, 1 ).value.at(0) );
        }
      }
    } // WHEN

    WHEN( "several valid values are provided" ){
      std::string test{ " " };
      int num_vals = 0;
      for( auto i : {-100, -1, 0, 1, 100} ){
        test = test + " " + std::to_string( i );
        num_vals++;
        iRecordStream<char> iss{ std::istringstream{ test } };

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< POWR::Lib3::Card7::Identb >(
                                                 iss, num_vals ).value.back() );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( " -101 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< POWR::Lib3::Card7::Identb >(iss, 1));
      }
    } // WHEN

    WHEN( "few value are provided than expected" ){
      iRecordStream<char> iss( std::istringstream( " -100 -99 -98 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< POWR::Lib3::Card7::Identb >(iss, 4));
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
