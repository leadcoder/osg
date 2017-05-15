#ifndef IVE_TEXTURE_BUFFER
#define IVE_TEXTURE_BUFFER 1

#include <osg/TextureBuffer>
#include "ReadWrite.h"

namespace ive{
class TextureBuffer : public osg::TextureBuffer, public ReadWrite {
public:
	void write(DataOutputStream* out);
	void read(DataInputStream* in);
};
}

#endif
