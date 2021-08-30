/*
   Copyright 2018 Simon Vogl <svogl@voxel.at>
                  Angel Merino-Sastre <amerino@voxel.at>

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#pragma once

#include <toffy/filter.hpp>

#if OCV_VERSION_MAJOR >= 3
#  include <opencv2/core.hpp>
#else
#  include <opencv2/core/core.hpp>
#endif

/**
 * @brief offset performs multiplicative compensation
 *
 * \section ex1 XML Configuration [TODO]
 * <h4>Inputs</h4>
 * <ul>
 * <li> img - the input image to convert 
 * </ul
 * <h4>Ouputs</h4>
 * <ul>
 * <li> img - the output image (depth per-pixel adjusted by img(*mulValue + sumvalue) 
 * </ul
 * <h4>Options</h4>
 * <ul>
 * <li> sumValue - (float) min value for the colormap 
 * <li> mulValue - (float) max value for the colormap
 * <li> colormap - one of jet / hot/ hsv / rainbow (defaults to jet)
 * <li> scale - scale factor 
 * </ul>
 *
 */
namespace toffy {
namespace filters {

class OffSet : public Filter {

    std::vector<cv::Rect> _rois;
    float _sumValue, _mulValue;
    std::string _in_img, _out_img;
    static std::size_t _filter_counter;
public:
    OffSet();
    virtual ~OffSet() {}
    static const std::string id_name;

    void addRoi(cv::Rect newRoi);

    //virtual int loadConfig(const boost::property_tree::ptree& pt);
    virtual boost::property_tree::ptree getConfig() const;
    virtual void updateConfig(const boost::property_tree::ptree &pt);


    virtual bool filter(const Frame& in, Frame& out) const;

};

}
}
