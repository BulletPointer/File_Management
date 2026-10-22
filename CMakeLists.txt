# Add an executable target named 'Lumina' using the source file 'Lumina.cpp'.
add_executable(Lumina Lumina.cpp)

# Link the executable with the required Windows libraries.
target_link_libraries(Lumina PRIVATE ole32 uuid)