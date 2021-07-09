add_executable(Hello
    main.cc
)

target_link_libraries(Hello
    ${GTKMM_LIBRARIES}
)
