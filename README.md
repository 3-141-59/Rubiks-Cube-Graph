# Rubiks-Cube-Algorithm

```bash
src/
└─ RCA.cpp #src file automatically compiled by launch.ps1
   cmdwindow/
      ├─ cmdwindow.cpp #Also automatically compiled
      └─ launch.ps1 #launch.ps1 opens two windows, the Command Window and the main file (RCA.cpp)

$ ./launch.ps1
```
Below contains the flow diagram/information around the workings of the CLIDataBridge:
```
---------------------------------------
datatype  ┃  receive-speed    ┃  time
---------------------------------------
int=      ┃   fast    ------> ┃  //TODO
string=   ┃   fast    ------> ┃  //TODO
bool=     ┃   quite fast ---> ┃  //TODO

```
![CLIDataBridge](https://user-images.githubusercontent.com/129062223/229358121-70e26ae1-381b-4862-a0f3-cf36593f5503.png)

Below contains the primary class methods and the rough concepts behind them (POORLY DESCRIBED ON PURPOSE):

![Screenshot 2023-03-28 145424](https://user-images.githubusercontent.com/129062223/228260886-eff21a2a-0f1b-48e1-a35f-4252da6acc4c.png)

## Commands and descriptions
```cpp
exit: "exit" //exits the program
print: "print", "p" //prints the graph
list_modes: "list_modes", "lm" //lists the modes avalible and there status
create_overlap: "create_overlap", "co" //Creates an overlap for the graph, TODO: A method to choose order of overlaps
list_overlapdata: "list_overlapdata", "lod" //Lists the overlapping data (which order number it is, TODO: the option to see an overlap by itself regardless of order)
remove_graphoverlap: "remove_graphoverlap", "rgo" //Removes an overlap, take care when using this command, removed via key in the map
```
## Command Window

The command window provides an easy way to write commands without having to zoom in
to see outputs which will be tiny because the graph will probably be massive in comparison.

