"""autogenerated by genmsg_py from SetPositionVelocityRequest.msg. Do not edit."""
import roslib.message
import struct


class SetPositionVelocityRequest(roslib.message.Message):
  _md5sum = "1faf4b4c83e1e50040afc67afdd423b0"
  _type = "amtec/SetPositionVelocityRequest"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """float64 position_pan
float64 position_tilt
float64 velocity_pan
float64 velocity_tilt

"""
  __slots__ = ['position_pan','position_tilt','velocity_pan','velocity_tilt']
  _slot_types = ['float64','float64','float64','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.
    
    The available fields are:
       position_pan,position_tilt,velocity_pan,velocity_tilt
    
    @param args: complete set of field values, in .msg order
    @param kwds: use keyword arguments corresponding to message field names
    to set specific fields. 
    """
    if args or kwds:
      super(SetPositionVelocityRequest, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.position_pan is None:
        self.position_pan = 0.
      if self.position_tilt is None:
        self.position_tilt = 0.
      if self.velocity_pan is None:
        self.velocity_pan = 0.
      if self.velocity_tilt is None:
        self.velocity_tilt = 0.
    else:
      self.position_pan = 0.
      self.position_tilt = 0.
      self.velocity_pan = 0.
      self.velocity_tilt = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    @param buff: buffer
    @type  buff: StringIO
    """
    try:
      _x = self
      buff.write(_struct_4d.pack(_x.position_pan, _x.position_tilt, _x.velocity_pan, _x.velocity_tilt))
    except struct.error, se: self._check_types(se)
    except TypeError, te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    @param str: byte array of serialized message
    @type  str: str
    """
    try:
      end = 0
      _x = self
      start = end
      end += 32
      (_x.position_pan, _x.position_tilt, _x.velocity_pan, _x.velocity_tilt,) = _struct_4d.unpack(str[start:end])
      return self
    except struct.error, e:
      raise roslib.message.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    @param buff: buffer
    @type  buff: StringIO
    @param numpy: numpy python module
    @type  numpy module
    """
    try:
      _x = self
      buff.write(_struct_4d.pack(_x.position_pan, _x.position_tilt, _x.velocity_pan, _x.velocity_tilt))
    except struct.error, se: self._check_types(se)
    except TypeError, te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    @param str: byte array of serialized message
    @type  str: str
    @param numpy: numpy python module
    @type  numpy: module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 32
      (_x.position_pan, _x.position_tilt, _x.velocity_pan, _x.velocity_tilt,) = _struct_4d.unpack(str[start:end])
      return self
    except struct.error, e:
      raise roslib.message.DeserializationError(e) #most likely buffer underfill

_struct_I = roslib.message.struct_I
_struct_4d = struct.Struct("<4d")
"""autogenerated by genmsg_py from SetPositionVelocityResponse.msg. Do not edit."""
import roslib.message
import struct


class SetPositionVelocityResponse(roslib.message.Message):
  _md5sum = "d41d8cd98f00b204e9800998ecf8427e"
  _type = "amtec/SetPositionVelocityResponse"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """
"""
  __slots__ = []
  _slot_types = []

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.
    
    The available fields are:
       
    
    @param args: complete set of field values, in .msg order
    @param kwds: use keyword arguments corresponding to message field names
    to set specific fields. 
    """
    if args or kwds:
      super(SetPositionVelocityResponse, self).__init__(*args, **kwds)

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    @param buff: buffer
    @type  buff: StringIO
    """
    try:
      pass
    except struct.error, se: self._check_types(se)
    except TypeError, te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    @param str: byte array of serialized message
    @type  str: str
    """
    try:
      end = 0
      return self
    except struct.error, e:
      raise roslib.message.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    @param buff: buffer
    @type  buff: StringIO
    @param numpy: numpy python module
    @type  numpy module
    """
    try:
      pass
    except struct.error, se: self._check_types(se)
    except TypeError, te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    @param str: byte array of serialized message
    @type  str: str
    @param numpy: numpy python module
    @type  numpy: module
    """
    try:
      end = 0
      return self
    except struct.error, e:
      raise roslib.message.DeserializationError(e) #most likely buffer underfill

_struct_I = roslib.message.struct_I
class SetPositionVelocity(roslib.message.ServiceDefinition):
  _type          = 'amtec/SetPositionVelocity'
  _md5sum = '1faf4b4c83e1e50040afc67afdd423b0'
  _request_class  = SetPositionVelocityRequest
  _response_class = SetPositionVelocityResponse
