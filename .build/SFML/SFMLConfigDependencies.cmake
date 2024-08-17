# in case of static linking, we must also define the list of all the dependencies of SFML libraries
if(SFML_STATIC_LIBRARIES)
    list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})

    include(CMakeFindDependencyMacro)

    # detect the OS
    if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
        set(FIND_SFML_OS_WINDOWS 1)
    elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
        set(FIND_SFML_OS_LINUX 1)

        if()
            set(FIND_SFML_USE_DRM 1)
        endif()
    elseif(${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
        set(FIND_SFML_OS_FREEBSD 1)
    elseif(${CMAKE_SYSTEM_NAME} MATCHES "Android")
        set(FIND_SFML_OS_ANDROID 1)
    elseif(${CMAKE_SYSTEM_NAME} MATCHES "iOS")
        set(FIND_SFML_OS_IOS 1)
    elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
        set(FIND_SFML_OS_MACOS 1)
    endif()

    # start with an empty list
    set(FIND_SFML_DEPENDENCIES_NOTFOUND)

    # SFML::System
    find_dependency(Threads)

    # SFML::Window
    list(FIND SFML_FIND_COMPONENTS "Window" FIND_SFML_WINDOW_COMPONENT_INDEX)
    if(FIND_SFML_WINDOW_COMPONENT_INDEX GREATER -1)
        if(FIND_SFML_USE_DRM)
            find_dependency(DRM)
            find_dependency(GBM)
        elseif(FIND_SFML_OS_LINUX OR FIND_SFML_OS_FREEBSD)
            find_dependency(X11 REQUIRED COMPONENTS Xrandr Xcursor)
        endif()

        if(FIND_SFML_OS_LINUX)
            find_dependency(UDev)
        endif()

        if(NOT FIND_SFML_OS_ANDROID AND NOT FIND_SFML_OS_IOS)
            if(NOT OpenGL_GL_PREFERENCE)
                set(OpenGL_GL_PREFERENCE "LEGACY")
            endif()
            find_dependency(OpenGL COMPONENTS OpenGL)
        endif()
    endif()

    # SFML::Graphics
    list(FIND SFML_FIND_COMPONENTS "Graphics" FIND_SFML_GRAPHICS_COMPONENT_INDEX)
    if(FIND_SFML_GRAPHICS_COMPONENT_INDEX GREATER -1)
        find_package(Freetype)
    endif()

    # SFML::Audio
    list(FIND SFML_FIND_COMPONENTS "Audio" FIND_SFML_AUDIO_COMPONENT_INDEX)
    if(FIND_SFML_AUDIO_COMPONENT_INDEX GREATER -1)
        find_package(Vorbis)
        find_package(FLAC)
    endif()

    if(FIND_SFML_DEPENDENCIES_NOTFOUND)
        set(FIND_SFML_ERROR "SFML found but some of its dependencies are missing (${FIND_SFML_DEPENDENCIES_NOTFOUND})")
        set(SFML_FOUND FALSE)
    endif()
endif()
