/*//////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this
//  license. If you do not agree to this license, do not download, install,
//  copy or use the software.
//
// This file originates from the openFABMAP project:
// [http://code.google.com/p/openfabmap/] -or-
// [https://github.com/arrenglover/openfabmap]
//
// For published work which uses all or part of OpenFABMAP, please cite:
// [http://ieeexplore.ieee.org/xpl/articleDetails.jsp?arnumber=6224843]
//
// Original Algorithm by Mark Cummins and Paul Newman:
// [http://ijr.sagepub.com/content/27/6/647.short]
// [http://ieeexplore.ieee.org/xpl/articleDetails.jsp?arnumber=5613942]
// [http://ijr.sagepub.com/content/30/9/1100.abstract]
//
//                           License Agreement
//
// Copyright (C) 2012 Arren Glover [aj.glover@qut.edu.au] and
//                    Will Maddern [w.maddern@qut.edu.au], all rights reserved.
//
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//  * Redistribution's of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
//  * Redistribution's in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
//  * The name of the copyright holders may not be used to endorse or promote
//    products derived from this software without specific prior written
///   permission.
//
// This software is provided by the copyright holders and contributors "as is"
// and any express or implied warranties, including, but not limited to, the
// implied warranties of merchantability and fitness for a particular purpose
// are disclaimed. In no event shall the Intel Corporation or contributors be
// liable for any direct, indirect, incidental, special, exemplary, or
// consequential damages (including, but not limited to, procurement of
// substitute goods or services; loss of use, data, or profits; or business
// interruption) however caused and on any theory of liability, whether in
// contract, strict liability,or tort (including negligence or otherwise)
// arising in any way out of the use of this software, even if advised of the
// possibility of such damage.
/////////////////////////////////////////////////////////////////////////////*/

//#include <openfabmap.hpp>
//#include <opencv2/opencv.hpp>
//#include <opencv2/core/version.hpp>

#include <iostream>
#include "openfabmap_u.h"

#if CV_MAJOR_VERSION == 2 and CV_MINOR_VERSION == 3

#elif CV_MAJOR_VERSION == 2 and CV_MINOR_VERSION == 4
#if USENONFREE
#include <opencv2/nonfree/nonfree.hpp>
#endif
#elif CV_MAJOR_VERSION >= 3
#ifdef USENONFREE
#include <opencv2/xfeatures2d.hpp>
#endif

#if CV_MAJOR_VERSION >= 4
#define CV_CAP_PROP_POS_FRAMES cv::CAP_PROP_POS_FRAMES
#define CV_CAP_PROP_FRAME_COUNT cv::CAP_PROP_FRAME_COUNT
#define CV_AA cv::LINE_AA
#endif
#endif

#include <fstream>
#include <iostream>

/*
int help(void);
int showFeatures(std::string trainPath,
                 cv::Ptr<cv::FeatureDetector> &detector);
int generateVocabTrainData(std::string trainPath,
                           std::string vocabTrainDataPath,
                           cv::Ptr<cv::FeatureDetector> &detector,
                           cv::Ptr<cv::DescriptorExtractor> &extractor);
int trainVocabulary(std::string vocabPath,
                    std::string vocabTrainDataPath,
                    double clusterRadius);

int generateBOWImageDescs(std::string dataPath,
                          std::string bowImageDescPath,
                          std::string vocabPath,
                          cv::Ptr<cv::FeatureDetector> &detector,
                          cv::Ptr<cv::DescriptorExtractor> &extractor,
                          int minWords);

int trainChowLiuTree(std::string chowliutreePath,
                     std::string fabmapTrainDataPath,
                     double lowerInformationBound);

int openFABMAP(std::string testPath,
               of2::FabMap *openFABMAP,
               std::string vocabPath,
               std::string resultsPath,
               bool addNewOnly);

of2::FabMap *generateFABMAPInstance(cv::FileStorage &settings);
cv::Ptr<cv::FeatureDetector> generateDetector(cv::FileStorage &fs);
cv::Ptr<cv::DescriptorExtractor> generateExtractor(cv::FileStorage &fs);

void drawRichKeypoints(const cv::Mat& src, std::vector<cv::KeyPoint>& kpts,
                       cv::Mat& dst);
void filterKeypoints(std::vector<cv::KeyPoint>& kpts, int maxSize = 0,
                     int maxFeatures = 0);
void sortKeypoints(std::vector<cv::KeyPoint>& keypoints);
*/

/*
The openFabMapcli accepts a YML settings file, an example of which is provided.
Modify options in the settings file for desired operation
*/
int main(int argc, char * argv[])
{
    /* load the settings file
    std::string settfilename;
    if (argc == 1) {
        //assume settings in working directory
        settfilename = "settings.yml";
    } else if (argc == 3) {
        if(std::string(argv[1]) != "-s") {
            //incorrect option
            return -1;
        } else {
            //settings provided as argument
            settfilename = std::string(argv[2]);
        }
    } else {
        //incorrect arguments
        return -1;
    } */

    //cv::FileStorage fs; // Remove CV specific stuff to speed compilation

    uint32_t flags = OE_ENCLAVE_FLAG_DEBUG;
    oe_enclave_t* enclave = NULL;
    oe_result_t _result;
    int res;

    fprintf(stdout,"Creating enclave from host...\n");

    _result = oe_create_openfabmap_enclave("openfabmapenc.signed",
	OE_ENCLAVE_TYPE_AUTO, flags, NULL, 0, &enclave);
	
    if (_result != OE_OK) {
	fprintf(stderr, "Creation of the enclave failed (res %d)\n", _result);
    }

    // PopSGX opens setting file
    std::cerr << "PopSGX: Open settings file started\n";
    if (open_settings_file(enclave, &res) != 0){
	std::cerr << "Opening settings failed\n";
    }
    std::cerr << "PopSGX: Open settings file done\n";
    return 0;
}

// All the below functions removed to speed compilation (not used)
