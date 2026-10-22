# Add an executable target named 'tick' using the source file 'tick.cpp'.
add_executable(tick.cpp)

# Link the executable with the required Windows libraries.
target_link_libraries(tick PRIVATE ole32 uuid)
