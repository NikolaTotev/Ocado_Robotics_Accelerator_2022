#ifndef ROBO_CLEANER_GUI_SOLUTIONVALIDATORCONFIG_H_
#define ROBO_CLEANER_GUI_SOLUTIONVALIDATORCONFIG_H_

//System headers

//Other libraries headers

//Own components headers
#include "robo_cleaner_gui/defines/RoboCleanerGuiDefines.h"

//Forward declarations

struct SolutionValidatorConfig {
  int32_t targetMapTilesCount = 0;
  FieldPos playerStartLocation;
};

#endif /* ROBO_CLEANER_GUI_SOLUTIONVALIDATORCONFIG_H_ */
