#pragma once

namespace study::enums
{
	enum class eLayerType
	{
		NONE,
		BACKGROUND,
		//TREE,
		//CHARACTER,
		PLAYER,
		MAX = 16,
	};

	enum class eResourceType
	{
		TEXTURE,
		AUDIOCLIP,
		PREFAB,
		END,
	};
}