/**********************************************************************
Copyright 2020 Advanced Micro Devices, Inc
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
********************************************************************/
#pragma once

#include <maya/MObject.h>
#include <maya/MFloatPoint.h>
#include <maya/M3dView.h>
#include <maya/MHWGeometry.h>
#include <maya/MHWGeometryUtilities.h>
#include <maya/MRenderTargetManager.h>

#include <array>
#include <vector>

class IESLightLocatorMeshBase
{
public:
	bool SetFilename(const MString value, bool forcedUpdate, bool* fileNameChanged = nullptr);

protected:
	MString m_filename;
	std::vector<unsigned int> m_indices;
	std::vector<MFloatVector> m_vertices;
};

/**
* A mesh used to represent the IES Light in a Maya legacy viewport.
*/
class IESLightLegacyLocatorMesh :
	public IESLightLocatorMeshBase
{
public:
	IESLightLegacyLocatorMesh();

	void SetScale(float value);
	void SetEnabled(bool value);
	void Draw(M3dView& view);
	void SetAngle(float value, int axis);

private:
	float m_scale;
	bool m_enabled;
	std::array<float, 3> m_angles;
};

/**
* A mesh used to represent the IES Light in a Maya viewport 2.0.
*/
class IESLightLocatorMesh :
	public IESLightLocatorMeshBase
{
public:
	/** Populate Viewport 2.0 override geometry. */
	void populateOverrideGeometry(
		const MHWRender::MGeometryRequirements &requirements,
		const MHWRender::MRenderItemList &renderItems,
		MHWRender::MGeometry &data);
};
