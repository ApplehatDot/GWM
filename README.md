# GWM
GWM_GL (GUI Window Manager for OpenGL) - a simple cross-platform windowing system for use with simple messageboxes and/or windows without system-specific libraries (like WinAPI etc.) 

Confirmed working on Windows and Linux
<div>
	<image src="Photos/Linux.png" width=400> 
	<image src="Photos/Windows.png" width=400>
</div>
Any contribution would be nice :D

# Using GWM in your project
_for more info, see Example.c_



GWM uses 2 `structs` - `GWMConfig`, `WindowPosition`:

```c
typedef struct {
	float PosX;  // GWM Window X Position
	float PosY;  // GWM Window Y Position
} WindowPosition;

typedef struct {
	float WinX;  // GWM Window X Resolution
	float WinY;  // GWM Window Y Resolution
	char* DESC;  // Description; displayed text
	float DescX;  // Texts X Position
	float DescY;  // Texts Y Position
} GWMConfig;
```
`PosX, PosY` must be defined in your project like this:
```c
// Value(s) can be changed up to your needs.
#define PosX 100.0f
#define PosY 100.0f
```
These values will be then passed down when defining structs:
```c
WindowPosition WP = {PosX, PosY};
GWMConfig GWM = {
                200.0f,
                100.0f,
                "a quick brown fox jumps\nover the lazy dog",
                PosX + 1.0f,
                PosY + 78.0f
    }; 
```

then to display your GWM Window you insert `MakeWindow(GWMConfig *GWM, WindowPosition *WP)` command and see the window being created:
```c
void display(){
    // Code
    MakeWindow(&GWM, &WP);
    // Rest of the Code
}
```

