#pragma once

#include "FireMaya.h"

namespace FireMaya
{
	class ToonMaterial : public ShaderNode
	{
	public:
		static  void *  creator();
		static  MStatus initialize();
		static MTypeId FRTypeID() { return FireMaya::TypeId::FireRenderToonMaterial; }

		virtual MStatus compute(const MPlug&, MDataBlock&) override;
		virtual frw::Shader GetShader(Scope& scope) override;

	private:

		/*struct NormalMapParams
		{
			static const unsigned int MATERIAL_INVALID_PARAM = 0xFFFF;

			Scope& scope;
			MFnDependencyNode& shaderNode;
			MObject attrUseCommonNormalMap;
			MObject mapPlug;
			unsigned int param;
			frw::Shader& material;

			NormalMapParams(Scope& _scope, frw::Shader& _material, MFnDependencyNode& _shaderNode);

			bool IsValid(void) const;
		};*/

		//void ApplyNormalMap(NormalMapParams& params);
		//bool IsNormalOrBumpMap(const MObject& attrNormal, NormalMapParams& params) const;
	};
}


