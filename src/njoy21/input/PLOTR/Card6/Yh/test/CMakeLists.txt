
add_executable( njoy21.input.PLOTR.Card6.Yh.test Yh.test.cpp )
target_compile_options( njoy21.input.PLOTR.Card6.Yh.test PRIVATE ${${PREFIX}_common_flags}
$<$<BOOL:${strict}>:${${PREFIX}_strict_flags}>$<$<CONFIG:DEBUG>:
${${PREFIX}_DEBUG_flags}
$<$<BOOL:${coverage}>:${${PREFIX}_coverage_flags}>>
$<$<CONFIG:RELEASE>:
${${PREFIX}_RELEASE_flags}
$<$<BOOL:${link_time_optimization}>:${${PREFIX}_link_time_optimization_flags}>
$<$<BOOL:${nonportable_optimization}>:${${PREFIX}_nonportable_optimization_flags}>>

${CXX_appended_flags} ${njoy21_appended_flags} )
target_link_libraries( njoy21.input.PLOTR.Card6.Yh.test PUBLIC njoy21 ) 
add_test( NAME njoy21.input.PLOTR.Card6.Yh COMMAND njoy21.input.PLOTR.Card6.Yh.test )