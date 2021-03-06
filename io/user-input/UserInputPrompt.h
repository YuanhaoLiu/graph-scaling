//
// Created by Ahmed on 25-1-18.
//

#ifndef GRAPH_SCALING_TOOL_USERINPUTPROMPT_H
#define GRAPH_SCALING_TOOL_USERINPUTPROMPT_H


#include "UserInput.h"
#include "../../scaling/scale-up/bridge/RandomBridge.h"

// TODO: Redundant class, get rid of it.
class UserInputPrompt : public UserInput {
public:

    UserInputPrompt();

    std::string getInputGraphPath();

    int getScalingType();

    std::string getOutputGraphPath();

    Bridge *getBridge();

    bool addDirectedBridges();

    long long getNumberOfInterconnections();

    Topology *getTopology();

    float getSamplingFraction();

    float getScalingFactor();

    Sampling* getSamplingAlgorithm(Graph*);
};


#endif //GRAPH_SCALING_TOOL_USERINPUTPROMPT_H
