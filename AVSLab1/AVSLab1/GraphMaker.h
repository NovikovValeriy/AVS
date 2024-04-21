#pragma once
#include <cstdlib>
#include <vector>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;


template <typename T>
class GraphMaker
{
private:
	
	void makeJson();
	void runPyScript(std::string);

public:
	std::vector<T> xPoints;
	std::vector<T> yPoints;

	GraphMaker()
	{
		xPoints = std::vector<T>();
		yPoints = std::vector<T>();
	}

	void ClearPoints();

	void PushPoint(std::pair<T, T>);
	
	void PrintGraph(std::string header);

};

template <typename T>
void GraphMaker<T>::makeJson()
{
	json jsonData = std::pair<std::vector<T>, std::vector<T>>(xPoints, yPoints);

	std::ofstream outputFile("data.json");
	if (outputFile.is_open()) {
		outputFile << jsonData;
		outputFile.close();
	}
	else {
		std::cout << "Unable to open file for writing." << std::endl;
	}
}

template <typename T>
void GraphMaker<T>::runPyScript(std::string header)
{
	system(("python printer.py " + header).c_str());
}

template <typename T>
void GraphMaker<T>::ClearPoints()
{
	xPoints.clear();
	yPoints.clear();
}

template <typename T>
void GraphMaker<T>::PushPoint(std::pair<T, T> point)
{
	xPoints.push_back(point.first);
	yPoints.push_back(point.second);
}


template <typename T>
void GraphMaker<T>::PrintGraph(std::string header)
{
	makeJson();
	runPyScript(header);
}

