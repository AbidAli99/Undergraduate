#ifndef _GAZEBO_ARDUCOPTERIRLOCK_PLUGIN_HH_
#define _GAZEBO_ARDUCOPTERIRLOCK_PLUGIN_HH_

#include <string>
#include <memory>

#include "gazebo/common/Plugin.hh"
#include "gazebo/util/system.hh"

namespace gazebo
{
  // Forward declare private class.
  class ArduCopterIRLockPluginPrivate;

  /// \brief A camera sensor plugin for fiducial detection
  class GAZEBO_VISIBLE ArduCopterIRLockPlugin : public SensorPlugin
  {
    /// \brief Constructor
    public: ArduCopterIRLockPlugin();

    /// \brief Destructor
    public: virtual ~ArduCopterIRLockPlugin();

    // Documentation Inherited.
    public: void Load(sensors::SensorPtr _sensor, sdf::ElementPtr _sdf);

    /// \brief Callback when a new camera frame is available
    /// \param[in] _image image data
    /// \param[in] _width image width
    /// \param[in] _height image height
    /// \param[in] _depth image depth
    /// \param[in] _format image format
    public: virtual void OnNewFrame(const unsigned char *_image,
        unsigned int _width, unsigned int _height, unsigned int _depth,
        const std::string &_format);

    /// \brief Publish the result
    /// \param[in] _name Name of fiducial
    /// \param[in] _x x position in image
    /// \param[in] _y y position in image
    public: virtual void Publish(const std::string &_fiducial, unsigned int _x,
        unsigned int _y);

    /// \internal
    /// \brief Pointer to private data.
    private: std::unique_ptr<ArduCopterIRLockPluginPrivate> dataPtr;
  };
}
#endif
