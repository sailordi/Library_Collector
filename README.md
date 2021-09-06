# Library_Collector
A program that collects library files into one folder in the same folder hierarchy as the library

The program collects .h files into a folder named includes in the output folder in the same folder hierarchy as in the header folder.

The program collects .a,.dll and .lib files into a folder named lib in the output folder from the release / debug build folder or both folders.

## V1
```
Created the project
Created the class Collector
Added UI elements the WindowMain UI will need
Added slots that are needed in the WindowMain
```
## V2
```
Added libraries that will be used in the project
Created the class LibraryDataWidget
Created the class MessageHandler
Created the class NoticeAdapter
Updated the UI with menu items for saving / loading the programs data
Added function that saves the window settings
Added function that loads the window setting
Added slot that will save the programs data
Added slot that will load the programs data
Fixed issue where collection did not work
```
## V3
```
Created the class BuildData
Created the class MainInfoWidget
Created the class BuildDataWidget
Created the class TextWrapDelegate
Created the class BuildDataTreeViewAdapter
Created the class BuildDataViewWidget
Updated the UI
Updated the main window to use the new widgets
```
## V4
```
Fixed error in comments
Created the class ExcludePathsViewWidget
Added a variable and a constructor in the class Collector
Added function that checks for error when adding exclude path
Added function that checks for error when uppdating exclude path
Added new elements to the UI and renamed others
Added functions that preform the collection in diffrent ways
Added a slot that is activated when add exclude path is clicked
Added a slot that is activated when update exclude path is clicked
```
## V4_1
```
Updated the program save file suffix
Added function that connects slots to signals
Rename functions to better represent what they do
Fixed issue where some of the menu items were not connected to the slots required of them    