#ifndef ITEXTSERIALIZABLE_H_
#define ITEXTSERIALIZABLE_H_

#include <string>

#include <boost/serialization/export.hpp>
#include <boost/serialization/base_object.hpp>
#include "Serialization.hpp"
#include "std/Vector.hpp"

#include "serialize/glm/Vec2.hpp"
#include "serialize/glm/Vec3.hpp"
#include "serialize/glm/Vec4.hpp"
#include "serialize/glm/Mat4.hpp"
#include "serialize/glm/Quat.hpp"

#include "TextOutArchive.hpp"
#include "TextInArchive.hpp"

namespace ice_script
{
namespace serialization
{

/**
 * 
 */
class ITextSerializable
{
public:
	virtual ~ITextSerializable() = default;

	/**
	 * Serialize the object to the provided filename.
	 * 
	 * **Not Thread Safe**: This method is *not* safe to call in a multi-threaded environment.  When you are calling this
	 * method, no other threads should be accessing this object.
	 */
	virtual void serialize(const std::string& filename) = 0;
	
	/**
	 * Serialize the object to the provided archive.
	 * 
	 * **Not Thread Safe**: This method is *not* safe to call in a multi-threaded environment.  When you are calling this
	 * method, no other threads should be accessing this object.
	 */
	virtual void serialize(TextOutArchive& outArchive) = 0;
	
	/**
	 * Deserializes the object from the provided filename.
	 * 
	 * **Not Thread Safe**: This method is *not* safe to call in a multi-threaded environment.  When you are calling this
	 * method, no other threads should be accessing this object.
	 */
	virtual void deserialize(const std::string& filename) = 0;
	
	/**
	 * Deserializes the object from the provided archive.
	 * 
	 * **Not Thread Safe**: This method is *not* safe to call in a multi-threaded environment.  When you are calling this
	 * method, no other threads should be accessing this object.
	 */
	virtual void deserialize(TextInArchive& inArchive) = 0;
};

}
}

#endif /* ITEXTSERIALIZABLE_H_ */
