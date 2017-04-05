/*
 * arhco.h
 *
 * Created on April 4, 2017
 *      Author: Ryan Owens
 */
#ifndef INCLUDE_WALLABY_ARUCO_HPP_
#define INCLUDE_WALLABY_ARUCO_HPP_

#include <algorithm>
#include <fstream>
#include <iostream>
#include <opencv2/aruco.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <string>

#include "wallaby/camera.hpp"

class Aruco {
public:
  Aruco(int dicionaryId);
  std::vector<double> getPose(int arucoId);
  std::vector<int> arucoMarkersInView();
  bool arucoMarkerInView(int arucoId);
  bool setCameraCalibration(std::string filename);

private:
  cv::Mat getFrame();
  float arucoSquareSize = 0.025f;
  cv::Mat cameraMatrix, distortionCoefficients;
  int dictionaryId;
  bool vectorContains(std::vector<int> vec, int val);
  std::string calibrationFile =
      "calibration.txt";                 // TODO need to get the proper path
  std::string customDictionaryFile = ""; // TODO need to get the proper path
  cv::Ptr<cv::aruco::Dictionary> dictionary;
  cv::Ptr<cv::aruco::DetectorParameters> detectorParams;
  bool getCustomDictionary();
  bool readCameraCalibration(std::string filename);
};
#endif
