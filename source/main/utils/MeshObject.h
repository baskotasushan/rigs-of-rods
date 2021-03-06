/*
    This source file is part of Rigs of Rods
    Copyright 2005-2012 Pierre-Michel Ricordel
    Copyright 2007-2012 Thomas Fischer
    Copyright 2013-2017 Petr Ohlidal & contributors

    For more information, see http://www.rigsofrods.org/

    Rigs of Rods is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 3, as
    published by the Free Software Foundation.

    Rigs of Rods is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Rigs of Rods. If not, see <http://www.gnu.org/licenses/>.
*/

/// @file
/// @author Thomas Fischer (thomas{AT}thomasfischer{DOT}biz)
/// @date   1st of May 2010

#pragma once

#include <Ogre.h>

#include "RoRPrerequisites.h"

class MeshObject : public Ogre::ResourceBackgroundQueue::Listener, public Ogre::Resource::Listener, public ZeroedMemoryAllocator
{
public:
    MeshObject(Ogre::String meshName, Ogre::String entityName, Ogre::SceneNode* sceneNode = 0, bool backgroundLoading = false);
    ~MeshObject();

    void setMaterialName(Ogre::String m);
    void setCastShadows(bool b);
    void setMeshEnabled(bool e);
    void setVisible(bool b);
    inline Ogre::MeshPtr    getMesh() { return mesh; };
    inline Ogre::Entity*    getEntity() { return ent; };
    inline Ogre::SceneNode* GetSceneNode() { return sceneNode; }

protected:
    Ogre::String meshName;
    Ogre::String entityName;
    Ogre::SceneNode* sceneNode;
    Ogre::Entity* ent;
    Ogre::MeshPtr mesh;
    Ogre::BackgroundProcessTicket ticket;
    bool backgroundLoading;
    bool loaded;

    Ogre::String materialName;
    bool castshadows;
    bool enabled;
    bool visible;

    void postProcess();
    void loadMesh();

    void operationCompleted(Ogre::BackgroundProcessTicket ticket, const Ogre::BackgroundProcessResult& result);
    void loadingComplete(Ogre::Resource* r);
    void preparingComplete(Ogre::Resource* r);
    void unloadingComplete(Ogre::Resource* r);
};

