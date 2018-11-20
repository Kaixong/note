/* Auto-generated by genmsg_cpp for file /home/asd/MyRosPack/amtec/srv/TargetVelocity.srv */
#ifndef AMTEC_SERVICE_TARGETVELOCITY_H
#define AMTEC_SERVICE_TARGETVELOCITY_H
#include <string>
#include <vector>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/message.h"
#include "ros/time.h"

#include "ros/service_traits.h"




namespace amtec
{
template <class ContainerAllocator>
struct TargetVelocityRequest_ : public ros::Message
{
  typedef TargetVelocityRequest_<ContainerAllocator> Type;

  TargetVelocityRequest_()
  : velocity_pan(0.0)
  , velocity_tilt(0.0)
  {
  }

  TargetVelocityRequest_(const ContainerAllocator& _alloc)
  : velocity_pan(0.0)
  , velocity_tilt(0.0)
  {
  }

  typedef double _velocity_pan_type;
  double velocity_pan;

  typedef double _velocity_tilt_type;
  double velocity_tilt;


private:
  static const char* __s_getDataType_() { return "amtec/TargetVelocityRequest"; }
public:
  ROSCPP_DEPRECATED static const std::string __s_getDataType() { return __s_getDataType_(); }

  ROSCPP_DEPRECATED const std::string __getDataType() const { return __s_getDataType_(); }

private:
  static const char* __s_getMD5Sum_() { return "2adb301f21428b03215ce423fc357684"; }
public:
  ROSCPP_DEPRECATED static const std::string __s_getMD5Sum() { return __s_getMD5Sum_(); }

  ROSCPP_DEPRECATED const std::string __getMD5Sum() const { return __s_getMD5Sum_(); }

private:
  static const char* __s_getServerMD5Sum_() { return "2adb301f21428b03215ce423fc357684"; }
public:
  ROSCPP_DEPRECATED static const std::string __s_getServerMD5Sum() { return __s_getServerMD5Sum_(); }

  ROSCPP_DEPRECATED const std::string __getServerMD5Sum() const { return __s_getServerMD5Sum_(); }

private:
  static const char* __s_getMessageDefinition_() { return "float64 velocity_pan\n\
float64 velocity_tilt\n\
\n\
"; }
public:
  ROSCPP_DEPRECATED static const std::string __s_getMessageDefinition() { return __s_getMessageDefinition_(); }

  ROSCPP_DEPRECATED const std::string __getMessageDefinition() const { return __s_getMessageDefinition_(); }

  ROSCPP_DEPRECATED virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
  {
    ros::serialization::OStream stream(write_ptr, 1000000000);
    ros::serialization::serialize(stream, velocity_pan);
    ros::serialization::serialize(stream, velocity_tilt);
    return stream.getData();
  }

  ROSCPP_DEPRECATED virtual uint8_t *deserialize(uint8_t *read_ptr)
  {
    ros::serialization::IStream stream(read_ptr, 1000000000);
    ros::serialization::deserialize(stream, velocity_pan);
    ros::serialization::deserialize(stream, velocity_tilt);
    return stream.getData();
  }

  ROSCPP_DEPRECATED virtual uint32_t serializationLength() const
  {
    uint32_t size = 0;
    size += ros::serialization::serializationLength(velocity_pan);
    size += ros::serialization::serializationLength(velocity_tilt);
    return size;
  }

  typedef boost::shared_ptr< ::amtec::TargetVelocityRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::amtec::TargetVelocityRequest_<ContainerAllocator>  const> ConstPtr;
}; // struct TargetVelocityRequest
typedef  ::amtec::TargetVelocityRequest_<std::allocator<void> > TargetVelocityRequest;

typedef boost::shared_ptr< ::amtec::TargetVelocityRequest> TargetVelocityRequestPtr;
typedef boost::shared_ptr< ::amtec::TargetVelocityRequest const> TargetVelocityRequestConstPtr;


template <class ContainerAllocator>
struct TargetVelocityResponse_ : public ros::Message
{
  typedef TargetVelocityResponse_<ContainerAllocator> Type;

  TargetVelocityResponse_()
  {
  }

  TargetVelocityResponse_(const ContainerAllocator& _alloc)
  {
  }


private:
  static const char* __s_getDataType_() { return "amtec/TargetVelocityResponse"; }
public:
  ROSCPP_DEPRECATED static const std::string __s_getDataType() { return __s_getDataType_(); }

  ROSCPP_DEPRECATED const std::string __getDataType() const { return __s_getDataType_(); }

private:
  static const char* __s_getMD5Sum_() { return "d41d8cd98f00b204e9800998ecf8427e"; }
public:
  ROSCPP_DEPRECATED static const std::string __s_getMD5Sum() { return __s_getMD5Sum_(); }

