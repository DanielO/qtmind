import qbs

CppApplication{
	name: "QtMind"
	files:[
		"src/main.cpp",
		"src/mainwindow.cpp",
		"src/peg.cpp",
		"src/button.cpp",
		"src/pegbox.cpp",
		"src/emptybox.cpp",
		"src/message.cpp",
		"src/pinbox.cpp",
		"src/pin.cpp",
		"src/preferences.cpp",
		"src/solver.cpp",
		"src/game.cpp",
		"src/gamerules.cpp",
		"src/indicator.cpp",
		"src/guesselement.cpp",
		"src/boardaid.cpp",
		"src/boardsounds.cpp",
		"src/boardfont.cpp",
		"src/mainwindow.h",
		"src/peg.h",
		"src/constants.h",
		"src/button.h",
		"src/pegbox.h",
		"src/emptybox.h",
		"src/message.h",
		"src/pinbox.h",
		"src/pin.h",
		"src/preferences.h",
		"src/solver.h",
		"src/game.h",
		"src/appinfo.h",
		"src/gamerules.h",
		"src/indicator.h",
		"src/guesselement.h",
		"src/boardaid.h",
		"src/boardsounds.h",
		"src/boardfont.h",
		"src/preferences.ui",
		"src/mainwindow.ui",
		"resource.qrc"
	]
	Depends{
		name: "Qt";
		property var submodules: {
			var result = ["core", "gui"];
			if (qbs.profile.contains("qt5")){
				result.push("widgets")
				result.push("multimedia")
			}
			return result
		}
	}
	
	        cpp.cxxFlags: ["-std=c++0x"]
   }
