//
//  myLib.cpp
//  TestLib
//
//  Created by Kusyumov Nikita on 23.04.2022.
//

#include "myLib.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <limits>
#include <fstream>
#include <math.h>
//using namespace std;

namespace myLib
{
    //var globalMap: [(latitude: Double, longitude: Double, roadType: RoadType)] = []
    
    // передается файл карты который должен выглядеть следующщим образом
    // номер строки (начало с 0) latitude longitude номера строк с которыми связан
    // пример:
    // 0 3.27635 549.12344 2 3
    // 1 5.73546 63.25367 2
    // 2 5.35353 711.23432 0 1 3
    // 3 192.12332 67366.12332 0 2
    //https://prog-cpp.ru/deikstra/
    // Алгоритм дейкстры
    vector<int> optimalPath(int nodeCount, vector<vector<double>> matrix, int startPointID, int endPointID) {
        double bigNumber = numeric_limits<double>::max();
        double weightArray[nodeCount];
        bool visitedArray[nodeCount];
        int currentPointID = startPointID;
        
        // init the weighted array for big numbers, start pooint weight = 0
        for(int i = 0; i < nodeCount; i++) {
            if(i == startPointID) {
                weightArray[i] = 0;
            } else {
                weightArray[i] = bigNumber;
            }
            visitedArray[i] = false;
        }
        
        bool isMapAnalized = false;

        while(!isMapAnalized) {
            //make new weights for current point
            for(int j = 0; j < nodeCount; j++) {
                if(visitedArray[j]) {
                    
                } else if(matrix[currentPointID][j] != 0) {
                    if(weightArray[j] > weightArray[currentPointID] + matrix[currentPointID][j]) {
                        weightArray[j] = weightArray[currentPointID] + matrix[currentPointID][j];
                    }
                }
            }
            visitedArray[currentPointID] = true;
            
            vector<pair<int, double>> tempArrPairs;
            vector<double> tempArr;
            
            for(int i = 0; i < nodeCount; i++) {
                if(!visitedArray[i]) {
                    tempArrPairs.push_back(pair(i, weightArray[i]));
                    tempArr.push_back(weightArray[i]);
                }
            }
            if(tempArr.size() != 0) {
                double smallestElement = *min_element(tempArr.begin(),tempArr.end());
                for(int i = 0; i < tempArrPairs.size(); i++) {
                    if(tempArrPairs[i].second == smallestElement) {
                        currentPointID = tempArrPairs[i].first;
                    }
                }
            }
            
            // check is all points analized
            bool checkMapAnalization = true;
            for(int i = 0; i < nodeCount; i++) {
                checkMapAnalization = checkMapAnalization && visitedArray[i];
            }
            isMapAnalized = checkMapAnalization;
        }
        
        // -------------------------------------------------------------------------
        
        //find the min path
        printf("\nWeight for nodes  ----  ");
        for(int i = 0; i < nodeCount; i++) {
            printf("%.3f ", weightArray[i]);
        }
        printf("\n");
        
        currentPointID = endPointID;
        vector<int> pathArray;
        while(currentPointID != startPointID) {
            pathArray.push_back(currentPointID);
            for(int i = 0; i < nodeCount; i++) {
                if(matrix[currentPointID][i] != 0) {
                    if(weightArray[currentPointID] - matrix[currentPointID][i] == weightArray[i]) {
                        currentPointID = i;
                        break;
                    }
                }
            }
        }
        // print the result path
        pathArray.push_back(currentPointID);
        printf("Minimal path is: ");
        reverse(pathArray.begin(), pathArray.end());
        for(int i = 0; i < pathArray.size(); i++) {
            printf("%d ", pathArray[i]);
        }
        printf("\n");

        return pathArray;
    }

    int getNodeCount(string mapFileName) {
        char *str = new char [1024];
        ifstream mapFile(mapFileName);
        
        int numberOfLines = 0;
        while (!mapFile.eof()) {
            mapFile.getline(str, 1024, '\n');
            numberOfLines++;
        }
        return numberOfLines;
    }

    double getLenght(pair<double, double> firstPoint, pair<double, double> secondPoint) {
        return sqrt(pow((secondPoint.first - firstPoint.first), 2) + pow((secondPoint.second - firstPoint.second), 2));
    }
    
    vector<vector<double>> getMapMatrix(int nodeCount, vector<vector<double>> matrix, string mapFileName) {
        pair<double, double> cordsArray[nodeCount];
        ifstream mapFile(mapFileName);
        
        int id;
        double latitude;
        double longetude;
        
        int temp;
        vector<int> arrayOfConnections[nodeCount];
        
        for(int i = 0; i < nodeCount; i++) {
            mapFile >> id;
            mapFile >> latitude;
            mapFile >> longetude;
            cordsArray[i] = pair(latitude, longetude);
            
            while (!mapFile.eof()) {
                if (mapFile.peek() == '\n') {
                    break;
                }
                mapFile >> temp;
                arrayOfConnections[i].push_back(temp);
            }
        }
        
        for(int i = 0; i < nodeCount; i++) {
            for(int j = 0; j < arrayOfConnections[i].size(); j++) {
                double a = getLenght(cordsArray[i], cordsArray[arrayOfConnections[i][j]]);
                matrix[i][arrayOfConnections[i][j]] = a;
            }
        }
        
        return matrix;
    }

    vector<int> getOptimalPath(string file, int  startPointId) {
        ifstream ifs;
        ifs.open(file);
        
        vector<int> minPath;

        if(ifs.is_open()) {
            cout << "File was opened\n";
            int nodeCount = getNodeCount(file);
            
            vector<vector<double>> matrix(nodeCount, vector<double>(nodeCount, 0));
            
            matrix = getMapMatrix(nodeCount, matrix, file);
            
            for(int i = 0; i < nodeCount; i++) {
                for(int j = 0; j < nodeCount; j++) {
                    printf("%.0f ", matrix[i][j]);
                }
                printf("\n");
            }
            
            minPath = optimalPath(nodeCount, matrix, 0, 36);
            
            
        } else {
            cerr <<"Could not open: " << file << endl;
            exit(1);
        }

        ifs.close();
        return minPath;
    }
        
// -------------------------------------------------------------------------------
    string getHelloString(string name) {
        string begining = "Hello, ";
        string end = ". Glad to hear you";
        
        string greatingsString = begining + name + end;
        return greatingsString;
    }
}
