# FDF
Generate 3D map through text

## Description

This program allows the user to generate a 3D map with a simple text file and see it through 3 different views. It was written in C.

<img src="https://donsefactory.files.wordpress.com/2020/02/fdf_00.gif" width=500 height=500/>

Main features:
* Zooming in/out
* Rotate the map on X and Y axis
* Color changing depending on height
* Depth increasing/decreasing
* 3 different perspectives

<img src="https://donsefactory.files.wordpress.com/2020/02/fdf_01.gif" width=500 height=500/>

## Installation
***Only works on MacOS with provided library***<br/>
To install simply type: <br/>
`make`

OpenGL has to be installed as it is required by the MLX library.

## Usage
`./fdf [text_file]`
different maps can be tested in the maps/ folder.
