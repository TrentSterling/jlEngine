#ifndef JL_IDENTIFIERTYPES_HPP
#define JL_IDENTIFIERTYPES_HPP

namespace jl
{

	// Used when storing type ID's
	typedef unsigned int TypeID;

	// Used when storying entity ID's
	typedef unsigned int EntityID;

	/*
	TypeIdGrabber

	Used to retrieve unique ID's per type
	*/
	struct TypeIdGrabber
	{
		static TypeID currentTypeId;
		template<typename TIdType> static TypeID getUniqueTypeID()
		{
			// This variable, since it's static in a template function, will
			// have the same value for same values of TIdType
			static const TypeID id = TypeIdGrabber::currentTypeId++;
			return id;
		};
	};

};

#endif