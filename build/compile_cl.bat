@ECHO OFF

del *.obj *.pdb *.ilk *.exe

cl /nologo /Zi /EHs /MDd /W4 -I ..\include -I ..\deps\sdl2\include -I ..\deps\imgui\ -I ..\deps\imgui_sdl -I ..\deps\sdl2_image\include -I ..\deps\sdl2_ttf\include -I ..\deps\sdl2_mixer\include /c ..\src\*.cc
cl /nologo /Zi /EHs /MDd /W4 /Fe: ..\bin\main.exe *.obj /link /SUBSYSTEM:CONSOLE ..\deps\sdl2\lib\x86\SDL2.lib ..\deps\sdl2\lib\x86\SDL2main.lib ..\deps\sdl2_image\lib\x86\SDL2_image.lib ..\deps\sdl2_mixer\lib\x86\SDL2_mixer.lib opengl32.lib shell32.lib user32.lib gdi32.lib

