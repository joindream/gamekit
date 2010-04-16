/*
-------------------------------------------------------------------------------
    This file is part of OgreKit.
    http://gamekit.googlecode.com/

    Copyright (c) 2006-2010 Nestor Silveira.

    Contributor(s): none yet.
-------------------------------------------------------------------------------
  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
-------------------------------------------------------------------------------
*/
#ifndef _gkFindPathNode_h_
#define _gkFindPathNode_h_

#include "gkLogicNode.h"

class dtNavMesh;
class gkPhysicsDebug;

class gkFindPathNode : public gkLogicNode
{
public:

	enum
	{
		UPDATE,
		NAV_MESH,
		MAX_PATH_POLYS,
		START_POS,
		END_POS,
		POLY_PICK_EXT,
		SHOW_PATH,
		SHOW_PATH_OFFSET,
		REDO_PATH_IF_FOLLOWING,
		PATH,
		PATH_FOUND
	};

	struct PathData
	{
		typedef std::deque<gkVector3> PATH_POINTS;

		PATH_POINTS path;

		bool following;

		bool retry;

		PathData() : following(false), retry(false) {}
	};

	DECLARE_SOCKET_TYPE(UPDATE, bool);
	DECLARE_SOCKET_TYPE(NAV_MESH, dtNavMesh*);
	DECLARE_SOCKET_TYPE(MAX_PATH_POLYS, int);
	DECLARE_SOCKET_TYPE(START_POS, gkVector3);
	DECLARE_SOCKET_TYPE(END_POS, gkVector3);
	DECLARE_SOCKET_TYPE(POLY_PICK_EXT, gkVector3);
	DECLARE_SOCKET_TYPE(SHOW_PATH, bool);
	DECLARE_SOCKET_TYPE(SHOW_PATH_OFFSET, gkVector3);
	DECLARE_SOCKET_TYPE(REDO_PATH_IF_FOLLOWING, bool);
	

	DECLARE_SOCKET_TYPE(PATH, PathData*);
	DECLARE_SOCKET_TYPE(PATH_FOUND, bool);

    gkFindPathNode(gkLogicTree *parent, size_t id);

	~gkFindPathNode();

	bool evaluate(gkScalar tick);
	void update(gkScalar tick);

private:

	void findPath();
	void showPath();

private:

	gkPhysicsDebug* m_debug;
	PathData m_path;
};

#endif//_gkFindPathNode_h_
