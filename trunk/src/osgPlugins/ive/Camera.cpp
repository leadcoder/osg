/**********************************************************************
 *
 *    FILE:            Camera.cpp
 *
 *    DESCRIPTION:    Read/Write osg::Camera in binary format to disk.
 *
 *    CREATED BY:        Auto generated by iveGenerated
 *                    and later modified by Rune Schmidt Jensen.
 *
 *    HISTORY:        Created 17.3.2003
 *
 *    Copyright 2003 VR-C
 **********************************************************************/

#include "Exception.h"
#include "Camera.h"
#include "Transform.h"
#include "Image.h"

using namespace ive;

void Camera::write(DataOutputStream* out){
    // Write Camera's identification.
    out->writeInt(IVECAMERA);

    // If the osg class is inherited by any other class we should also write this to file.
    osg::Transform* transform = dynamic_cast<osg::Transform*>(this);
    if(transform){
        ((ive::Transform*)(transform))->write(out);
    }
    else
        throw Exception("Camera::write(): Could not cast this osg::Camera to an osg::Group.");


    out->writeVec4(getClearColor());
    out->writeUInt(getClearMask());

    out->writeBool(getColorMask()!=0);
    if (getColorMask()!=0)
    {
        out->writeStateAttribute(getColorMask());
    }

    out->writeBool(getViewport()!=0);
    if (getViewport()!=0)
    {
        out->writeStateAttribute(getViewport());
    }
    
    out->writeInt(getTransformOrder());

    // Write Camera's properties.
    out->writeMatrixd(getProjectionMatrix());
    out->writeMatrixd(getViewMatrix());
    
    out->writeInt(getRenderOrder());
    out->writeInt(getRenderTargetImplementation());
    out->writeInt(getRenderTargetFallback());
 
    out->writeUInt(getDrawBuffer());
    out->writeUInt(getReadBuffer());
     
    const BufferAttachmentMap& baf = getBufferAttachmentMap();
    out->writeUInt(baf.size());
    for(BufferAttachmentMap::const_iterator itr = baf.begin();
        itr != baf.end();
        ++itr)
    {
        BufferComponent buffer = itr->first;
        const Attachment& attachment = itr->second;

        out->writeInt( buffer );
        out->writeUInt( attachment._internalFormat);

        // this ain't right... what if we need to share images????
        out->writeBool(attachment._image.valid());
        if(attachment._image.valid())
            ((ive::Image*)attachment._image.get())->write(out);

        out->writeBool(attachment._texture.valid());
        if(attachment._texture.valid())
            out->writeStateAttribute(attachment._texture.get());
            
        out->writeUInt(attachment._level);
        out->writeUInt(attachment._face);
        out->writeBool(attachment._mipMapGeneration);
    }
     
}

void Camera::read(DataInputStream* in)
{
    // Read Camera's identification.
    int id = in->peekInt();
    if(id == IVECAMERA)
    {
        // Code to read Camera's properties.
        id = in->readInt();
        // If the osg class is inherited by any other class we should also read this from file.
        osg::Transform*  transform = dynamic_cast<osg::Transform*>(this);
        if(transform)
        {
            ((ive::Transform*)(transform))->read(in);
        }
        else
            throw Exception("Camera::read(): Could not cast this osg::Camera to an osg::Group.");

        setClearColor(in->readVec4());
        setClearMask(in->readUInt());

        if (in->readBool())
        {
            osg::ref_ptr<osg::StateAttribute> attribute = in->readStateAttribute();
            osg::ColorMask* cm = dynamic_cast<osg::ColorMask*>(attribute.get());
            if (cm) setColorMask(cm);
        }

        if (in->readBool())
        {
            osg::ref_ptr<osg::StateAttribute> attribute = in->readStateAttribute();
            osg::Viewport* vp = dynamic_cast<osg::Viewport*>(attribute.get());
            if (vp) setViewport(vp);
        }
    
        setTransformOrder((TransformOrder)in->readInt());

        // Read matrix
        setProjectionMatrix(in->readMatrixd());
        setViewMatrix(in->readMatrixd());

    
        setRenderOrder((RenderOrder)in->readInt());
    
        RenderTargetImplementation impl = (RenderTargetImplementation)in->readInt();
        RenderTargetImplementation fallback = (RenderTargetImplementation)in->readInt();
        setRenderTargetImplementation(impl, fallback);
 
        setDrawBuffer((GLenum)in->readUInt());
        setReadBuffer((GLenum)in->readUInt());
     
        _bufferAttachmentMap.clear();
        
        unsigned int numAttachments = in->readUInt();
        for(unsigned int i=0; i<numAttachments; ++i)
        {
            Attachment& attachment = _bufferAttachmentMap[(BufferComponent)in->readInt()];
            attachment._internalFormat = (GLenum)in->readUInt();
            
            if (in->readBool())
            {
                // this ain't right... what if we need to share images????
                attachment._image = new osg::Image;
               ((ive::Image*)attachment._image.get())->read(in);
            }

            if (in->readBool())
            {
                osg::ref_ptr<osg::StateAttribute> attribute = in->readStateAttribute();
                osg::Texture* texture = dynamic_cast<osg::Texture*>(attribute.get());
                if (texture) attachment._texture = texture;
            }

            attachment._level = in->readUInt();
            attachment._face = in->readUInt();
            attachment._mipMapGeneration = in->readBool();
        }
    }
    else{
        throw Exception("Camera::read(): Expected Camera identification");
    }
}