  ROSCPP_DEPRECATED const std::string __getMD5Sum() const { return __s_getMD5Sum_(); }

private:
  static const char* __s_getServerMD5Sum_() { return "2adb301f21428b03215ce423fc357684"; }
public:
  ROSCPP_DEPRECATED static const std::string __s_getServerMD5Sum() { return __s_getServerMD5Sum_(); }

  ROSCPP_DEPRECATED const std::string __getServerMD5Sum() const { return __s_getServerMD5Sum_(); }

private:
  static const char* __s_getMessageDefinition_() { return "\n\
"; }
public:
  ROSCPP_DEPRECATED static const std::string __s_getMessageDefinition() { return __s_getMessageDefinition_(); }

  ROSCPP_DEPRECATED const std::string __getMessageDefinition() const { return __s_getMessageDefinition_(); }

  ROSCPP_DEPRECATED virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
  {
    ros::serialization::OStream stream(write_ptr, 1000000000);
    return stream.getData();
  }

  ROSCPP_DEPRECATED virtual uint8_t *deserialize(uint8_t *read_ptr)
  {
    ros::serialization::IStream stream(read_ptr, 1000000000);
    return stream.getData();
  }

  ROSCPP_DEPRECATED virtual uint32_t serializationLength() const
  {
    uint32_t size = 0;
    return size;
  }

  typedef boost::shared_ptr< ::amtec::TargetVelocityResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::amtec::TargetVelocityResponse_<ContainerAllocator>  const> ConstPtr;
}; // struct TargetVelocityResponse
typedef  ::amtec::TargetVelocityResponse_<std::allocator<void> > TargetVelocityResponse;

typedef boost::shared_ptr< ::amtec::TargetVelocityResponse> TargetVelocityResponsePtr;
typedef boost::shared_ptr< ::amtec::TargetVelocityResponse const> TargetVelocityResponseConstPtr;

struct TargetVelocity
{

typedef TargetVelocityRequest Request;
typedef TargetVelocityResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;
}; // struct TargetVelocity
} // namespace amtec

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator>
struct MD5Sum< ::amtec::TargetVelocityRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "2adb301f21428b03215ce423fc357684";
  }

  static const char* value(const  ::amtec::TargetVelocityRequest_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x2adb301f21428b03ULL;
  static const uint64_t static_value2 = 0x215ce423fc357684ULL;
};

template<class ContainerAllocator>
struct DataType< ::amtec::TargetVelocityRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "amtec/TargetVelocityRequest";
  }

  static const char* value(const  ::amtec::TargetVelocityRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::amtec::TargetVelocityRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "float64 velocity_pan\n\
float64 velocity_tilt\n\
\n\
";
  }

  static const char* value(const  ::amtec::TargetVelocityRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::amtec::TargetVelocityRequest_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros


namespace ros
{
namespace message_traits
{
template<class ContainerAllocator>
struct MD5Sum< ::amtec::TargetVelocityResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const  ::amtec::TargetVelocityResponse_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::amtec::TargetVelocityResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "amtec/TargetVelocityResponse";
  }

  static const char* value(const  ::amtec::TargetVelocityResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::amtec::TargetVelocityResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "\n\
";
  }

  static const char* value(const  ::amtec::TargetVelocityResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::amtec::TargetVelocityResponse_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::amtec::TargetVelocityRequest_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.velocity_pan);
    stream.next(m.velocity_tilt);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct TargetVelocityRequest_
} // namespace serialization
} // namespace ros


namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::amtec::TargetVelocityResponse_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct TargetVelocityResponse_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace service_traits
{
template<>
struct MD5Sum<amtec::TargetVelocity> {
  static const char* value() 
  {
    return "2adb301f21428b03215ce423fc357684";
  }

  static const char* value(const amtec::TargetVelocity&) { return value(); } 
};

template<>
struct DataType<amtec::TargetVelocity> {
  static const char* value() 
  {
    return "amtec/TargetVelocity";
  }

  static const char* value(const amtec::TargetVelocity&) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<amtec::TargetVelocityRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "2adb301f21428b03215ce423fc357684";
  }

  static const char* value(const amtec::TargetVelocityRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<amtec::TargetVelocityRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "amtec/TargetVelocity";
  }

  static const char* value(const amtec::TargetVelocityRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<amtec::TargetVelocityResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "2adb301f21428b03215ce423fc357684";
  }

  static const char* value(const amtec::TargetVelocityResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<amtec::TargetVelocityResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "amtec/TargetVelocity";
  }

  static const char* value(const amtec::TargetVelocityResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace service_traits
} // namespace ros

#endif // AMTEC_SERVICE_TARGETVELOCITY_H
