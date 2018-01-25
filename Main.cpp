#include <iostream>
#include <map>
#include "scaling/Scaling.h"
#include "io/GraphLoader.h"
#include "io/user-input/UserInput.h"
#include "io/user-input/UserInputPrompt.h"
#include "io/user-input/UserInputCMD.h"

std::string logo = "  ____                        _        ____                        \n"
        " / ___|  __ _ _ __ ___  _ __ | | ___  / ___| _ __  _ __ __ _ _   _ \n"
        " \\___ \\ / _` | '_ ` _ \\| '_ \\| |/ _ \\ \\___ \\| '_ \\| '__/ _` | | | |\n"
        "  ___) | (_| | | | | | | |_) | |  __/  ___) | |_) | | | (_| | |_| |\n"
        " |____/ \\__,_|_| |_| |_| .__/|_|\\___| |____/| .__/|_|  \\__,_|\\__, |\n"
        "                       |_|                  |_|              |___/ ";

std::string version = "v1.0";


void scaleUp(GraphLoader *graphLoader, UserInput *userInput);

void scaleDown(UserInput *userInput);

UserInput*  getUserInput(int argc, char* argv[]);

int main(int argc, char* argv[]) {
    std::cout << logo << version << std::endl;

    GraphLoader* graphLoader = new GraphLoader();
    UserInput* userInput = getUserInput(argc, argv);

    if (userInput->getScalingType()) {
        scaleUp(graphLoader, userInput);
    } else {
        scaleDown(userInput);
    }

    delete(userInput);
    delete(graphLoader);

    return 0;
}

void scaleUp(GraphLoader *graphLoader, UserInput *userInput) {
    Graph* graph = graphLoader->loadGraph(userInput->getInputGraphPath());
    Scaling* scaling = new Scaling(graph);
    ScalingUpConfig* scaleUpSamplesInfo = new ScalingUpConfig(userInput->getScalingFactor(),
                                                              userInput->getSamplingFraction(),
                                                              userInput->getTopology());
    scaling->scaleUp(scaleUpSamplesInfo, userInput->getOutputGraphPath());

    delete(scaleUpSamplesInfo);
    delete(scaling);
}

void scaleDown(UserInput *userInput) {
    std::string inputPathGraph = userInput->getInputGraphPath();
    std::string outputPathGraph = userInput->getOutputGraphPath();
    float samplingFraction = userInput->getSamplingFraction();
}

UserInput* getUserInput(int argc, char* argv[]) {
    if (argc > 1) {
        return new UserInputCMD(argc, argv);
    }

    return new UserInputPrompt();
}