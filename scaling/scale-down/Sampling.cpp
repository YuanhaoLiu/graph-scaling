//
// Created by Ahmed on 14-11-17.
//

#include "Sampling.h"
#include "../../io/WriteSampledGraph.h"

Sampling::Sampling(Graph* graph, std::string samplingAlgorithmName) {
    this->graph = graph;

    this->samplingAlgorithmName = samplingAlgorithmName;
    std::cout << "Selected " << samplingAlgorithmName << " as sampling algorithm." << std::endl;
}

Graph* Sampling::sampleBase(float fraction) {
    if (fraction == 1.0) {
        return getFullGraphCopy();
    }

    return sample(fraction);
}

long long Sampling::getNumberOfVerticesFromFraction(float fraction) {
    return this->graph->getVertices().size() * fraction;
}

long long Sampling::getNumberOfEdgesFromFraction(float fraction) {
    return this->graph->getEdges().size() * fraction;
}

long long Sampling::getRandomIntBetweenRange(long long min, long long max) {
    std::mt19937 engine(seed());
    std::uniform_int_distribution<long long> dist(min, max);

    return dist(engine);
}

void Sampling::run(float fraction, std::string outputPath) {
    Graph* graph = sampleBase(fraction);

    WriteGraph* writeSampledGraph = new WriteSampledGraph(graph, outputPath, fraction); // TODO: Delete this later.
    writeSampledGraph->write();
}

/**
 * @return full copy of the input graph (in case the sample size is 1.0)
 */
Graph* Sampling::getFullGraphCopy() {
    std::cout << "Copying the full graph." << std::endl;
    Graph* fullCopy = new Graph(); // TODO: Delete this later.
    fullCopy->setVertices(graph->getVertices());
    fullCopy->setEdges(graph->getEdges());

    return fullCopy;
}

std::string Sampling::getSamplingAlgorithmName() {
    return samplingAlgorithmName;
}