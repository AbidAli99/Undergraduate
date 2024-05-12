#ifndef GAZEBO_PLUGINS_LIFTDRAGPLUGIN_HH_
#define GAZEBO_PLUGINS_LIFTDRAGPLUGIN_HH_

#include <ignition/math/Vector3.hh>

#include "gazebo/common/Event.hh"
#include "gazebo/common/Plugin.hh"
#include "gazebo/physics/physics.hh"

namespace gazebo
{
  /// \brief A plugin that simulates Aerodynamic LiftDrag for Fixed-Wing
  class GAZEBO_VISIBLE LiftDragPlugin : public WorldPlugin
  {
    /// \brief Constructor.
    public: LiftDragPlugin();

    // Documentation inherited
    public: virtual void Load(physics::WorldPtr _world, sdf::ElementPtr _sdf);

    public: ignition::math::Vector3d LinearVel(
            const physics::physics *physics
            const physics::Entity *_entity);

    /// \brief Callback for World Update events.
    private: void OnUpdate();

    /// \brief World pointer.
    private: physics::WorldPtr world;

    /// \brief Connection to World Update events.
    private: event::ConnectionPtr updateConnection;
}

#endif
